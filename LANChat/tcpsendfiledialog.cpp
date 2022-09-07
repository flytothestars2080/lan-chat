#include "tcpsendfiledialog.h"
#include "ui_tcpsendfiledialog.h"
#include<QFileDialog>
#include<QMessageBox>
#include<QDataStream>
#include <synchapi.h>
qint64 TcpSendFileDialog::getPayloadSize() const
{
    return payloadSize;
}

void TcpSendFileDialog::setPayloadSize(const qint64 &value)
{
    payloadSize = value;
}

void TcpSendFileDialog::ClientRefuse()
{

    ui->label->setText("对端拒绝接收");
    tcpServer->close();
    ui->btn_FileOpen->setEnabled(true);
    ui->btn_send->setEnabled(false);

}

void TcpSendFileDialog::closeEvent(QCloseEvent *event)
{
    Q_UNUSED(event);
    on_btn_close_clicked();
}

void TcpSendFileDialog::InitServer()
{

    this->TotalBytes=0;
    bytesWritten=0;
    bytesToWrite=0;
    payloadSize=64*1024;//每次发送的数据 64 KB
    ui->progressBar->setValue(0);
    ui->label->setText(tr("请选择要发送的文件"));
    ui->btn_FileOpen->setEnabled(true);
    ui->btn_send->setEnabled(false);
    tcpServer->close();//关闭监听
}



TcpSendFileDialog::TcpSendFileDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TcpSendFileDialog)
{
    ui->setupUi(this);
    this->setFixedSize(350,180);
    port=6666;
    tcpServer= new QTcpServer(this);
    connect(tcpServer,SIGNAL(newConnection()),this,SLOT(SendMessage()));//绑定连接信号
    InitServer();

}

TcpSendFileDialog::~TcpSendFileDialog()
{
    delete ui;
}

void TcpSendFileDialog::SendMessage()
{
    ui->btn_send->setEnabled(false);
    //获取连接客户端socket
    clientSocket= tcpServer->nextPendingConnection();
    //连接更新进度条
    connect(clientSocket,SIGNAL(bytesWritten(qint64 )),
            this,SLOT(updataSendProgess(qint64)));
    ui->label->setText("开始发送:"+FileName);
    //获取文件名，文件大小
    LoadFile=new QFile(FilePath);
    if(!LoadFile->open(QFile::ReadOnly))//文件打开失败就返回
    {
        QMessageBox::warning(this,"send错误","文件打开失败"+LoadFile->errorString());
        return ;
    }

    TotalBytes=LoadFile->size();//数据大小
    //数据流
    QDataStream out(&outArray,QIODevice::WriteOnly);

    out.setVersion(QDataStream::Qt_5_9);

    //准备文件头结构，总大小,文件名大小,文件名
    //先预留出要发送的总大小,文件名大小
    out<<qint64(0)<<qint64(0)<<FileName;
    out.device()->seek(0);//将输入位置定向到缓冲区的开头
    TotalBytes+=outArray.size();
    out<<TotalBytes<<qint64((outArray.size()- sizeof(qint64)*2));

    //发送文件头结构
    time.start();//开启定时器
    bytesToWrite=TotalBytes -clientSocket->write(outArray);
    outArray.resize(0);
}

void TcpSendFileDialog::updataSendProgess(qint64 ByteNum)
{
    QCoreApplication::processEvents();//防止用户界面冻结

    bytesWritten+=ByteNum;//已经发送数据的大小
    if(this->bytesToWrite>0)//如果有数据要发
    {
        //文件读取到缓冲区里
        //如果剩余数据不足64kb,就发剩余数据大小
        outArray=LoadFile->read(qMin(payloadSize,bytesToWrite));
        bytesToWrite-=clientSocket->write(outArray);//更新剩余数据大小
        //清空缓冲区
        outArray.resize(0);
    }else
    {
        LoadFile->close();
    }
    //更新进度条
    ui->progressBar->setMaximum(TotalBytes);
    ui->progressBar->setValue(bytesWritten);
    //估算发送速度,发送时间
    double  usedtime=time.elapsed();
    double speed=bytesWritten/ usedtime;//单位是毫秒
    qint64 oneMB=(1024*1024);
    ui->label->setText(QString::asprintf("已发送%lldMB,发送速度%fMB/s,"
                                         "总共%lldMB,剩余%lldMB,剩余时间%fs"
                                         ,bytesWritten/oneMB,speed*1000/oneMB
                                         ,TotalBytes/oneMB,
                                         bytesToWrite/oneMB
                                         ,(bytesToWrite/oneMB)/(speed*1000/oneMB)));
    //是否已发送完
    if(bytesWritten==TotalBytes)//这里bytesWritten才是真的写入socket缓冲区的大小
    {
        ui->label->setText("文件发送完成,请取消来再次发送或者关闭对话框");
        LoadFile->close();
        clientSocket->close();

    }



}

void TcpSendFileDialog::on_btn_FileOpen_clicked()
{
    //获取文件路径
    this->FilePath=QFileDialog::getOpenFileName(this);
    if(!FilePath.isEmpty())
    {
        //获取文件名
        FileName=FilePath.right(FilePath.size()-1-FilePath.lastIndexOf('/'));
        ui->label->setText("发送的文件名:"+FileName);
        ui->label_FilePath->setText("文件路径:"+FilePath);
        ui->btn_FileOpen->setEnabled(false);
        ui->btn_send->setEnabled(true);
    }

}

void TcpSendFileDialog::on_btn_send_clicked()
{
    //开始监听
    if(!tcpServer->listen(QHostAddress::AnyIPv4,port))
    {
        //如果监听失败
        QMessageBox::warning(this,"错误","监听失败:"+LoadFile->errorString());
        close();
        return ;
    }
    ui->label->setText("等待接收");
    ui->btn_FileOpen->setEnabled(false);
    ui->btn_send->setEnabled(false);

    emit sendFileName(FileName);
}

void TcpSendFileDialog::on_btn_close_clicked()
{
    if(tcpServer->isListening())
    {
        tcpServer->close();
        if(LoadFile!=nullptr)
        {
            if(LoadFile->isOpen())
            LoadFile->close();
        }
        if(clientSocket!=nullptr)
        {
           clientSocket->abort();
        }
    }
    close();

}

void TcpSendFileDialog::on_pushButton_canel_clicked()
{
    this->InitServer();

}

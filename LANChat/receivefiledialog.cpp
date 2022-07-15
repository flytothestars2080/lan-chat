#include "receivefiledialog.h"
#include "ui_receivefiledialog.h"
#include<QMessageBox>

void receiveFileDialog::setFileName(const QString &value)
{
    fileName = value;
}

receiveFileDialog::receiveFileDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::receiveFileDialog)
{
    ui->setupUi(this);
    Init();

    connect(client,SIGNAL(readyRead()),
            this,SLOT(readMessage()));

    connect(client,SIGNAL(error(QAbstractSocket::SocketError)),
                          this,SLOT(on_error(QAbstractSocket::SocketError)));

}

receiveFileDialog::~receiveFileDialog()
{
    delete ui;
}

void receiveFileDialog::SetFilePath(QString filePath)
{

    filePath=filePath+"/"+fileName;//完整的路径
    loadFile=new QFile(filePath);

}

void receiveFileDialog::SetAddress(QHostAddress address)
{
    peeraddress=address;
}

void receiveFileDialog::StartConnect()
{

    client->abort();
    client->connectToHost(peeraddress,port);
    time.start();
}

void receiveFileDialog::closeEvent(QCloseEvent *event)
{
    Q_UNUSED(event);
    on_btn_close_clicked();
}

void receiveFileDialog::readMessage()
{
    //开始读取
    QDataStream in(client);
    in.setVersion(QDataStream::Qt_5_9);
    //读取文件头结构
    if(bytesRecevivded<=(sizeof(qint64)*2))
    {
        if(client->bytesAvailable()>=(sizeof(qint64)*2)&&fileNameSize==0)
        {
            in>>totalBytes>>fileNameSize;
            bytesRecevivded+=sizeof(qint64)*2;
        }
        if(client->bytesAvailable()>=fileNameSize&&fileNameSize!=0)
        {
            in>>fileName;
            bytesRecevivded+=fileNameSize;
            if(!loadFile->open(QFile::WriteOnly))
            {
                QMessageBox::warning(this,"recy错误","文件打开失败"+loadFile->errorString());
            }else
            {
                ui->label->setText(tr("接收文件%1.....").arg(fileName));
            }
        }
        return ;//文件头读完了

    }
    //读取文件数据,写入到文件里
    if(bytesRecevivded<totalBytes)
    {
        //读取到缓冲区里
        bytesRecevivded+=client->bytesAvailable();
        inArray=client->readAll();
        //写入文件
        loadFile->write(inArray);
        inArray.resize(0);


    }
    //更新进度条
    ui->progressBar->setMaximum(totalBytes);
    ui->progressBar->setValue(bytesRecevivded);


    //估算接收速度,接收时间
    double  usedtime=time.elapsed();
    double speed=bytesRecevivded/ usedtime;//单位是毫秒
    qint64 oneMB=(1024*1024);
    ui->label->setText(QString::asprintf("已接收%lldMB,接收速度%fMB/s,"
                                         "总共%lldMB,剩余%lldMB,估计剩余时间%fs"
                                         ,bytesRecevivded/oneMB
                                         ,speed*1000/oneMB
                                         ,totalBytes/oneMB,
                                        (totalBytes-bytesRecevivded) /oneMB
                                         ,(totalBytes-bytesRecevivded/oneMB)/(speed*1000/oneMB)));
    //接收数据完成

    if(bytesRecevivded==totalBytes)
    {
        loadFile->close();
        client->close();
        ui->label->setText(tr("接收文件%1已完成").arg(fileName));

    }

}

void receiveFileDialog::on_error(QAbstractSocket::SocketError socketError)
{

   QMessageBox::warning(this,"错误",QString::asprintf("出现错误 %d:",socketError)+
                        client->errorString());
}

void receiveFileDialog::Init()
{
    setFixedSize(350,180);

    totalBytes=0;//已接收到的总数据
    bytesRecevivded=0;//已收到的数据大小
    fileNameSize=0;//文件名的大小信息
    port=6666;
    ui->progressBar->setValue(0);
    setWindowTitle("接收文件");
    client=new QTcpSocket(this);



}

void receiveFileDialog::on_btn_canel_clicked()
{
     client->abort();
    if(loadFile->isOpen())
    {
        loadFile->close();

    }

}

void receiveFileDialog::on_btn_close_clicked()
{
    on_btn_canel_clicked();
    close();
}


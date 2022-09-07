#include "sendfiledialog.h"
#include "ui_sendfiledialog.h"
#include<QFileDialog>

int SendFileDialog::getDlgid() const
{
    return Dlgid;
}

void SendFileDialog::setDlgid(int value)
{
    Dlgid = value;
}

QString SendFileDialog::getRecyIP() const
{
    return recyIP;
}

void SendFileDialog::setRecyIP(const QString &value)
{
    recyIP = value;
}

void SendFileDialog::InitDlg()
{
    m_TotalBytes=0;
    m_bytesWritten=0;
    m_bytesToWrite=0;
    m_payloadSize=64*1024;//每次发送的数据 64 KB
    ui->progressBar->setValue(0);
    ui->label->setText(tr("请选择要发送的文件"));
    ui->btn_FileOpen->setEnabled(true);
    ui->btn_send->setEnabled(false);
}

QString SendFileDialog::getFilePath() const
{
    return FilePath;
}

void SendFileDialog::setFileName(const QString &value)
{
    FileName = value;
}

QString SendFileDialog::getFileName() const
{
    return FileName;
}

qint64 SendFileDialog::getPayloadSize() const
{
    return m_payloadSize;
}

void SendFileDialog::setPayloadSize(const qint64 &payloadSize)
{
    m_payloadSize = payloadSize;
}

SendFileDialog::SendFileDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SendFileDialog)
{
    ui->setupUi(this);

    InitDlg();
}

SendFileDialog::~SendFileDialog()
{
    delete ui;
}

void SendFileDialog::ClientRefuse()
{
    ui->label->setText("对端拒绝接收");
    ui->btn_FileOpen->setEnabled(true);
    ui->btn_send->setEnabled(false);

}

void SendFileDialog::on_btn_FileOpen_clicked()
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

void SendFileDialog::on_btn_send_clicked()
{

    ui->label->setText("等待接收");
    ui->btn_FileOpen->setEnabled(false);
    ui->btn_send->setEnabled(false);
    emit sendFileName(FileName);
}

void SendFileDialog::on_btn_close_clicked()
{

    emit DlgSendCanel(Dlgid );
    emit DlgClose(Dlgid);
    close();

}

void SendFileDialog::on_pushButton_canel_clicked()
{
    InitDlg();
    emit DlgSendCanel(Dlgid );
}

void SendFileDialog::updateDateBytes(qint64 TotalBytes, qint64 bytesWritten,
                                     qint64 bytesToWrite,
                                     qint64 payloadSize,
                                     double speed, double usedtime)
{

    m_TotalBytes=TotalBytes;//要发送数据的总大小
    m_bytesWritten=bytesWritten;//已经发送数据的大小
    m_bytesToWrite=bytesToWrite;//剩余数据的大小
    m_payloadSize=payloadSize;//每次发送的大小


    //更新界面

    qint64 oneMB=(1024*1024);
    ui->label->setText(QString::asprintf("已发送%lldMB,发送速度%fMB/s,"
                                         "总共%lldMB,剩余%lldMB,剩余时间%fs"
                                         ,bytesWritten/oneMB,speed*1000/oneMB
                                         ,TotalBytes/oneMB,
                                         bytesToWrite/oneMB
                                         ,(bytesToWrite/oneMB)/(speed*1000/oneMB)));


    ui->progressBar->setMaximum(m_TotalBytes);
    ui->progressBar->setValue(m_bytesWritten);

}



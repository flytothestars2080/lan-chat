#ifndef TCPSENDFILEDIALOG_H
#define TCPSENDFILEDIALOG_H
#include<QTcpServer>
#include<QTcpSocket>
#include <QDialog>
#include<QString>
#include<QTime>
#include<QFile>
#include<QByteArray>
namespace Ui {
class TcpSendFileDialog;
}

class TcpSendFileDialog : public QDialog
{
    Q_OBJECT

private:
    QTime time;//计时器
    qint64 port;//端口号
    QTcpServer* tcpServer=nullptr;
    QString FilePath=""; //完整文件路径
    QString FileName;//文件名
    QTcpSocket *clientSocket=nullptr;//客户端连接的socket
    QFile *LoadFile=nullptr;//要发送的文件

qint64 TotalBytes=0;//要发送数据的总大小
qint64 bytesWritten=0;//已经发送数据的大小
qint64 bytesToWrite=0;//剩余数据的大小
qint64 payloadSize=0;//每次发送数据的大小

QByteArray outArray;//发送缓冲区

public:
    explicit TcpSendFileDialog(QWidget *parent = 0);
    ~TcpSendFileDialog();
qint64 getPayloadSize() const;
void setPayloadSize(const qint64 &value);
void ClientRefuse();
void  closeEvent(QCloseEvent*event)Q_DECL_OVERRIDE;
void InitServer();
private slots:
void SendMessage();
void updateSendProgess(qint64 ByteNum);

void on_btn_FileOpen_clicked();

void on_btn_send_clicked();
void on_btn_close_clicked();

void on_pushButton_canel_clicked();

signals:
void sendFileName(QString FileName);
private:
Ui::TcpSendFileDialog *ui;
};

#endif // TCPSENDFILEDIALOG_H

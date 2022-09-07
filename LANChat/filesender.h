#ifndef FILESENDER_H
#define FILESENDER_H

#include <QObject>
#include<QTcpSocket>
#include<QTime>
#include<QFile>
#include<QThread>
class FIleSender : public QObject
{
    Q_OBJECT
private:

    int m_dlgid=0;//服务于哪个对话框
    QString m_IP;
    QTime time;
    QTcpSocket*Clientsocket=nullptr;//通信socket
    QThread*Thethread;//线程地址
    QString m_FileName="";
    QString m_FilePath=""; //完整文件路径
    QFile *LoadFile=nullptr;//要发送的文件

qint64 m_TotalBytes=0;//要发送数据的总大小
qint64 m_bytesWritten=0;//已经发送数据的大小
qint64 m_bytesToWrite=0;//剩余数据的大小
qint64 m_payloadSize=0;//每次发送数据的大小

QByteArray outArray;//发送缓冲区

signals:
void DataBytesChange(qint64 TotalBytes,qint64 bytesWritten,qint64 bytesToWrite,
                     qint64 payloadSize,double speed, double  usedtime);
void errorString(QString error);
void fileSendComplete();
void SenderCreate(FIleSender*onefileSender,QString RecyIP);

private slots:
  void CreateSocket(qintptr socketDescriptor);
  void SenderStart_slot(FIleSender *onefileSender,QString FileName,QString FilePath,qint64 payloadSize,int dlgid);



void updataSendProgess(qint64 ByteNum);


public:

    explicit FIleSender(QObject *parent = nullptr);
    void initSender();
    void SendFileHead();//发送文件头意味者文件传输开始,发送文件头之前必须设置文件名,文件路径,每次发送数据的大小
    void closeSender();//退出thread,并且TCpserver会调用deletelater
public:
    QTcpSocket *getClientsocket() const;

    qint64 getPayloadSize() const;


    QString getFilePath() const;


    QString getFileName() const;




    QString getIP() const;

    QThread *getThethread() const;
    void setThethread(QThread *value);

    int getDlgid() const;

public slots:

};

#endif // FILESENDER_H

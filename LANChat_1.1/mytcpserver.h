#ifndef MYTCPSERVER_H
#define MYTCPSERVER_H

#include <QObject>
#include<QTcpServer>
#include<QTcpSocket>
#include<QList>
#include<QThread>
#include<filesender.h>

class MyTcpServer : public QTcpServer
{
    Q_OBJECT
private:
    QList<QThread*>threadlist;//线程链表
    QList<FIleSender*>fileSenderlist;//发送者链表,内部含有代表客户端通信的socket
public:
     explicit  MyTcpServer(QObject *parent = Q_NULLPTR);
     void closeSendThread(int dlgid);
     void MakeSenderWork(FIleSender *onefileSender,QString FileName,QString FilePath,qint64 payloadSize,int dlgid);
    ~MyTcpServer();
signals:
    void newFileSenderCreate(FIleSender*onefileSender,QString RecyIP);
    void CreateNewSocket(qintptr socketDescriptor);
    void SenderStart(FIleSender *onefileSender,QString FileName,QString FilePath,qint64 payloadSize,int dlgid);

private slots:
    void RemoveSenderAtList(QObject*sender);//从链表中删除
    void RemoveThreadAtList(QObject*sender);
    void SenderCreate_Slot(FIleSender*onefileSender,QString RecyIP);

protected:
void incomingConnection(qintptr socketDescriptor)Q_DECL_OVERRIDE  ;

};

#endif // MYTCPSERVER_H

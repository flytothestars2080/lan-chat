#include "mytcpserver.h"
#include <QMetaType>

MyTcpServer::MyTcpServer(QObject *parent )
    :QTcpServer(parent)
{

  qRegisterMetaType<qintptr>("qintptr");



}

void MyTcpServer::closeSendThread(int dlgid)
{
    for(int i=0;i<fileSenderlist.count();i++)
    {
        if(fileSenderlist.at(i)->getDlgid()==dlgid)
        {
            //关闭对应的线程和socket
            fileSenderlist.at(i)->getThethread()->quit();
            break;
        }
    }

}

void MyTcpServer::MakeSenderWork(FIleSender *onefileSender, QString FileName, QString FilePath, qint64 payloadSize,int dlgid)
{

   emit SenderStart(onefileSender,FileName,FilePath, payloadSize,dlgid);

}

MyTcpServer::~MyTcpServer()
{
    for(int i=0;i< threadlist.count();i++)
    {
        threadlist.at(i)->quit();
    }

    close();
}



void MyTcpServer::RemoveSenderAtList(QObject *sender)
{


        FIleSender*filesender;
        filesender=(FIleSender*)sender;
        if(filesender!=0)
        {
            fileSenderlist.removeOne(filesender);
            qDebug()<<"sender 删除成功";
        }




}

void MyTcpServer::RemoveThreadAtList(QObject *sender)
{
    QThread*Thethread=(QThread*)(sender);
    if(Thethread!=0)
    {
        threadlist.removeOne(Thethread);
        qDebug()<<"thread 删除成功";
    }

}

void MyTcpServer::SenderCreate_Slot(FIleSender*onefileSender,QString RecyIP)
{

    emit  newFileSenderCreate(onefileSender, RecyIP);

}

void MyTcpServer::incomingConnection(qintptr socketDescriptor)
{

    //创建object子对象,创建线程,绑定,调用addp...,发送信号


    FIleSender*onefileSender=new FIleSender();
    fileSenderlist.append(onefileSender);
    QThread*onethread=new QThread();
    threadlist.append(onethread);
    onefileSender->moveToThread(onethread);//移入线程
    connect(this,SIGNAL(CreateNewSocket(qintptr)),
            onefileSender,SLOT(CreateSocket(qintptr)));
    connect(onefileSender,SIGNAL(SenderCreate(FIleSender*,QString)),
                                 this,SLOT(SenderCreate_Slot(FIleSender*,QString)));
    connect(this,SIGNAL(SenderStart(FIleSender*,QString,QString,qint64,int)),
            onefileSender,SLOT(SenderStart_slot(FIleSender*,QString,QString,qint64,int)));


     onefileSender->setThethread(onethread);

    //绑定必须的信号和槽
      //释放堆空间资源
    //线程结束以后自动释放空间，并且将对应的指针从list中删除
    connect(onethread,SIGNAL(finished()),
           onethread,SLOT(deleteLater()));
    connect(onethread,SIGNAL(finished()),
          onefileSender,SLOT(deleteLater()));

    //将对应的指针置从list中删除
           connect(onethread, SIGNAL(destroyed(QObject*)),
                   this, SLOT(RemoveThreadAtList(QObject*)));
           connect(onefileSender,SIGNAL(destroyed(QObject*)) ,
                   this,SLOT(RemoveSenderAtList(QObject*)));
    //启动线程
           onethread->start();
           emit CreateNewSocket(socketDescriptor);//让线程创建socket

}

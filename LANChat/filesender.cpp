#include "filesender.h"
#include<QDataStream>
#include<QHostAddress>
QTcpSocket *FIleSender::getClientsocket() const
{
    return Clientsocket;
}

qint64 FIleSender::getPayloadSize() const
{
    return m_payloadSize;
}


QString FIleSender::getFilePath() const
{
    return m_FilePath;
}



FIleSender::FIleSender(QObject *parent) : QObject(parent)
{


}

QString FIleSender::getIP() const
{
    return m_IP;
}



int FIleSender::getDlgid() const
{
    return m_dlgid;
}



void FIleSender::CreateSocket(qintptr socketDescriptor)
{
    if(Clientsocket==nullptr)
    {
        Clientsocket=new QTcpSocket(this);
        Clientsocket->setSocketDescriptor(socketDescriptor);


        QHostAddress address (Clientsocket->peerAddress().toIPv4Address());
        m_IP= address.toString();
        //发送信号
        emit SenderCreate(this,m_IP);


    }

}

void FIleSender::SenderStart_slot(FIleSender *onefileSender, QString FileName, QString FilePath, qint64 payloadSize, int dlgid)
{
    if(onefileSender==this)
    {
        //初始化并且开始工作
        m_FileName=FileName;
        m_FilePath=FilePath;
        m_payloadSize=payloadSize;
        m_dlgid =dlgid;
        SendFileHead();
    }

}

void FIleSender::initSender()
{
    m_FileName="";
    m_FilePath=""; //完整文件路径
    LoadFile=nullptr;//要发送的文件
    m_TotalBytes=0;//要发送数据的总大小
    m_bytesWritten=0;//已经发送数据的大小
    m_bytesToWrite=0;//剩余数据的大小
    m_payloadSize=0;//每次发送数据的大小


}

QString FIleSender::getFileName() const
{
    return m_FileName;
}



void FIleSender::SendFileHead()
{

    //获取文件名，文件大小
    LoadFile=new QFile(m_FilePath);
    if(!LoadFile->open(QFile::ReadOnly))//文件打开失败就返回
    {
        emit errorString("文件打开失败");
        return ;
    }

    connect(Clientsocket,SIGNAL(bytesWritten(qint64 )),
            this,SLOT(updataSendProgess(qint64)));

    m_TotalBytes=LoadFile->size();//数据大小
    //数据流
    QDataStream out(&outArray,QIODevice::WriteOnly);

    out.setVersion(QDataStream::Qt_5_9);

    //准备文件头结构，总大小,文件名大小,文件名
    //先预留出要发送的总大小,文件名大小
    out<<qint64(0)<<qint64(0)<<m_FileName;
    out.device()->seek(0);//将输入位置定向到缓冲区的开头
    m_TotalBytes+=outArray.size();
    //写入总字节数，写入文件名大小
    out<<m_TotalBytes<<qint64((outArray.size()- sizeof(qint64)*2));

    //发送文件头结构
    time.start();//开启定时器
    m_bytesToWrite=m_TotalBytes -Clientsocket->write(outArray);
    outArray.resize(0);
    Clientsocket->waitForBytesWritten(100);//有时候会读不到信号试着调用这个函数

    qDebug()<<"文件头发送完成"<<"currentThreadId";


}

void FIleSender::closeSender()
{
    Clientsocket->close();
    Thethread->quit();
}

QThread *FIleSender::getThethread() const
{
    return Thethread;
}

void FIleSender::setThethread(QThread *value)
{
    Thethread = value;
}




void FIleSender::updataSendProgess(qint64 ByteNum)
{

    m_bytesWritten+=ByteNum;//已经发送数据的大小
    if(this->m_bytesToWrite>0)//如果有数据要发
    {
        //文件读取到缓冲区里
        //如果剩余数据不足64kb,就发剩余数据大小
        outArray=LoadFile->read(qMin(m_payloadSize,m_bytesToWrite));//读取数据
        m_bytesToWrite-=Clientsocket->write(outArray);//发送数据,更新剩余数据大小
        //清空缓冲区
        outArray.resize(0);
    }else
    {
        LoadFile->close();
    }

    //估算发送速度,发送时间
    double  usedtime=time.elapsed();
    double speed=m_bytesWritten/ usedtime;//单位是毫秒
    emit DataBytesChange(m_TotalBytes,m_bytesWritten,m_bytesToWrite,
                         m_payloadSize,speed,usedtime);



    qDebug()<<"文件发送一次"<<"currentThreadId"<<QThread::currentThreadId();

    //是否已发送完
    if(m_bytesWritten==m_TotalBytes)//这里bytesWritten才是真的写入socket缓冲区的大小
    {
        emit fileSendComplete();
        LoadFile->close();
        Clientsocket->close();
        initSender();

    }

}

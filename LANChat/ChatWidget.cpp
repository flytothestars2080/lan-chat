#include "ChatWidget.h"
#include"ui_ChatWidget.h"
#include "QHostInfo"
#include<QMessageBox>
#include<QScrollBar>
#include<QDateTime>
#include<QTableWidgetItem>
#include<QKeyEvent>
#include<QTextCursor>
#include"receivefiledialog.h"
#include<QFileDialog>
#include<QColorDialog>
#include<QDate>


qint16 ChatWidget::getPort() const
{
    return m_port;
}

void ChatWidget::setPort(const qint16 &value)
{
    m_port = value;
}

QString ChatWidget::getLocalUsername() const
{
    return m_LocalUsername;
}

void ChatWidget::setLocalUsername(const QString &value)
{
    m_LocalUsername = value;
}

void ChatWidget::closeEvent(QCloseEvent *event)
{
    sendMessage(ChatWidget::UserLeft);
    SaveMessageToFile();
    QWidget::closeEvent(event);
}

bool ChatWidget::SaveMessageToFile()
{

    QFile Localfile(QDir::currentPath()+"/chatMessage.msg");
    if(!Localfile.open(QIODevice::WriteOnly|QIODevice::Text))
    {
        QMessageBox::warning(this,"错误","聊天记录保存失败:"+Localfile.errorString());
        return false;
    }
    QTextStream out(&Localfile);
    out.setAutoDetectUnicode(true);
    QString mess= ui->messageBrowser->toPlainText();
    out<<ui->messageBrowser->toPlainText();
    return true;

}

bool ChatWidget::ReadSavedChatFromFile()
{
    //读取聊天记录
     QFile Localfile(QDir::currentPath()+"/chatMessage.msg");
     if(!Localfile.exists())
     {
         return false;
         //没有聊天记录文件
     }
     if(!Localfile.open(QIODevice::ReadOnly|QIODevice::Text))
     {
         QMessageBox::warning(this,"错误","聊天记录读取失败:"+Localfile.errorString());
         return false;
     }


     QTextStream in(&Localfile);
     in.setAutoDetectUnicode(true);
     ui->messageBrowser->append(in.readAll());
     return true;
}

void ChatWidget::hasPendingFile(QString username, QString sendIP, QString recyIP, QString Filename)
{

    if(recyIP==m_LocalIp)
    {

        int btn=QMessageBox::information(this,"确认?",
                                 tr("来自%1的文件%2,是否接收").arg(username).arg(Filename),
                                         QMessageBox::Yes,QMessageBox::No,QMessageBox::NoButton);

        if(btn==QMessageBox::Yes)
        {

            QString filepath=QFileDialog::getExistingDirectory(this);
            receiveFileDialog* recydlg=new receiveFileDialog(this);
            recydlg->setFileName(Filename);
            recydlg->SetFilePath(filepath);
            recydlg->SetAddress(QHostAddress(sendIP));//设置连接地址
            recydlg->show();
            recydlg->StartConnect();


        }else
        {
            sendMessage(RefuseFile,sendIP);
        }
    }
}

bool ChatWidget::eventFilter(QObject *watched, QEvent *event)
{
    if(watched==ui->messageTextEdit)
    {
        if(event->type()==QEvent::KeyPress)
        {
            QKeyEvent* keyEvent=dynamic_cast<QKeyEvent*>(event);

            //换行
            if(keyEvent->modifiers()==Qt::ControlModifier)
            {
                if(keyEvent->key()==Qt::Key_Return)
                {
                    if(ui->messageTextEdit->hasFocus())
                    {
                        QTextCursor TextCursor = ui->messageTextEdit->textCursor();
                        TextCursor.insertBlock();
                        return true;
                    }
                }
            }

            //发送
            if(keyEvent->key()==Qt::Key_Return)
            {
                if(ui->messageTextEdit->hasFocus())
                 sendMessage(Message);
                return true;//messageTextEdit不要处理了

            }
        }
    }

   return QWidget::eventFilter(watched,event);
}

ChatWidget::ChatWidget(QWidget *parent,QString username) :
    QWidget(parent),m_LocalUsername(username),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    //登录以后的初始化


    ui->messageTextEdit->installEventFilter(this);

    //设置TableWidget
    ui->userTableWidget->setColumnCount(4);
    //设置为只读
    ui->userTableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    QStringList headList;
    headList<<"用户名"<<"主机名"<<"ID"<<"IP";
    ui->userTableWidget->setHorizontalHeaderLabels(headList);
    ui->userTableWidget->setColumnHidden(3,false);//隐藏IP行

    udpsocket=new QUdpSocket(this);

    connect(udpsocket,SIGNAL(error(QAbstractSocket::SocketError)),
            this,SLOT(Socketerror_slot(QAbstractSocket::SocketError)));
    //绑定端口
   if( udpsocket->bind(m_port))
    {

        //获得本地IP
        m_LocalIp=getLocalIp();
        //本地主机名
        m_Localhostname=  QHostInfo::localHostName();
        //这里可以改成多线程
        connect(udpsocket,SIGNAL(readyRead()),
                this,SLOT(SocketReadyRead_slot()));
        //发送登陆消息
        sendMessage(NewUser);
        ReadSavedChatFromFile();

    }

   TcpsendDlg=new TcpSendFileDialog(this);
   connect(TcpsendDlg,SIGNAL(sendFileName(QString)),
           this,SLOT(sendFileName_slot(QString)));





}

ChatWidget::~ChatWidget()
{
    delete ui;
}

QString ChatWidget::getLocalIp()
{

    //获取本机Ipv4地址
    //获取主机名
    QString hostname=  QHostInfo::localHostName();
    QHostInfo hostinfo= QHostInfo::fromName(hostname);
    //根据主机名获得Ip地址
    QString localIP;
    QList<QHostAddress>addresslist= hostinfo.addresses();
    for(int i=0;i<addresslist.count();i++)
    {
        QHostAddress HostAddress =addresslist.at(i);
        if(QAbstractSocket::IPv4Protocol==HostAddress.protocol())
        {
            localIP=HostAddress.toString();
            break;
        }
    }


    return localIP;

}

void ChatWidget::NewUserCome(QString username, QString LocalHostName, QString IP, qint64 id)
{
    //处理新用户到来


    //判断是否已加入用户列表
    bool Isempty=ui->userTableWidget->findItems(username,Qt::MatchExactly).isEmpty();

    if(Isempty)
    {
        QString Uid=QString::number(id);
        //tabwidget添加新行
        QTableWidgetItem*userNAME=new QTableWidgetItem(username);
        QTableWidgetItem*hostNAME=new QTableWidgetItem(LocalHostName) ;
        QTableWidgetItem*userID=new QTableWidgetItem(Uid);
        QTableWidgetItem*userIP=new QTableWidgetItem(IP);
        //设置对齐
        userNAME->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
        hostNAME->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
        userID->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
        userIP->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

        //加入
        //首行添加
        ui->userTableWidget->insertRow(0);
        ui->userTableWidget->setItem(0,0,userNAME);
        ui->userTableWidget->setItem(0,1,hostNAME);
        ui->userTableWidget->setItem(0,2,userID);
        ui->userTableWidget->setItem(0,3,userIP);




        //提示新用户加入
        QString currentime=QDateTime::currentDateTime().toString(
                    "yyyy年MM月dd日 hh:mm:ss");
        ui->messageBrowser->setTextColor(Qt::black);
        ui->messageBrowser->setCurrentFont(QFont("宋体",12));
        ui->messageBrowser->append("["+username+"]"+" 加入 "+currentime);

        this->m_userCount++;
        //更新用户数
        ui->userNumLabel->setText(QString::asprintf("在线用户：%d人",m_userCount));

        //使新用户也更新用户列表
        sendMessage(ChatWidget::NewUser);

    }


}

void ChatWidget::OneUserLeft(QString username, QString IP, qint64 id)
{
    //更新用户列表,删除离去的用户列

  int row= ui->userTableWidget->findItems(username,Qt::MatchExactly).first()->row();
  ui->userTableWidget->removeRow(row);

  //提示用户离去
  QString currentime=QDateTime::currentDateTime().toString(
              "yyyy年MM月dd日:hh:mm:ss");
  ui->messageBrowser->setTextColor(Qt::gray);
  ui->messageBrowser->setCurrentFont(QFont("宋体",12));
  ui->messageBrowser->append("["+username+"]"+"离去:"+currentime);
  m_userCount--;
  //更新用户数
  ui->userNumLabel->setText(QString::asprintf("在线用户：%d人",m_userCount));


}

void ChatWidget::sendMessage(ChatWidget::MessageType messageType,QString IP)
{
    QByteArray data;

    QDataStream out(&data,QIODevice::WriteOnly);//通过数据流变成二进制编码并且跨平台

    out<<messageType<<m_LocalUsername<<m_Localhostname;
    switch(messageType)
    {
    case   ChatWidget::Message:
        if(ui->messageTextEdit->toPlainText().isEmpty())
        {
            QMessageBox::warning(this,tr("警告"),tr("发送内容为空"));
            return ;
        }
        else
        {
            //读取消息广播
            out<<m_LocalIp<<GetMessage();
            //移动到最新消息
            ui->messageBrowser->verticalScrollBar()->setValue
                    (ui->messageBrowser->verticalScrollBar()->maximum());

        }
        break;
    case  ChatWidget::NewUser://登录
        out<<m_LocalIp<<m_LocalId;
        break;
    case ChatWidget::UserLeft:
       out<<m_LocalIp;

        break;
    case ChatWidget::RefuseFile:
        out<<IP;
        break;

    case ChatWidget::FileName:
        out<<m_LocalIp<<m_recyIP<<m_SendFilename;
        break;


    }
    //写入socket的输出缓冲区
    udpsocket->writeDatagram(data,data.length(),QHostAddress::Broadcast,m_port);
}



QString ChatWidget::GetMessage()
{
    QString msg=ui->messageTextEdit->toHtml();
    ui->messageTextEdit->clear();
    ui->messageTextEdit->setFocus();
    return  msg;

}

void ChatWidget::Socketerror_slot(QAbstractSocket::SocketError socketError)
{

    switch (socketError) {
    case QAbstractSocket::ConnectionRefusedError:
        break;
    case QAbstractSocket::RemoteHostClosedError:
        break;
    case  QAbstractSocket::HostNotFoundError:
        break;
       case QAbstractSocket::AddressInUseError:
         QMessageBox::question(this,QString::asprintf("错误,错误码:%d",socketError),"端口已被应用程序绑定");
         exit(-socketError);

         return ;
        break;
    default:
        break;
    }

    QMessageBox::warning(this,QString::asprintf("错误,错误码:%d",socketError),udpsocket->errorString());

}

void ChatWidget::SocketReadyRead_slot()
{

    while(udpsocket->hasPendingDatagrams())
    {
        QByteArray Datagrams;//数据报
        Datagrams.resize(udpsocket->pendingDatagramSize());
        //读取数据报,分析数据报
        udpsocket->readDatagram(Datagrams.data(),Datagrams.size());
        QDataStream in(&Datagrams,QIODevice::ReadOnly);

        int messageType;
        qint64 ID;
        QString Username,hostname,Ip,message;

        in>>messageType>>Username>>hostname;
        QString currentime=QDateTime::currentDateTime().toString(
                    "yyyy年MM月dd日 hh:mm:ss");



        switch(messageType)
        {
        case   ChatWidget::Message:
                //读取消息广播
                in>>Ip>>message;
              //显示消息
               ui->messageBrowser->setTextColor(Qt::black);
               ui->messageBrowser->setCurrentFont(QFont("宋体",12));
               ui->messageBrowser->append("["+Username+"]"+currentime);
               ui->messageBrowser->append(message);



            break;
        case  ChatWidget::NewUser://登录
            in>>Ip>>ID;
            NewUserCome(Username,hostname,Ip,ID);//新用户到来

            break;
        case ChatWidget::UserLeft:
            in>>Ip;
            OneUserLeft(Username,Ip);


            break;
        case ChatWidget::RefuseFile:
             in>>Ip;
             if(Ip==m_LocalIp)
             {
                 TcpsendDlg->ClientRefuse();
             }

            break;

        case ChatWidget::FileName:
            QString sendIp;
            QString FilerecyIp;//接收者IP
            QString recyFileName;//需要接收文件的名字
            in>>sendIp>>FilerecyIp>>recyFileName;
            hasPendingFile(Username,sendIp,FilerecyIp,recyFileName);
            break;

        }




    }



}

void ChatWidget::on_sendButton_clicked()
{


    sendMessage(Message);

}

void ChatWidget::on_exitButton_clicked()
{
    this->close();
}

void ChatWidget::sendFileName_slot(QString filename)
{
    //收到了发送窗口发来的文件名

   m_SendFilename=filename;
    sendMessage(FileName);//广播FileName;

}



void ChatWidget::on_sendFileToolBtn_clicked()
{

    if(ui->userTableWidget->selectedItems().isEmpty())
    {
        QMessageBox::warning(this,"请选择","请选择要发送文件用户");

    }else
    {
        int row=ui->userTableWidget->currentRow();
        m_recyIP =ui->userTableWidget->item(row,3)->text();//获取接收端的IP地址
        TcpsendDlg->InitServer();
        TcpsendDlg->show();
    }
}

void ChatWidget::on_fontComboBox_currentFontChanged(const QFont &f)
{
    ui->messageTextEdit->setFont(f);
    ui->messageTextEdit->setFocus();
}

void ChatWidget::on_sizeComboBox_currentIndexChanged(const QString &arg1)
{
    bool ok;
    ui->messageTextEdit->setFontPointSize(arg1.toDouble(&ok));
    ui->messageTextEdit->setFocus();
}

void ChatWidget::on_boldToolBtn_clicked(bool checked)
{

    QTextCharFormat format;
    QFont font;
    font.setBold(checked);
    format.setFont(font);
    ui->messageTextEdit->setCurrentCharFormat(format);
    ui->messageTextEdit->setFocus();
}


void ChatWidget::on_italicToolBtn_clicked(bool checked)
{
    ui->messageTextEdit->setFontItalic(checked);
    ui->messageTextEdit->setFocus();

}

void ChatWidget::on_underlineToolBtn_clicked(bool checked)
{
    ui->messageTextEdit->setFontUnderline(checked);
    ui->messageTextEdit->setFocus();
}

void ChatWidget::on_colorToolBtn_clicked()
{
    QColor color= QColorDialog::getColor(Qt::white,this);
    if(color.isValid())
    {
        ui->messageTextEdit->setTextColor(color);
        ui->messageTextEdit->setFocus();

    }

}

void ChatWidget::on_messageTextEdit_currentCharFormatChanged(const QTextCharFormat &format)
{
    ui->fontComboBox->setCurrentFont(format.font());
    if(format.fontPointSize()<9)
    {
        ui->sizeComboBox->setCurrentIndex(3);
    }else
    {
        ui->sizeComboBox->setCurrentIndex(ui->sizeComboBox->findText(
                                              QString::number(format.fontPointSize())));
    }
    ui->boldToolBtn->setChecked(format.font().bold());
    ui->italicToolBtn->setChecked(format.font().italic());
    ui->underlineToolBtn->setChecked(format.font().underline());

}

void ChatWidget::on_clearToolBtn_clicked()
{
    ui->messageTextEdit->clear();
}

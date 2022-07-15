#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include<QUdpSocket>
#include<QString>
#include<QHash>
#include"tcpsendfiledialog.h"
#include<QTextCharFormat>

namespace Ui {
class Widget;
}

class ChatWidget : public QWidget
{
    Q_OBJECT
public:
    bool eventFilter(QObject *watched, QEvent *event)Q_DECL_OVERRIDE;//处理messageBrowser的键盘事件

private:
    QString m_LocalIp;
    QString m_Localhostname;
    QString m_LocalUsername;
    qint64 m_LocalId=-1;
    int m_userCount=0;
    QString m_recyIP;
    QUdpSocket*udpsocket=NULL;
    qint16 m_port=12345;//端口号
    QString m_SendFilename;//要发送的文件名字
    TcpSendFileDialog*TcpsendDlg;//发送窗口

public:
    explicit ChatWidget(QWidget *parent = 0,QString username="默认用户");
    ~ChatWidget();

    qint16 getPort() const;
    void setPort(const qint16 &value);

    QString getLocalUsername() const;
    void setLocalUsername(const QString &value);

protected:

   void closeEvent(QCloseEvent *event)Q_DECL_OVERRIDE;
   bool SaveMessageToFile();//保存聊天记录到文件
   bool ReadSavedChatFromFile();//从文件中读取聊天记录
    enum MessageType
    {
        Message,//通信消息
        NewUser,//新的用户
        UserLeft,//用户离去
        FileName,//文件名
        RefuseFile,//拒绝接收文件


    };

    void hasPendingFile(QString username,QString sendIP,QString recyIP,QString Filename);//是否接收文件


    void NewUserCome(QString username,QString LocalHostName,QString IP,qint64 id=-1);//新用户到来
    void OneUserLeft(QString username,QString IP, qint64 id=-1);//用户离去
    void sendMessage(MessageType messageType,QString IP="");

    QString getLocalIp();
    QString GetMessage();
private slots:
    void Socketerror_slot(QAbstractSocket::SocketError socketError);
    void SocketReadyRead_slot();//一个数据报(报文段)已到达
    void on_sendButton_clicked();

    void on_exitButton_clicked();
    void sendFileName_slot(QString filename);//获取发送窗口选中得文件名



    void on_sendFileToolBtn_clicked();

    void on_fontComboBox_currentFontChanged(const QFont &f);

    void on_sizeComboBox_currentIndexChanged(const QString &arg1);

    void on_boldToolBtn_clicked(bool checked);


    void on_italicToolBtn_clicked(bool checked);

    void on_underlineToolBtn_clicked(bool checked);

    void on_colorToolBtn_clicked();

    void on_messageTextEdit_currentCharFormatChanged(const QTextCharFormat &format);

    void on_clearToolBtn_clicked();

private:


      Ui::Widget *ui;

};

#endif // WIDGET_H

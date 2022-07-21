#ifndef RECEIVEFILEDIALOG_H
#define RECEIVEFILEDIALOG_H
#include<QTcpSocket>
#include <QDialog>
#include<QFile>
#include<QHostAddress>
#include<QTime>

namespace Ui {
class receiveFileDialog;
}

class receiveFileDialog : public QDialog
{
    Q_OBJECT

private:

    QTime time;

    qint64 totalBytes;//已接收到的总数据
    qint64 bytesRecevivded;//已收到的数据大小
    qint64 fileNameSize;//文件名的大小信息
    qint16 port=6666;
    QTcpSocket *client=nullptr;
    QString fileName;//文件名
    QFile *loadFile=nullptr;//本地文件
    QByteArray inArray;//数据缓冲区
    QString filepath;

    QHostAddress peeraddress;//对端地址


public:
    explicit receiveFileDialog(QWidget *parent = 0);
    ~receiveFileDialog();
    void SetFilePath(QString filePath);//设置完整的包含文件名路径
    void SetAddress(QHostAddress address);//设置地址
    void StartConnect();//连接
    void setFileName(const QString &value);

    QString getFilepath() const;

protected:
    void closeEvent(QCloseEvent *event)Q_DECL_OVERRIDE;
private slots:
    void  readMessage();
    void  on_error(QAbstractSocket::SocketError socketError);

    void Init();
    void on_btn_canel_clicked();

    void on_btn_close_clicked();

private:
    Ui::receiveFileDialog *ui;
};

#endif // RECEIVEFILEDIALOG_H

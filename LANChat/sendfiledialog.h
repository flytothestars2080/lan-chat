#ifndef SENDFILEDIALOG_H
#define SENDFILEDIALOG_H

#include <QDialog>

namespace Ui {
class SendFileDialog;
}

class SendFileDialog : public QDialog
{
    Q_OBJECT

private:
    int Dlgid=0;
    QString recyIP;//接收方IP
    QString FilePath=""; //完整文件路径
    QString FileName;//文件名
    qint64 m_TotalBytes=0;//要发送数据的总大小
    qint64 m_bytesWritten=0;//已经发送数据的大小
    qint64 m_bytesToWrite=0;//剩余数据的大小
    qint64 m_payloadSize=0;//每次发送数据的大小
public:
    explicit SendFileDialog(QWidget *parent = 0);
    ~SendFileDialog();
    void  ClientRefuse();

    int getDlgid() const;
    void setDlgid(int value);
    QString getRecyIP() const;
    void setRecyIP(const QString &value);
    void InitDlg();

    QString getFilePath() const;

    void setFileName(const QString &value);

    QString getFileName() const;

    qint64 getPayloadSize() const;
    void setPayloadSize(const qint64 &payloadSize);

signals:
    void sendFileName(QString FileName);
    void DlgSendCanel(int dlgid);
    void DlgClose(int dlgid);
private slots:
    void on_btn_FileOpen_clicked();

    void on_btn_send_clicked();

    void on_btn_close_clicked();

    void on_pushButton_canel_clicked();
    void updateDateBytes(qint64 TotalBytes, qint64 bytesWritten, qint64 bytesToWrite, qint64 payloadSize,
                         double speed, double usedtime);//更新文件发送数据记录
private:
    Ui::SendFileDialog *ui;
};

#endif // SENDFILEDIALOG_H

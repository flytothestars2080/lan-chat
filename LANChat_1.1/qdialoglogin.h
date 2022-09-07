#ifndef QDIALOGLOGIN_H
#define QDIALOGLOGIN_H

#include <QDialog>
#include<QString>
#include<QMouseEvent>

namespace Ui {
class QDialogLogin;
}

class QDialogLogin : public QDialog
{
    Q_OBJECT
private:
    bool m_moveing=false;//表示窗口是否在鼠标的操作下移动
    bool m_IsComboxNeedChange=false;
    QPoint m_lastPos;//上一次的鼠标位置
    QString m_user="user";//初始化用户名
    QString m_pswd="123456";//初始化密码，未加密的
    int m_TryCount=0;
    bool readFile();//读取文件
    bool writeFile();//写入文件
   QString  encrypt(const QString&str);//加密字符串
protected: //用于鼠标拖动窗口的鼠标事件
   void mousePressEvent(QMouseEvent*event);//鼠标摁住
   void mouseMoveEvent(QMouseEvent*event);//鼠标移动
   void mouseReleaseEvent(QMouseEvent*event);//鼠标松开


public:
    explicit QDialogLogin(QWidget *parent = 0);
    ~QDialogLogin();
   QString GetUserName();



   QString user() const;
   void setUser(const QString &user);

private slots:
   void on_btnOK_clicked();


   void on_btn_delete_username_clicked();

   void on_btnCancel_clicked();

private:
   Ui::QDialogLogin *ui;


};

#endif // QDIALOGLOGIN_H

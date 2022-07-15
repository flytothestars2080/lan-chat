#include "ChatWidget.h"
#include"qdialoglogin.h"
#include <QApplication>
#include<QTextCodec>
#include<QTranslator>

int main(int argc, char *argv[])
{
    //解决汉字乱码问题
    QTextCodec*codec=QTextCodec::codecForName("UTF-8");
    QTextCodec::setCodecForLocale(codec);
    QApplication a(argc, argv);

    QTranslator trans;
    bool ok;
    ok=trans.load("qtbase_zh_CN .qm");
    a.installTranslator(&trans);

    QDialogLogin *Login=new  QDialogLogin ;
    if(QDialog::Accepted==Login->exec())
    {
        ChatWidget w(nullptr,Login->user());
        Login->deleteLater();
        Login=nullptr;
        w.show();
        return a.exec();
    }
     else
    {
        return 0;
    }


}

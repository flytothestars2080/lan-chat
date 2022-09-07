#include "qdialoglogin.h"
#include "ui_qdialoglogin.h"
#include<QFile>
#include<QDir>
#include<QCryptographicHash>
#include<QMessageBox>

QString QDialogLogin::user() const
{
    return m_user;
}

void QDialogLogin::setUser(const QString &user)
{
    m_user = user;
}

bool QDialogLogin::readFile()
{
    QString currentPath=QDir::currentPath();
    QFile file(currentPath+"/init.dat");
    if(!file.exists())
    {
        return false;
    }



    if(!file.open(QIODevice::ReadOnly))
    {
        return false;
    }

      QDataStream in(&file);
      int count;
      in>>count;
      for(int i=0;i<count;i++)
      {
          QString str;
          in>>str;
          ui->comboBox->addItem(str);
      }
      return true;


}

bool QDialogLogin::writeFile()
{
    //保存用户名到文件里
    QString currentPath=QDir::currentPath();
    QFile file(currentPath+"/init.dat");
    if(!file.open(QIODevice::WriteOnly|QIODevice::Truncate))
    {
        return false;
    }

    QDataStream out(&file);
    out<<ui->comboBox->count();
   for(int i=0;i<ui->comboBox->count();i++)
   {
       out<<ui->comboBox->itemText(i);

   }
   file.close();
   return true;



}

QString QDialogLogin::encrypt(const QString &str)
{
    //字符串MD5加密
    QByteArray btArray;
    btArray.append(str);
    QCryptographicHash hash(QCryptographicHash::Md5);
    hash.addData(btArray);
    QByteArray  resultArray=hash.result();
    QString md5=resultArray.toHex();//转化成十六进制
    return md5;

}

void QDialogLogin::mousePressEvent(QMouseEvent *event)
{
    //event->globalPos()获取鼠标以电脑屏幕左上角为原点的向量
    if(event->button()==Qt::LeftButton)
    {
        this->m_moveing=true;
        m_lastPos=event->globalPos()-pos();//使用向量的减法获得鼠标相对于窗口的位置

    }
    return  QDialog::mousePressEvent(event);

}

void QDialogLogin::mouseMoveEvent(QMouseEvent *event)
{
    //在mouseMoveEvent 里event->button()返回的引进事件的button永远是Qt::NoButton!!
    if(m_moveing && (event->buttons()&&Qt::LeftButton))//左键被按下
    {
        move(event->globalPos()-m_lastPos);
       //m_lastPos=event->globalPos()-pos();//使用向量的减法获得鼠标相对于窗口的位置
    }
   return QDialog::mouseMoveEvent(event);
}

void QDialogLogin::mouseReleaseEvent(QMouseEvent *event)
{
   Q_UNUSED(event);
   m_moveing=false;
}

QDialogLogin::QDialogLogin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::QDialogLogin)
{
    ui->setupUi(this);
    ui->editPSWD->setEchoMode(QLineEdit::Password);
    this->setWindowFlags(Qt::SplashScreen);//设置为登录界面
    this->setWindowFlags(Qt::FramelessWindowHint);//无边框但在任务栏上显示标题

    readFile();
    ui->comboBox->setCurrentIndex(ui->comboBox->count()-1);
}

QDialogLogin::~QDialogLogin()
{
    delete ui;
}

QString QDialogLogin::GetUserName()
{
    return ui->comboBox->currentText().trimmed();
}

void QDialogLogin::on_btnOK_clicked()
{
    QString user=ui->comboBox->currentText().trimmed();//消掉开头和结尾的空格
    QString pswd=ui->editPSWD->text().trimmed();
    QString encrptPSWD=encrypt(pswd);

    //获取改用户名的密码 GetPSWDByName;
    QString rigthPswd=encrypt(m_pswd);
    m_user=GetUserName();

    if((user==m_user)&&(encrptPSWD==rigthPswd))
    {
        if(ui->chkBoxSave->isChecked())
        {
            ui->comboBox->addItem(ui->comboBox->currentText());//把当前文本加入
            writeFile();
        }

        this->accept();
    }
    else
    {
        m_TryCount++;
        if(m_TryCount>3)
        {
            QMessageBox::critical(this,"错误","输入错误次数太多,强行退出");
            if(m_IsComboxNeedChange)//是否需要更新Combox里存的用户
                 writeFile();
            this->reject();
        }
        else
        {
            QMessageBox::warning(this,"错误提示","用户名或密码错误");
        }
    }
}


void QDialogLogin::on_btn_delete_username_clicked()
{
  if(0==ui->comboBox->count())
  {
      ui->comboBox->setCurrentText("");
  }else
  {
    ui->comboBox->removeItem(ui->comboBox->currentIndex());
    this->m_IsComboxNeedChange=true;
  }



}

void QDialogLogin::on_btnCancel_clicked()
{
    if(m_IsComboxNeedChange)//是否需要更新Combox里存的用户
         writeFile();
    this->reject();
}

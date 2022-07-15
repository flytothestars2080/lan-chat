/********************************************************************************
** Form generated from reading UI file 'tcpsendfiledialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TCPSENDFILEDIALOG_H
#define UI_TCPSENDFILEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_TcpSendFileDialog
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *btn_FileOpen;
    QPushButton *btn_send;
    QPushButton *btn_close;
    QPushButton *pushButton_canel;
    QLabel *label;
    QProgressBar *progressBar;
    QLabel *label_FilePath;

    void setupUi(QDialog *TcpSendFileDialog)
    {
        if (TcpSendFileDialog->objectName().isEmpty())
            TcpSendFileDialog->setObjectName(QStringLiteral("TcpSendFileDialog"));
        TcpSendFileDialog->resize(456, 321);
        gridLayout = new QGridLayout(TcpSendFileDialog);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        btn_FileOpen = new QPushButton(TcpSendFileDialog);
        btn_FileOpen->setObjectName(QStringLiteral("btn_FileOpen"));

        horizontalLayout->addWidget(btn_FileOpen);

        btn_send = new QPushButton(TcpSendFileDialog);
        btn_send->setObjectName(QStringLiteral("btn_send"));

        horizontalLayout->addWidget(btn_send);

        btn_close = new QPushButton(TcpSendFileDialog);
        btn_close->setObjectName(QStringLiteral("btn_close"));

        horizontalLayout->addWidget(btn_close);

        pushButton_canel = new QPushButton(TcpSendFileDialog);
        pushButton_canel->setObjectName(QStringLiteral("pushButton_canel"));

        horizontalLayout->addWidget(pushButton_canel);


        gridLayout->addLayout(horizontalLayout, 3, 0, 1, 1);

        label = new QLabel(TcpSendFileDialog);
        label->setObjectName(QStringLiteral("label"));
        label->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        progressBar = new QProgressBar(TcpSendFileDialog);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setValue(24);

        gridLayout->addWidget(progressBar, 2, 0, 1, 1);

        label_FilePath = new QLabel(TcpSendFileDialog);
        label_FilePath->setObjectName(QStringLiteral("label_FilePath"));
        label_FilePath->setMaximumSize(QSize(4000, 20));

        gridLayout->addWidget(label_FilePath, 1, 0, 1, 1);


        retranslateUi(TcpSendFileDialog);

        QMetaObject::connectSlotsByName(TcpSendFileDialog);
    } // setupUi

    void retranslateUi(QDialog *TcpSendFileDialog)
    {
        TcpSendFileDialog->setWindowTitle(QApplication::translate("TcpSendFileDialog", "\345\217\221\351\200\201\346\226\207\344\273\266", Q_NULLPTR));
        btn_FileOpen->setText(QApplication::translate("TcpSendFileDialog", "\346\211\223\345\274\200\346\226\207\344\273\266", Q_NULLPTR));
        btn_send->setText(QApplication::translate("TcpSendFileDialog", "\345\217\221\351\200\201", Q_NULLPTR));
        btn_close->setText(QApplication::translate("TcpSendFileDialog", "\345\205\263\351\227\255", Q_NULLPTR));
        pushButton_canel->setText(QApplication::translate("TcpSendFileDialog", "\345\217\226\346\266\210", Q_NULLPTR));
        label->setText(QApplication::translate("TcpSendFileDialog", "\350\257\267\351\200\211\346\213\251\350\246\201\345\217\221\351\200\201\347\232\204\346\226\207\344\273\266", Q_NULLPTR));
        label_FilePath->setText(QApplication::translate("TcpSendFileDialog", "\346\226\207\344\273\266\350\267\257\345\276\204:", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class TcpSendFileDialog: public Ui_TcpSendFileDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TCPSENDFILEDIALOG_H

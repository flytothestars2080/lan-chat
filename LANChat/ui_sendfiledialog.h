/********************************************************************************
** Form generated from reading UI file 'sendfiledialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SENDFILEDIALOG_H
#define UI_SENDFILEDIALOG_H

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

class Ui_SendFileDialog
{
public:
    QGridLayout *gridLayout;
    QProgressBar *progressBar;
    QLabel *label;
    QLabel *label_FilePath;
    QHBoxLayout *horizontalLayout;
    QPushButton *btn_FileOpen;
    QPushButton *btn_send;
    QPushButton *pushButton_canel;
    QPushButton *btn_close;

    void setupUi(QDialog *SendFileDialog)
    {
        if (SendFileDialog->objectName().isEmpty())
            SendFileDialog->setObjectName(QStringLiteral("SendFileDialog"));
        SendFileDialog->resize(367, 240);
        gridLayout = new QGridLayout(SendFileDialog);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        progressBar = new QProgressBar(SendFileDialog);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setValue(24);

        gridLayout->addWidget(progressBar, 3, 1, 1, 1);

        label = new QLabel(SendFileDialog);
        label->setObjectName(QStringLiteral("label"));
        label->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label, 1, 1, 1, 1);

        label_FilePath = new QLabel(SendFileDialog);
        label_FilePath->setObjectName(QStringLiteral("label_FilePath"));
        label_FilePath->setMaximumSize(QSize(4000, 20));

        gridLayout->addWidget(label_FilePath, 2, 1, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        btn_FileOpen = new QPushButton(SendFileDialog);
        btn_FileOpen->setObjectName(QStringLiteral("btn_FileOpen"));

        horizontalLayout->addWidget(btn_FileOpen);

        btn_send = new QPushButton(SendFileDialog);
        btn_send->setObjectName(QStringLiteral("btn_send"));

        horizontalLayout->addWidget(btn_send);

        pushButton_canel = new QPushButton(SendFileDialog);
        pushButton_canel->setObjectName(QStringLiteral("pushButton_canel"));

        horizontalLayout->addWidget(pushButton_canel);

        btn_close = new QPushButton(SendFileDialog);
        btn_close->setObjectName(QStringLiteral("btn_close"));

        horizontalLayout->addWidget(btn_close);


        gridLayout->addLayout(horizontalLayout, 4, 1, 1, 1);


        retranslateUi(SendFileDialog);

        QMetaObject::connectSlotsByName(SendFileDialog);
    } // setupUi

    void retranslateUi(QDialog *SendFileDialog)
    {
        SendFileDialog->setWindowTitle(QApplication::translate("SendFileDialog", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("SendFileDialog", "\350\257\267\351\200\211\346\213\251\350\246\201\345\217\221\351\200\201\347\232\204\346\226\207\344\273\266", Q_NULLPTR));
        label_FilePath->setText(QApplication::translate("SendFileDialog", "\346\226\207\344\273\266\350\267\257\345\276\204:", Q_NULLPTR));
        btn_FileOpen->setText(QApplication::translate("SendFileDialog", "\346\211\223\345\274\200\346\226\207\344\273\266", Q_NULLPTR));
        btn_send->setText(QApplication::translate("SendFileDialog", "\345\217\221\351\200\201", Q_NULLPTR));
        pushButton_canel->setText(QApplication::translate("SendFileDialog", "\345\217\226\346\266\210", Q_NULLPTR));
        btn_close->setText(QApplication::translate("SendFileDialog", "\345\205\263\351\227\255", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class SendFileDialog: public Ui_SendFileDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SENDFILEDIALOG_H

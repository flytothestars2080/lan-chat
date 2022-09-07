/********************************************************************************
** Form generated from reading UI file 'receivefiledialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RECEIVEFILEDIALOG_H
#define UI_RECEIVEFILEDIALOG_H

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

class Ui_receiveFileDialog
{
public:
    QGridLayout *gridLayout;
    QProgressBar *progressBar;
    QLabel *label;
    QLabel *label_FilePath;
    QHBoxLayout *horizontalLayout;
    QPushButton *btn_canel;
    QPushButton *btn_close;

    void setupUi(QDialog *receiveFileDialog)
    {
        if (receiveFileDialog->objectName().isEmpty())
            receiveFileDialog->setObjectName(QStringLiteral("receiveFileDialog"));
        receiveFileDialog->resize(451, 222);
        gridLayout = new QGridLayout(receiveFileDialog);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        progressBar = new QProgressBar(receiveFileDialog);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setValue(24);

        gridLayout->addWidget(progressBar, 2, 1, 1, 1);

        label = new QLabel(receiveFileDialog);
        label->setObjectName(QStringLiteral("label"));
        label->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label, 0, 0, 2, 2);

        label_FilePath = new QLabel(receiveFileDialog);
        label_FilePath->setObjectName(QStringLiteral("label_FilePath"));
        label_FilePath->setMaximumSize(QSize(4000, 20));

        gridLayout->addWidget(label_FilePath, 1, 1, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        btn_canel = new QPushButton(receiveFileDialog);
        btn_canel->setObjectName(QStringLiteral("btn_canel"));

        horizontalLayout->addWidget(btn_canel);

        btn_close = new QPushButton(receiveFileDialog);
        btn_close->setObjectName(QStringLiteral("btn_close"));

        horizontalLayout->addWidget(btn_close);


        gridLayout->addLayout(horizontalLayout, 3, 1, 1, 1);


        retranslateUi(receiveFileDialog);

        QMetaObject::connectSlotsByName(receiveFileDialog);
    } // setupUi

    void retranslateUi(QDialog *receiveFileDialog)
    {
        receiveFileDialog->setWindowTitle(QApplication::translate("receiveFileDialog", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("receiveFileDialog", "\346\255\243\345\234\250\346\216\245\346\224\266\346\226\207\344\273\266.....", Q_NULLPTR));
        label_FilePath->setText(QApplication::translate("receiveFileDialog", "\346\226\207\344\273\266\350\267\257\345\276\204:", Q_NULLPTR));
        btn_canel->setText(QApplication::translate("receiveFileDialog", "\345\217\226\346\266\210", Q_NULLPTR));
        btn_close->setText(QApplication::translate("receiveFileDialog", "\345\205\263\351\227\255", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class receiveFileDialog: public Ui_receiveFileDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RECEIVEFILEDIALOG_H

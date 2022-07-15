/********************************************************************************
** Form generated from reading UI file 'qdialoglogin.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QDIALOGLOGIN_H
#define UI_QDIALOGLOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_QDialogLogin
{
public:
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QLineEdit *editPSWD;
    QPushButton *btnCancel;
    QPushButton *btnOK;
    QLabel *label_2;
    QLabel *label_3;
    QComboBox *comboBox;
    QCheckBox *chkBoxSave;
    QPushButton *btn_delete_username;

    void setupUi(QDialog *QDialogLogin)
    {
        if (QDialogLogin->objectName().isEmpty())
            QDialogLogin->setObjectName(QStringLiteral("QDialogLogin"));
        QDialogLogin->resize(434, 197);
        gridLayout_2 = new QGridLayout(QDialogLogin);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        editPSWD = new QLineEdit(QDialogLogin);
        editPSWD->setObjectName(QStringLiteral("editPSWD"));
        editPSWD->setEchoMode(QLineEdit::Password);

        gridLayout->addWidget(editPSWD, 1, 1, 1, 1);

        btnCancel = new QPushButton(QDialogLogin);
        btnCancel->setObjectName(QStringLiteral("btnCancel"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/images/images/706.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        btnCancel->setIcon(icon);

        gridLayout->addWidget(btnCancel, 3, 2, 1, 1);

        btnOK = new QPushButton(QDialogLogin);
        btnOK->setObjectName(QStringLiteral("btnOK"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/images/images/704.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        btnOK->setIcon(icon1);

        gridLayout->addWidget(btnOK, 3, 0, 1, 2);

        label_2 = new QLabel(QDialogLogin);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 0, 0, 1, 1);

        label_3 = new QLabel(QDialogLogin);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 1, 0, 1, 1);

        comboBox = new QComboBox(QDialogLogin);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setEditable(true);

        gridLayout->addWidget(comboBox, 0, 1, 1, 1);

        chkBoxSave = new QCheckBox(QDialogLogin);
        chkBoxSave->setObjectName(QStringLiteral("chkBoxSave"));

        gridLayout->addWidget(chkBoxSave, 1, 2, 1, 1);

        btn_delete_username = new QPushButton(QDialogLogin);
        btn_delete_username->setObjectName(QStringLiteral("btn_delete_username"));

        gridLayout->addWidget(btn_delete_username, 0, 2, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);


        retranslateUi(QDialogLogin);

        QMetaObject::connectSlotsByName(QDialogLogin);
    } // setupUi

    void retranslateUi(QDialog *QDialogLogin)
    {
        QDialogLogin->setWindowTitle(QApplication::translate("QDialogLogin", "Dialog", Q_NULLPTR));
        btnCancel->setText(QApplication::translate("QDialogLogin", "\345\205\263\351\227\255", Q_NULLPTR));
        btnOK->setText(QApplication::translate("QDialogLogin", "\347\231\273\345\275\225", Q_NULLPTR));
        label_2->setText(QApplication::translate("QDialogLogin", "\347\224\250\346\210\267\345\220\215", Q_NULLPTR));
        label_3->setText(QApplication::translate("QDialogLogin", "\345\257\206 \347\240\201", Q_NULLPTR));
        chkBoxSave->setText(QApplication::translate("QDialogLogin", "\344\277\235\345\255\230\347\224\250\346\210\267\345\220\215", Q_NULLPTR));
        btn_delete_username->setText(QApplication::translate("QDialogLogin", "\345\210\240\351\231\244\350\257\245\347\224\250\346\210\267\345\220\215", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class QDialogLogin: public Ui_QDialogLogin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QDIALOGLOGIN_H

/********************************************************************************
** Form generated from reading UI file 'ChatWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHATWIDGET_H
#define UI_CHATWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFontComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QGridLayout *gridLayout;
    QTableWidget *userTableWidget;
    QVBoxLayout *verticalLayout;
    QTextBrowser *messageBrowser;
    QHBoxLayout *horizontalLayout_2;
    QFontComboBox *fontComboBox;
    QHBoxLayout *horizontalLayout;
    QComboBox *sizeComboBox;
    QToolButton *boldToolBtn;
    QToolButton *italicToolBtn;
    QToolButton *underlineToolBtn;
    QToolButton *colorToolBtn;
    QToolButton *sendFileToolBtn;
    QToolButton *saveToolBtn;
    QToolButton *clearToolBtn;
    QTextEdit *messageTextEdit;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *sendButton;
    QSpacerItem *horizontalSpacer;
    QLabel *userNumLabel;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *exitButton;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(984, 680);
        gridLayout = new QGridLayout(Widget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        userTableWidget = new QTableWidget(Widget);
        userTableWidget->setObjectName(QStringLiteral("userTableWidget"));
        userTableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
        userTableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
        userTableWidget->setShowGrid(false);

        gridLayout->addWidget(userTableWidget, 0, 2, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        messageBrowser = new QTextBrowser(Widget);
        messageBrowser->setObjectName(QStringLiteral("messageBrowser"));
        messageBrowser->setMinimumSize(QSize(0, 400));

        verticalLayout->addWidget(messageBrowser);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        fontComboBox = new QFontComboBox(Widget);
        fontComboBox->setObjectName(QStringLiteral("fontComboBox"));

        horizontalLayout_2->addWidget(fontComboBox);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        sizeComboBox = new QComboBox(Widget);
        sizeComboBox->setObjectName(QStringLiteral("sizeComboBox"));

        horizontalLayout->addWidget(sizeComboBox);

        boldToolBtn = new QToolButton(Widget);
        boldToolBtn->setObjectName(QStringLiteral("boldToolBtn"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/images/images/bold.png"), QSize(), QIcon::Normal, QIcon::Off);
        boldToolBtn->setIcon(icon);
        boldToolBtn->setIconSize(QSize(22, 22));
        boldToolBtn->setCheckable(true);
        boldToolBtn->setAutoRaise(true);

        horizontalLayout->addWidget(boldToolBtn);

        italicToolBtn = new QToolButton(Widget);
        italicToolBtn->setObjectName(QStringLiteral("italicToolBtn"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/images/images/italic.png"), QSize(), QIcon::Normal, QIcon::Off);
        italicToolBtn->setIcon(icon1);
        italicToolBtn->setIconSize(QSize(22, 22));
        italicToolBtn->setCheckable(true);
        italicToolBtn->setAutoRaise(true);

        horizontalLayout->addWidget(italicToolBtn);

        underlineToolBtn = new QToolButton(Widget);
        underlineToolBtn->setObjectName(QStringLiteral("underlineToolBtn"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/images/images/under.png"), QSize(), QIcon::Normal, QIcon::Off);
        underlineToolBtn->setIcon(icon2);
        underlineToolBtn->setIconSize(QSize(22, 22));
        underlineToolBtn->setCheckable(true);
        underlineToolBtn->setAutoRaise(true);

        horizontalLayout->addWidget(underlineToolBtn);

        colorToolBtn = new QToolButton(Widget);
        colorToolBtn->setObjectName(QStringLiteral("colorToolBtn"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/images/images/color .png"), QSize(), QIcon::Normal, QIcon::Off);
        colorToolBtn->setIcon(icon3);
        colorToolBtn->setIconSize(QSize(22, 22));
        colorToolBtn->setCheckable(false);
        colorToolBtn->setAutoRaise(true);

        horizontalLayout->addWidget(colorToolBtn);

        sendFileToolBtn = new QToolButton(Widget);
        sendFileToolBtn->setObjectName(QStringLiteral("sendFileToolBtn"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/images/images/send.png"), QSize(), QIcon::Normal, QIcon::Off);
        sendFileToolBtn->setIcon(icon4);
        sendFileToolBtn->setIconSize(QSize(22, 22));
        sendFileToolBtn->setCheckable(false);
        sendFileToolBtn->setAutoRaise(true);

        horizontalLayout->addWidget(sendFileToolBtn);

        saveToolBtn = new QToolButton(Widget);
        saveToolBtn->setObjectName(QStringLiteral("saveToolBtn"));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/images/images/save.png"), QSize(), QIcon::Normal, QIcon::Off);
        saveToolBtn->setIcon(icon5);
        saveToolBtn->setIconSize(QSize(22, 22));
        saveToolBtn->setCheckable(false);
        saveToolBtn->setAutoRaise(true);

        horizontalLayout->addWidget(saveToolBtn);

        clearToolBtn = new QToolButton(Widget);
        clearToolBtn->setObjectName(QStringLiteral("clearToolBtn"));
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/images/images/clear.png"), QSize(), QIcon::Normal, QIcon::Off);
        clearToolBtn->setIcon(icon6);
        clearToolBtn->setIconSize(QSize(22, 22));
        clearToolBtn->setCheckable(false);
        clearToolBtn->setAutoRaise(true);

        horizontalLayout->addWidget(clearToolBtn);


        horizontalLayout_2->addLayout(horizontalLayout);


        verticalLayout->addLayout(horizontalLayout_2);

        messageTextEdit = new QTextEdit(Widget);
        messageTextEdit->setObjectName(QStringLiteral("messageTextEdit"));
        messageTextEdit->setMinimumSize(QSize(0, 0));
        messageTextEdit->setMaximumSize(QSize(4000, 4000));
        messageTextEdit->setBaseSize(QSize(4000, 4000));

        verticalLayout->addWidget(messageTextEdit);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        sendButton = new QPushButton(Widget);
        sendButton->setObjectName(QStringLiteral("sendButton"));
        sendButton->setCheckable(false);
        sendButton->setAutoDefault(false);

        horizontalLayout_3->addWidget(sendButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        userNumLabel = new QLabel(Widget);
        userNumLabel->setObjectName(QStringLiteral("userNumLabel"));

        horizontalLayout_3->addWidget(userNumLabel);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        exitButton = new QPushButton(Widget);
        exitButton->setObjectName(QStringLiteral("exitButton"));

        horizontalLayout_3->addWidget(exitButton);


        verticalLayout->addLayout(horizontalLayout_3);


        gridLayout->addLayout(verticalLayout, 0, 1, 1, 1);


        retranslateUi(Widget);

        sizeComboBox->setCurrentIndex(3);


        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "\345\261\200\345\237\237\347\275\221\350\201\212\345\244\251\347\250\213\345\272\217", Q_NULLPTR));
        sizeComboBox->clear();
        sizeComboBox->insertItems(0, QStringList()
         << QApplication::translate("Widget", "9", Q_NULLPTR)
         << QApplication::translate("Widget", "10", Q_NULLPTR)
         << QApplication::translate("Widget", "11", Q_NULLPTR)
         << QApplication::translate("Widget", "12", Q_NULLPTR)
         << QApplication::translate("Widget", "13", Q_NULLPTR)
         << QApplication::translate("Widget", "14", Q_NULLPTR)
         << QApplication::translate("Widget", "15", Q_NULLPTR)
         << QApplication::translate("Widget", "16", Q_NULLPTR)
         << QApplication::translate("Widget", "17", Q_NULLPTR)
         << QApplication::translate("Widget", "18", Q_NULLPTR)
         << QApplication::translate("Widget", "19", Q_NULLPTR)
         << QApplication::translate("Widget", "20", Q_NULLPTR)
         << QApplication::translate("Widget", "21", Q_NULLPTR)
         << QApplication::translate("Widget", "22", Q_NULLPTR)
        );
#ifndef QT_NO_TOOLTIP
        boldToolBtn->setToolTip(QApplication::translate("Widget", "\345\212\240\347\262\227", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        boldToolBtn->setText(QApplication::translate("Widget", "...", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        italicToolBtn->setToolTip(QApplication::translate("Widget", "\345\200\276\346\226\234", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        italicToolBtn->setText(QApplication::translate("Widget", "...", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        underlineToolBtn->setToolTip(QApplication::translate("Widget", "\344\270\213\345\210\222\347\272\277", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        underlineToolBtn->setText(QApplication::translate("Widget", "...", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        colorToolBtn->setToolTip(QApplication::translate("Widget", "\346\233\264\346\224\271\345\255\227\344\275\223\351\242\234\350\211\262", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        colorToolBtn->setText(QApplication::translate("Widget", "...", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        sendFileToolBtn->setToolTip(QApplication::translate("Widget", "\344\274\240\350\276\223\346\226\207\344\273\266", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        sendFileToolBtn->setText(QApplication::translate("Widget", "...", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        saveToolBtn->setToolTip(QApplication::translate("Widget", "\344\277\235\345\255\230\350\201\212\345\244\251\350\256\260\345\275\225", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        saveToolBtn->setText(QApplication::translate("Widget", "...", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        clearToolBtn->setToolTip(QApplication::translate("Widget", "\346\270\205\347\251\272\350\201\212\345\244\251\350\256\260\345\275\225", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        clearToolBtn->setText(QApplication::translate("Widget", "...", Q_NULLPTR));
        sendButton->setText(QApplication::translate("Widget", "\345\217\221\351\200\201", Q_NULLPTR));
        userNumLabel->setText(QApplication::translate("Widget", "\345\234\250\347\272\277\347\224\250\346\210\267\357\274\2320\344\272\272", Q_NULLPTR));
        exitButton->setText(QApplication::translate("Widget", "\351\200\200\345\207\272", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHATWIDGET_H

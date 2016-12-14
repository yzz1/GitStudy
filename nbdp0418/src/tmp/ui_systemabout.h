/********************************************************************************
** Form generated from reading UI file 'systemabout.ui'
**
** Created: Wed May 4 11:49:56 2016
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SYSTEMABOUT_H
#define UI_SYSTEMABOUT_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QToolButton>
#include <QtGui/QWidget>
#include "widgets/titlewidget.h"

QT_BEGIN_NAMESPACE

class Ui_SystemAbout
{
public:
    QWidget *controlWidget;
    QToolButton *homeTBnt;
    QToolButton *aboutTBtn;
    QToolButton *testTBtn;
    QToolButton *settingTBtn;
    TitleWidget *tiltewidget;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;

    void setupUi(QWidget *SystemAbout)
    {
        if (SystemAbout->objectName().isEmpty())
            SystemAbout->setObjectName(QString::fromUtf8("SystemAbout"));
        SystemAbout->resize(800, 544);
        controlWidget = new QWidget(SystemAbout);
        controlWidget->setObjectName(QString::fromUtf8("controlWidget"));
        controlWidget->setGeometry(QRect(0, 470, 800, 72));
        controlWidget->setAutoFillBackground(false);
        controlWidget->setStyleSheet(QString::fromUtf8(" background-color:rgb(10,21,31);"));
        homeTBnt = new QToolButton(controlWidget);
        homeTBnt->setObjectName(QString::fromUtf8("homeTBnt"));
        homeTBnt->setGeometry(QRect(80, 0, 141, 61));
        homeTBnt->setFocusPolicy(Qt::NoFocus);
        homeTBnt->setStyleSheet(QString::fromUtf8("QToolButton{\n"
"    border:none;\n"
"    outline: none;\n"
"    color:rgb(86, 74, 74);\n"
"     background: transparent;\n"
"	font: 18pt \"Ubuntu\";\n"
"\n"
"}\n"
"QToolButton:focus{\n"
"    color:white;\n"
"\n"
"}\n"
"\n"
""));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/home_normal"), QSize(), QIcon::Normal, QIcon::On);
        icon.addFile(QString::fromUtf8(":/images/home_hover"), QSize(), QIcon::Active, QIcon::On);
        icon.addFile(QString::fromUtf8(":/images/home_normal"), QSize(), QIcon::Selected, QIcon::Off);
        icon.addFile(QString::fromUtf8(":/images/home_hover"), QSize(), QIcon::Selected, QIcon::On);
        homeTBnt->setIcon(icon);
        homeTBnt->setIconSize(QSize(56, 42));
        homeTBnt->setPopupMode(QToolButton::DelayedPopup);
        homeTBnt->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        aboutTBtn = new QToolButton(controlWidget);
        aboutTBtn->setObjectName(QString::fromUtf8("aboutTBtn"));
        aboutTBtn->setGeometry(QRect(650, 0, 131, 61));
        aboutTBtn->setFocusPolicy(Qt::NoFocus);
        aboutTBtn->setStyleSheet(QString::fromUtf8("QToolButton{\n"
"    border:none;\n"
"    outline: none;\n"
"    color:rgb(86, 74, 74);\n"
"     background: transparent;\n"
"	font: 18pt \"Ubuntu\";\n"
"\n"
"}\n"
"QToolButton:focus{\n"
"    color:white;\n"
"\n"
"}\n"
"\n"
""));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/System_AboutBtn_SelYes"), QSize(), QIcon::Normal, QIcon::On);
        aboutTBtn->setIcon(icon1);
        aboutTBtn->setIconSize(QSize(29, 29));
        aboutTBtn->setPopupMode(QToolButton::DelayedPopup);
        aboutTBtn->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        testTBtn = new QToolButton(controlWidget);
        testTBtn->setObjectName(QString::fromUtf8("testTBtn"));
        testTBtn->setGeometry(QRect(510, 0, 111, 61));
        testTBtn->setFocusPolicy(Qt::NoFocus);
        testTBtn->setStyleSheet(QString::fromUtf8("QToolButton{\n"
"    border:none;\n"
"    outline: none;\n"
"    color:rgb(86, 74, 74);\n"
"     background: transparent;\n"
"	font: 18pt \"Ubuntu\";\n"
"    \n"
"}\n"
"QToolButton:focus{\n"
"    color:white;\n"
"\n"
"\n"
"}\n"
"\n"
""));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/images/System_TestBtn_SelNo"), QSize(), QIcon::Normal, QIcon::On);
        testTBtn->setIcon(icon2);
        testTBtn->setIconSize(QSize(29, 29));
        testTBtn->setPopupMode(QToolButton::DelayedPopup);
        testTBtn->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        settingTBtn = new QToolButton(controlWidget);
        settingTBtn->setObjectName(QString::fromUtf8("settingTBtn"));
        settingTBtn->setGeometry(QRect(360, 0, 121, 61));
        settingTBtn->setFocusPolicy(Qt::NoFocus);
        settingTBtn->setStyleSheet(QString::fromUtf8("QToolButton{\n"
"    border:none;\n"
"    outline: none;\n"
"    color:rgb(86, 74, 74);\n"
"     background: transparent;\n"
"	font: 18pt \"Ubuntu\";\n"
"    \n"
"}\n"
"QToolButton:focus{\n"
"    color:white;\n"
"\n"
"}\n"
"\n"
""));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/images/System_SetBtn_SelNo"), QSize(), QIcon::Normal, QIcon::On);
        settingTBtn->setIcon(icon3);
        settingTBtn->setIconSize(QSize(27, 28));
        settingTBtn->setPopupMode(QToolButton::DelayedPopup);
        settingTBtn->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        tiltewidget = new TitleWidget(SystemAbout);
        tiltewidget->setObjectName(QString::fromUtf8("tiltewidget"));
        tiltewidget->setGeometry(QRect(0, 0, 800, 45));
        label = new QLabel(SystemAbout);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(240, 70, 360, 50));
        QFont font;
        font.setFamily(QString::fromUtf8("Ubuntu"));
        font.setPointSize(18);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(7);
        label->setFont(font);
        label->setLayoutDirection(Qt::LeftToRight);
        label->setStyleSheet(QString::fromUtf8("font: 57 18pt \"Ubuntu\";\n"
"color:rgb(105, 115, 119);"));
        label->setAlignment(Qt::AlignCenter);
        label_2 = new QLabel(SystemAbout);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(200, 140, 400, 50));
        label_2->setStyleSheet(QString::fromUtf8("font: 57 18pt \"Ubuntu\";\n"
"color:rgb(105, 115, 119);"));
        label_2->setAlignment(Qt::AlignCenter);
        label_3 = new QLabel(SystemAbout);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(240, 210, 360, 50));
        label_3->setStyleSheet(QString::fromUtf8("font: 57 18pt \"Ubuntu\";\n"
"color:rgb(105, 115, 119);"));
        label_3->setAlignment(Qt::AlignCenter);

        retranslateUi(SystemAbout);

        QMetaObject::connectSlotsByName(SystemAbout);
    } // setupUi

    void retranslateUi(QWidget *SystemAbout)
    {
        SystemAbout->setWindowTitle(QApplication::translate("SystemAbout", "Form", 0, QApplication::UnicodeUTF8));
        homeTBnt->setText(QApplication::translate("SystemAbout", "&Home", 0, QApplication::UnicodeUTF8));
        aboutTBtn->setText(QApplication::translate("SystemAbout", "About", 0, QApplication::UnicodeUTF8));
        testTBtn->setText(QApplication::translate("SystemAbout", "&Test", 0, QApplication::UnicodeUTF8));
        settingTBtn->setText(QApplication::translate("SystemAbout", "&Setting", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("SystemAbout", "TextLabel", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("SystemAbout", "TextLabel", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("SystemAbout", "TextLabel", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class SystemAbout: public Ui_SystemAbout {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SYSTEMABOUT_H

/********************************************************************************
** Form generated from reading UI file 'systemtest.ui'
**
** Created: Wed May 4 11:49:55 2016
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SYSTEMTEST_H
#define UI_SYSTEMTEST_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QHeaderView>
#include <QtGui/QListWidget>
#include <QtGui/QPushButton>
#include <QtGui/QToolButton>
#include <QtGui/QWidget>
#include "widgets/titlewidget.h"

QT_BEGIN_NAMESPACE

class Ui_SystemTest
{
public:
    TitleWidget *tiltewidget;
    QWidget *controlWidget;
    QToolButton *homeTBnt;
    QToolButton *aboutTBtn;
    QToolButton *testTBtn;
    QToolButton *settingTBtn;
    QWidget *widget_7;
    QPushButton *okBtn;
    QPushButton *cancelBtn;
    QListWidget *listWidget;
    QFrame *line_2;

    void setupUi(QWidget *SystemTest)
    {
        if (SystemTest->objectName().isEmpty())
            SystemTest->setObjectName(QString::fromUtf8("SystemTest"));
        SystemTest->resize(800, 544);
        tiltewidget = new TitleWidget(SystemTest);
        tiltewidget->setObjectName(QString::fromUtf8("tiltewidget"));
        tiltewidget->setGeometry(QRect(0, 0, 800, 45));
        controlWidget = new QWidget(SystemTest);
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
        icon1.addFile(QString::fromUtf8(":/images/System_AboutBtn_SelNo"), QSize(), QIcon::Normal, QIcon::On);
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
        icon2.addFile(QString::fromUtf8(":/images/System_TestBtn_SelYes"), QSize(), QIcon::Normal, QIcon::On);
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
        widget_7 = new QWidget(SystemTest);
        widget_7->setObjectName(QString::fromUtf8("widget_7"));
        widget_7->setGeometry(QRect(0, 420, 800, 51));
        okBtn = new QPushButton(widget_7);
        okBtn->setObjectName(QString::fromUtf8("okBtn"));
        okBtn->setGeometry(QRect(110, 0, 101, 31));
        okBtn->setFocusPolicy(Qt::NoFocus);
        okBtn->setStyleSheet(QString::fromUtf8("QPushButton:focus{\n"
"    color:white;\n"
"}\n"
"\n"
""));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/images/images/OK.png"), QSize(), QIcon::Normal, QIcon::Off);
        okBtn->setIcon(icon4);
        cancelBtn = new QPushButton(widget_7);
        cancelBtn->setObjectName(QString::fromUtf8("cancelBtn"));
        cancelBtn->setGeometry(QRect(540, 0, 121, 31));
        cancelBtn->setFocusPolicy(Qt::NoFocus);
        cancelBtn->setStyleSheet(QString::fromUtf8("QPushButton:focus{\n"
"    color:white;\n"
"}\n"
""));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/images/cancel"), QSize(), QIcon::Normal, QIcon::Off);
        cancelBtn->setIcon(icon5);
        listWidget = new QListWidget(SystemTest);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setGeometry(QRect(30, 60, 371, 261));
        QFont font;
        font.setPointSize(15);
        listWidget->setFont(font);
        listWidget->setFocusPolicy(Qt::StrongFocus);
        listWidget->setStyleSheet(QString::fromUtf8("QListWidget {\n"
"    border:none;\n"
"    outline: none;\n"
"    icon-size: 40px;\n"
"    background: transparent;\n"
"    padding-right:20px;\n"
"   color:gray;\n"
"}\n"
"\n"
"QListWidget::item{\n"
"   height:50px;\n"
"}\n"
"\n"
"QListWidget:focus{\n"
"    border:none;\n"
"    outline: none;\n"
"}\n"
"\n"
"QListWidget::item:focus{\n"
"    border:none;\n"
"    outline: none;\n"
"    font: bold 20pt;\n"
"    color:white;\n"
"    background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(48, 60, 76, 255), stop:1 rgba(7, 61, 82, 255));\n"
"}\n"
"\n"
"QListWidget::item:selected{\n"
"    border: none;\n"
"    outline: none;\n"
"    font: bold 20pt;\n"
"    color:white;\n"
"    background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(48, 60, 76, 255), stop:1 rgba(7, 61, 82, 255));\n"
"}\n"
" "));
        line_2 = new QFrame(SystemTest);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setGeometry(QRect(0, 390, 800, 16));
        line_2->setStyleSheet(QString::fromUtf8("background:transparent;"));
        line_2->setFrameShadow(QFrame::Plain);
        line_2->setLineWidth(2);
        line_2->setFrameShape(QFrame::HLine);

        retranslateUi(SystemTest);

        QMetaObject::connectSlotsByName(SystemTest);
    } // setupUi

    void retranslateUi(QWidget *SystemTest)
    {
        SystemTest->setWindowTitle(QApplication::translate("SystemTest", "Form", 0, QApplication::UnicodeUTF8));
        homeTBnt->setText(QApplication::translate("SystemTest", "&Home", 0, QApplication::UnicodeUTF8));
        aboutTBtn->setText(QApplication::translate("SystemTest", "&About", 0, QApplication::UnicodeUTF8));
        testTBtn->setText(QApplication::translate("SystemTest", "Test", 0, QApplication::UnicodeUTF8));
        settingTBtn->setText(QApplication::translate("SystemTest", "&Setting", 0, QApplication::UnicodeUTF8));
        okBtn->setText(QApplication::translate("SystemTest", "&Ok", 0, QApplication::UnicodeUTF8));
        cancelBtn->setText(QApplication::translate("SystemTest", "Ca&ncel", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class SystemTest: public Ui_SystemTest {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SYSTEMTEST_H

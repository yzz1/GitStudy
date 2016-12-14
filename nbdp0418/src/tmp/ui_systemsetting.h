/********************************************************************************
** Form generated from reading UI file 'systemsetting.ui'
**
** Created: Wed May 4 11:49:55 2016
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SYSTEMSETTING_H
#define UI_SYSTEMSETTING_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QListWidget>
#include <QtGui/QPushButton>
#include <QtGui/QScrollBar>
#include <QtGui/QTableWidget>
#include <QtGui/QToolButton>
#include <QtGui/QWidget>
#include "widgets/titlewidget.h"

QT_BEGIN_NAMESPACE

class Ui_SystemSetting
{
public:
    TitleWidget *tiltewidget;
    QLabel *label_7;
    QWidget *controlWidget;
    QToolButton *homeTBnt;
    QToolButton *aboutTBtn;
    QToolButton *testTBtn;
    QToolButton *settingTBtn;
    QWidget *widget;
    QListWidget *listWidget;
    QLabel *languageFocus;
    QLabel *printFocus;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit_4;
    QLineEdit *lineEdit_6;
    QLineEdit *lineEdit_7;
    QLineEdit *lineEdit_8;
    QLineEdit *lineEdit_9;
    QLineEdit *lineEdit_10;
    QLineEdit *lineEdit_11;
    QLineEdit *lineEdit_12;
    QLineEdit *lineEdit_13;
    QLineEdit *lineEdit_14;
    QLineEdit *lineEdit_15;
    QLineEdit *lineEdit_16;
    QLineEdit *lineEdit_17;
    QLineEdit *lineEdit_18;
    QLineEdit *lineEdit_19;
    QLineEdit *lineEdit_20;
    QPushButton *dateTimeButton;
    QWidget *widget_2;
    QComboBox *comboBox;
    QListWidget *listWidget_2;
    QWidget *widget_3;
    QListWidget *listWidget_3;
    QScrollBar *horizontalScrollBar;
    QLabel *horizontalScrollBarFocus;
    QWidget *widget_4;
    QScrollBar *horizontalScrollBar_2;
    QListWidget *listWidget_4;
    QLabel *horizontalScrollBarFocus2;
    QWidget *widget_5;
    QLineEdit *lineEdit_5;
    QListWidget *listWidget_5;
    QLabel *label_8;
    QWidget *widget_6;
    QListWidget *listWidget_6;
    QTableWidget *identificationSetting;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QWidget *widget_7;
    QComboBox *comboBox_2;
    QListWidget *listWidget_7;

    void setupUi(QWidget *SystemSetting)
    {
        if (SystemSetting->objectName().isEmpty())
            SystemSetting->setObjectName(QString::fromUtf8("SystemSetting"));
        SystemSetting->resize(800, 544);
        tiltewidget = new TitleWidget(SystemSetting);
        tiltewidget->setObjectName(QString::fromUtf8("tiltewidget"));
        tiltewidget->setGeometry(QRect(0, 0, 800, 45));
        label_7 = new QLabel(tiltewidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setEnabled(false);
        label_7->setGeometry(QRect(300, 10, 67, 17));
        controlWidget = new QWidget(SystemSetting);
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
"\n"
"}\n"
""));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/images/System_SetBtn_SelYes"), QSize(), QIcon::Normal, QIcon::On);
        settingTBtn->setIcon(icon3);
        settingTBtn->setIconSize(QSize(27, 28));
        settingTBtn->setPopupMode(QToolButton::DelayedPopup);
        settingTBtn->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        widget = new QWidget(SystemSetting);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(0, 50, 800, 40));
        listWidget = new QListWidget(widget);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setEnabled(true);
        listWidget->setGeometry(QRect(40, 0, 212, 40));
        listWidget->setFocusPolicy(Qt::WheelFocus);
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
"    color:rgb(255, 255, 255);\n"
"	font: 57 22pt \"Ubuntu\";\n"
"    background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(48, 60, 76, 255), stop:1 rgba(7, 61, 82, 255));\n"
"}\n"
"\n"
"QListWidget::item:selected{\n"
"    border: none;\n"
"    outline: none;\n"
"    color:rgb(255, 255, 255);\n"
"	font: 57 22pt \"Ubuntu\";\n"
"    background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(48, 60, 76, 255), stop:1 rgba(7, 61, 82, 255));\n"
"}"));
        languageFocus = new QLabel(widget);
        languageFocus->setObjectName(QString::fromUtf8("languageFocus"));
        languageFocus->setGeometry(QRect(150, 10, 67, 17));
        printFocus = new QLabel(widget);
        printFocus->setObjectName(QString::fromUtf8("printFocus"));
        printFocus->setGeometry(QRect(40, 10, 67, 17));
        printFocus->setFocusPolicy(Qt::NoFocus);
        lineEdit = new QLineEdit(widget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(300, 10, 20, 30));
        lineEdit->setFocusPolicy(Qt::NoFocus);
        lineEdit->setStyleSheet(QString::fromUtf8("QLineEdit\n"
"{\n"
"    border:none;\n"
"    outline: none;    \n"
" background: gray;\n"
"    color:white;\n"
"}\n"
"QLineEdit:focus\n"
"{\n"
"\n"
"    color:rgb(0, 0, 0);\n"
"    background-color:white;\n"
"}\n"
"\n"
"QLineEdit:selected{\n"
"    color:rgb(0, 0, 0);\n"
"    background-color:white;\n"
"}\n"
""));
        lineEdit_2 = new QLineEdit(widget);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(320, 10, 20, 30));
        lineEdit_2->setFocusPolicy(Qt::NoFocus);
        lineEdit_2->setStyleSheet(QString::fromUtf8("QLineEdit\n"
"{\n"
"    border:none;\n"
"    outline: none;    \n"
" background: gray;\n"
"    color:white;\n"
"}\n"
"QLineEdit:focus\n"
"{\n"
"\n"
"    color:rgb(0, 0, 0);\n"
"    background-color:white;\n"
"}\n"
"\n"
"QLineEdit:selected{\n"
"    color:rgb(0, 0, 0);\n"
"    background-color:white;\n"
"}\n"
""));
        lineEdit_3 = new QLineEdit(widget);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(340, 10, 20, 30));
        lineEdit_3->setFocusPolicy(Qt::NoFocus);
        lineEdit_3->setStyleSheet(QString::fromUtf8("QLineEdit\n"
"{\n"
"    border:none;\n"
"    outline: none;    \n"
" background: gray;\n"
"    color:white;\n"
"}\n"
"QLineEdit:focus\n"
"{\n"
"\n"
"    color:rgb(0, 0, 0);\n"
"    background-color:white;\n"
"}\n"
"\n"
"QLineEdit:selected{\n"
"    color:rgb(0, 0, 0);\n"
"    background-color:white;\n"
"}\n"
""));
        lineEdit_4 = new QLineEdit(widget);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));
        lineEdit_4->setGeometry(QRect(360, 10, 20, 30));
        lineEdit_4->setFocusPolicy(Qt::NoFocus);
        lineEdit_4->setStyleSheet(QString::fromUtf8("QLineEdit\n"
"{\n"
"    border:none;\n"
"    outline: none;    \n"
" background: gray;\n"
"    color:white;\n"
"}\n"
"QLineEdit:focus\n"
"{\n"
"\n"
"    color:rgb(0, 0, 0);\n"
"    background-color:white;\n"
"}\n"
"\n"
"QLineEdit:selected{\n"
"    color:rgb(0, 0, 0);\n"
"    background-color:white;\n"
"}\n"
""));
        lineEdit_6 = new QLineEdit(widget);
        lineEdit_6->setObjectName(QString::fromUtf8("lineEdit_6"));
        lineEdit_6->setGeometry(QRect(380, 10, 10, 30));
        lineEdit_6->setFocusPolicy(Qt::NoFocus);
        lineEdit_6->setStyleSheet(QString::fromUtf8("QLineEdit\n"
"{\n"
"    border:none;\n"
"    outline: none;    \n"
" background: gray;\n"
"    color:white;\n"
"}\n"
"QLineEdit:focus\n"
"{\n"
"\n"
"    color:rgb(0, 0, 0);\n"
"    background-color:white;\n"
"}\n"
"\n"
"QLineEdit:selected{\n"
"    color:rgb(0, 0, 0);\n"
"    background-color:white;\n"
"}\n"
""));
        lineEdit_7 = new QLineEdit(widget);
        lineEdit_7->setObjectName(QString::fromUtf8("lineEdit_7"));
        lineEdit_7->setGeometry(QRect(390, 10, 20, 30));
        lineEdit_7->setFocusPolicy(Qt::NoFocus);
        lineEdit_7->setStyleSheet(QString::fromUtf8("QLineEdit\n"
"{\n"
"    border:none;\n"
"    outline: none;    \n"
" background: gray;\n"
"    color:white;\n"
"}\n"
"QLineEdit:focus\n"
"{\n"
"\n"
"    color:rgb(0, 0, 0);\n"
"    background-color:white;\n"
"}\n"
"\n"
"QLineEdit:selected{\n"
"    color:rgb(0, 0, 0);\n"
"    background-color:white;\n"
"}\n"
""));
        lineEdit_8 = new QLineEdit(widget);
        lineEdit_8->setObjectName(QString::fromUtf8("lineEdit_8"));
        lineEdit_8->setGeometry(QRect(410, 10, 20, 30));
        lineEdit_8->setFocusPolicy(Qt::NoFocus);
        lineEdit_8->setStyleSheet(QString::fromUtf8("QLineEdit\n"
"{\n"
"    border:none;\n"
"    outline: none;    \n"
" background: gray;\n"
"    color:white;\n"
"}\n"
"QLineEdit:focus\n"
"{\n"
"\n"
"    color:rgb(0, 0, 0);\n"
"    background-color:white;\n"
"}\n"
"\n"
"QLineEdit:selected{\n"
"    color:rgb(0, 0, 0);\n"
"    background-color:white;\n"
"}\n"
""));
        lineEdit_9 = new QLineEdit(widget);
        lineEdit_9->setObjectName(QString::fromUtf8("lineEdit_9"));
        lineEdit_9->setGeometry(QRect(430, 10, 10, 30));
        lineEdit_9->setFocusPolicy(Qt::NoFocus);
        lineEdit_9->setStyleSheet(QString::fromUtf8("QLineEdit\n"
"{\n"
"    border:none;\n"
"    outline: none;    \n"
" background: gray;\n"
"    color:white;\n"
"}\n"
"QLineEdit:focus\n"
"{\n"
"\n"
"    color:rgb(0, 0, 0);\n"
"    background-color:white;\n"
"}\n"
"\n"
"QLineEdit:selected{\n"
"    color:rgb(0, 0, 0);\n"
"    background-color:white;\n"
"}\n"
""));
        lineEdit_10 = new QLineEdit(widget);
        lineEdit_10->setObjectName(QString::fromUtf8("lineEdit_10"));
        lineEdit_10->setGeometry(QRect(440, 10, 20, 30));
        lineEdit_10->setFocusPolicy(Qt::NoFocus);
        lineEdit_10->setStyleSheet(QString::fromUtf8("QLineEdit\n"
"{\n"
"    border:none;\n"
"    outline: none;    \n"
" background: gray;\n"
"    color:white;\n"
"}\n"
"QLineEdit:focus\n"
"{\n"
"\n"
"    color:rgb(0, 0, 0);\n"
"    background-color:white;\n"
"}\n"
"\n"
"QLineEdit:selected{\n"
"    color:rgb(0, 0, 0);\n"
"    background-color:white;\n"
"}\n"
""));
        lineEdit_11 = new QLineEdit(widget);
        lineEdit_11->setObjectName(QString::fromUtf8("lineEdit_11"));
        lineEdit_11->setGeometry(QRect(460, 10, 20, 30));
        lineEdit_11->setFocusPolicy(Qt::NoFocus);
        lineEdit_11->setStyleSheet(QString::fromUtf8("QLineEdit\n"
"{\n"
"    border:none;\n"
"    outline: none;    \n"
" background: gray;\n"
"    color:white;\n"
"}\n"
"QLineEdit:focus\n"
"{\n"
"\n"
"    color:rgb(0, 0, 0);\n"
"    background-color:white;\n"
"}\n"
"\n"
"QLineEdit:selected{\n"
"    color:rgb(0, 0, 0);\n"
"    background-color:white;\n"
"}\n"
""));
        lineEdit_12 = new QLineEdit(widget);
        lineEdit_12->setObjectName(QString::fromUtf8("lineEdit_12"));
        lineEdit_12->setGeometry(QRect(492, 10, 20, 30));
        lineEdit_12->setFocusPolicy(Qt::NoFocus);
        lineEdit_12->setStyleSheet(QString::fromUtf8("QLineEdit\n"
"{\n"
"    border:none;\n"
"    outline: none;    \n"
" background: gray;\n"
"    color:white;\n"
"}\n"
"QLineEdit:focus\n"
"{\n"
"\n"
"    color:rgb(0, 0, 0);\n"
"    background-color:white;\n"
"}\n"
"\n"
"QLineEdit:selected{\n"
"    color:rgb(0, 0, 0);\n"
"    background-color:white;\n"
"}\n"
""));
        lineEdit_13 = new QLineEdit(widget);
        lineEdit_13->setObjectName(QString::fromUtf8("lineEdit_13"));
        lineEdit_13->setGeometry(QRect(512, 10, 20, 30));
        lineEdit_13->setFocusPolicy(Qt::NoFocus);
        lineEdit_13->setStyleSheet(QString::fromUtf8("QLineEdit\n"
"{\n"
"    border:none;\n"
"    outline: none;    \n"
" background: gray;\n"
"    color:white;\n"
"}\n"
"QLineEdit:focus\n"
"{\n"
"\n"
"    color:rgb(0, 0, 0);\n"
"    background-color:white;\n"
"}\n"
"\n"
"QLineEdit:selected{\n"
"    color:rgb(0, 0, 0);\n"
"    background-color:white;\n"
"}\n"
""));
        lineEdit_14 = new QLineEdit(widget);
        lineEdit_14->setObjectName(QString::fromUtf8("lineEdit_14"));
        lineEdit_14->setGeometry(QRect(532, 10, 10, 30));
        lineEdit_14->setFocusPolicy(Qt::NoFocus);
        lineEdit_14->setStyleSheet(QString::fromUtf8("QLineEdit\n"
"{\n"
"    border:none;\n"
"    outline: none;    \n"
" background: gray;\n"
"    color:white;\n"
"}\n"
"QLineEdit:focus\n"
"{\n"
"\n"
"    color:rgb(0, 0, 0);\n"
"    background-color:white;\n"
"}\n"
"\n"
"QLineEdit:selected{\n"
"    color:rgb(0, 0, 0);\n"
"    background-color:white;\n"
"}\n"
""));
        lineEdit_15 = new QLineEdit(widget);
        lineEdit_15->setObjectName(QString::fromUtf8("lineEdit_15"));
        lineEdit_15->setGeometry(QRect(542, 10, 20, 30));
        lineEdit_15->setFocusPolicy(Qt::NoFocus);
        lineEdit_15->setStyleSheet(QString::fromUtf8("QLineEdit\n"
"{\n"
"    border:none;\n"
"    outline: none;    \n"
" background: gray;\n"
"    color:white;\n"
"}\n"
"QLineEdit:focus\n"
"{\n"
"\n"
"    color:rgb(0, 0, 0);\n"
"    background-color:white;\n"
"}\n"
"\n"
"QLineEdit:selected{\n"
"    color:rgb(0, 0, 0);\n"
"    background-color:white;\n"
"}\n"
""));
        lineEdit_16 = new QLineEdit(widget);
        lineEdit_16->setObjectName(QString::fromUtf8("lineEdit_16"));
        lineEdit_16->setGeometry(QRect(562, 10, 20, 30));
        lineEdit_16->setFocusPolicy(Qt::NoFocus);
        lineEdit_16->setStyleSheet(QString::fromUtf8("QLineEdit\n"
"{\n"
"    border:none;\n"
"    outline: none;    \n"
" background: gray;\n"
"    color:white;\n"
"}\n"
"QLineEdit:focus\n"
"{\n"
"\n"
"    color:rgb(0, 0, 0);\n"
"    background-color:white;\n"
"}\n"
"\n"
"QLineEdit:selected{\n"
"    color:rgb(0, 0, 0);\n"
"    background-color:white;\n"
"}\n"
""));
        lineEdit_17 = new QLineEdit(widget);
        lineEdit_17->setObjectName(QString::fromUtf8("lineEdit_17"));
        lineEdit_17->setGeometry(QRect(582, 10, 10, 30));
        lineEdit_17->setFocusPolicy(Qt::NoFocus);
        lineEdit_17->setStyleSheet(QString::fromUtf8("QLineEdit\n"
"{\n"
"    border:none;\n"
"    outline: none;    \n"
" background: gray;\n"
"    color:white;\n"
"}\n"
"QLineEdit:focus\n"
"{\n"
"\n"
"    color:rgb(0, 0, 0);\n"
"    background-color:white;\n"
"}\n"
"\n"
"QLineEdit:selected{\n"
"    color:rgb(0, 0, 0);\n"
"    background-color:white;\n"
"}\n"
""));
        lineEdit_18 = new QLineEdit(widget);
        lineEdit_18->setObjectName(QString::fromUtf8("lineEdit_18"));
        lineEdit_18->setGeometry(QRect(592, 10, 20, 30));
        lineEdit_18->setFocusPolicy(Qt::NoFocus);
        lineEdit_18->setStyleSheet(QString::fromUtf8("QLineEdit\n"
"{\n"
"    border:none;\n"
"    outline: none;    \n"
" background: gray;\n"
"    color:white;\n"
"}\n"
"QLineEdit:focus\n"
"{\n"
"\n"
"    color:rgb(0, 0, 0);\n"
"    background-color:white;\n"
"}\n"
"\n"
"QLineEdit:selected{\n"
"    color:rgb(0, 0, 0);\n"
"    background-color:white;\n"
"}\n"
""));
        lineEdit_19 = new QLineEdit(widget);
        lineEdit_19->setObjectName(QString::fromUtf8("lineEdit_19"));
        lineEdit_19->setGeometry(QRect(612, 10, 20, 30));
        lineEdit_19->setFocusPolicy(Qt::NoFocus);
        lineEdit_19->setStyleSheet(QString::fromUtf8("QLineEdit\n"
"{\n"
"    border:none;\n"
"    outline: none;    \n"
" background: gray;\n"
"    color:white;\n"
"}\n"
"QLineEdit:focus\n"
"{\n"
"\n"
"    color:rgb(0, 0, 0);\n"
"    background-color:white;\n"
"}\n"
"\n"
"QLineEdit:selected{\n"
"    color:rgb(0, 0, 0);\n"
"    background-color:white;\n"
"}\n"
""));
        lineEdit_20 = new QLineEdit(widget);
        lineEdit_20->setObjectName(QString::fromUtf8("lineEdit_20"));
        lineEdit_20->setGeometry(QRect(475, 10, 20, 30));
        lineEdit_20->setFocusPolicy(Qt::NoFocus);
        lineEdit_20->setStyleSheet(QString::fromUtf8("QLineEdit\n"
"{\n"
"    border:none;\n"
"    outline: none;    \n"
" background: gray;\n"
"    color:white;\n"
"}\n"
"QLineEdit:focus\n"
"{\n"
"\n"
"    color:rgb(0, 0, 0);\n"
"    background-color:white;\n"
"}\n"
"\n"
"QLineEdit:selected{\n"
"    color:rgb(0, 0, 0);\n"
"    background-color:white;\n"
"}\n"
""));
        dateTimeButton = new QPushButton(widget);
        dateTimeButton->setObjectName(QString::fromUtf8("dateTimeButton"));
        dateTimeButton->setGeometry(QRect(300, 0, 331, 45));
        dateTimeButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"    border:none;\n"
"    outline: none;\n"
"    icon-size: 40px;\n"
"    background: transparent;\n"
"font: 15pt \"Ubuntu\";\n"
"text-align: left;\n"
"color: rgb(105, 115, 119);\n"
"}\n"
"QPushButton:focus{\n"
"    border:none;\n"
"    outline: none;\n"
"color:white;\n"
"text-align: left;\n"
"    background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(48, 60, 76, 255), stop:1 rgba(7, 61, 82, 255));\n"
"}"));
        widget_2 = new QWidget(SystemSetting);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        widget_2->setGeometry(QRect(0, 100, 800, 40));
        comboBox = new QComboBox(widget_2);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(300, 5, 292, 40));
        comboBox->setFocusPolicy(Qt::NoFocus);
        comboBox->setStyleSheet(QString::fromUtf8("QComboBox{\n"
"border:0px;\n"
"background: transparent;\n"
"font: 14pt \"Ubuntu\";\n"
"color: rgb(105, 115, 119);\n"
"}\n"
"\n"
"QComboBox::down-arrow{image: url(:/images/System_Arrow_Down);}\n"
"QComboBox::drop-down{\n"
"border:0px;\n"
"}\n"
"QComboBox QAbstractItemView::item {\n"
"height:100px;\n"
"margin:10px;\n"
"\n"
"}\n"
"QComboBox QAbstractItemView {\n"
"border:0px;\n"
"outer:0px;\n"
"selection-background-color: rgb(140, 146, 150);\n"
"background-color: rgb(140, 146, 150);\n"
"}\n"
""));
        listWidget_2 = new QListWidget(widget_2);
        listWidget_2->setObjectName(QString::fromUtf8("listWidget_2"));
        listWidget_2->setEnabled(true);
        listWidget_2->setGeometry(QRect(40, 0, 212, 40));
        listWidget_2->setFocusPolicy(Qt::WheelFocus);
        listWidget_2->setStyleSheet(QString::fromUtf8("QListWidget {\n"
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
        widget_3 = new QWidget(SystemSetting);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        widget_3->setGeometry(QRect(0, 150, 800, 40));
        listWidget_3 = new QListWidget(widget_3);
        listWidget_3->setObjectName(QString::fromUtf8("listWidget_3"));
        listWidget_3->setEnabled(true);
        listWidget_3->setGeometry(QRect(40, 0, 212, 40));
        listWidget_3->setFocusPolicy(Qt::WheelFocus);
        listWidget_3->setStyleSheet(QString::fromUtf8("QListWidget {\n"
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
        horizontalScrollBar = new QScrollBar(widget_3);
        horizontalScrollBar->setObjectName(QString::fromUtf8("horizontalScrollBar"));
        horizontalScrollBar->setGeometry(QRect(300, 5, 370, 30));
        horizontalScrollBar->setStyleSheet(QString::fromUtf8("QScrollBar:horizontal\n"
"{\n"
"width:8px;\n"
"background:rgba(0,0,0,50%);\n"
"selection-background:rgba(255, 255, 255, 154);\n"
"margin:1px,1px,1px,1px;\n"
"padding-left:20px;\n"
"padding-right:22px;\n"
"}\n"
"QScrollBar:handle\n"
"{\n"
"    background:qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0.15 rgba(0, 0, 0, 0), stop:0.16 rgba(193, 190, 190, 255), stop:0.845 rgba(134, 125, 125, 255), stop:0.855 rgba(0, 0, 0, 0));\n"
"\n"
"}\n"
"QScrollBar::add-line:horizontal  \n"
"{\n"
"    height:15px;width:15px;\n"
"    border-image:url(:/images/System_Arrow_Right);\n"
"    subcontrol-position:right;\n"
"}\n"
"QScrollBar::sub-line:horizontal   \n"
"{\n"
"    height:15px;width:15px;\n"
"    border-image:url(:/images/System_Arrow_Left);\n"
"    subcontrol-position:left;\n"
"\n"
"}\n"
"QScrollBar::add-page:horizontal\n"
"{\n"
"    background:rgba(0,0,0,0%);\n"
"    border-radius:20px;\n"
"}\n"
"QScrollBar::sub-page:horizontal  \n"
"{\n"
"    background:qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, sto"
                        "p:0.15 rgba(0, 0, 0, 0), stop:0.16 rgba(193, 190, 190, 255), stop:0.845 rgba(134, 125, 125, 255), stop:0.855 rgba(0, 0, 0, 0));\n"
"border-radius:20px;\n"
"}"));
        horizontalScrollBar->setMaximum(100);
        horizontalScrollBar->setOrientation(Qt::Horizontal);
        horizontalScrollBarFocus = new QLabel(widget_3);
        horizontalScrollBarFocus->setObjectName(QString::fromUtf8("horizontalScrollBarFocus"));
        horizontalScrollBarFocus->setGeometry(QRect(680, 10, 67, 17));
        widget_4 = new QWidget(SystemSetting);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));
        widget_4->setGeometry(QRect(0, 200, 800, 40));
        horizontalScrollBar_2 = new QScrollBar(widget_4);
        horizontalScrollBar_2->setObjectName(QString::fromUtf8("horizontalScrollBar_2"));
        horizontalScrollBar_2->setGeometry(QRect(300, 5, 370, 30));
        horizontalScrollBar_2->setStyleSheet(QString::fromUtf8("QScrollBar:horizontal\n"
"{\n"
"width:8px;\n"
"background:rgba(0,0,0,50%);\n"
"margin:1px,1px,1px,1px;\n"
"padding-left:20px;\n"
"padding-right:22px;\n"
"selection-background-color:rgba(255, 255, 255, 154);\n"
"}\n"
"QScrollBar:handle\n"
"{\n"
"    background:qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0.15 rgba(0, 0, 0, 0), stop:0.16 rgba(193, 190, 190, 255), stop:0.845 rgba(134, 125, 125, 255), stop:0.855 rgba(0, 0, 0, 0));\n"
"\n"
"}\n"
"QScrollBar::add-line:horizontal  \n"
"{\n"
"    height:15px;width:15px;\n"
"    border-image:url(:/images/System_Arrow_Right);\n"
"    subcontrol-position:right;\n"
"}\n"
"QScrollBar::sub-line:horizontal   \n"
"{\n"
"    height:15px;width:15px;\n"
"    border-image:url(:/images/System_Arrow_Left);\n"
"    subcontrol-position:left;\n"
"\n"
"}\n"
"QScrollBar::add-page:horizontal\n"
"{\n"
"    background:rgba(0,0,0,0%);\n"
"    border-radius:20px;\n"
"}\n"
"QScrollBar::sub-page:horizontal  \n"
"{\n"
"    background:qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:"
                        "1, stop:0.15 rgba(0, 0, 0, 0), stop:0.16 rgba(193, 190, 190, 255), stop:0.845 rgba(134, 125, 125, 255), stop:0.855 rgba(0, 0, 0, 0));\n"
"border-radius:20px;\n"
"}"));
        horizontalScrollBar_2->setMaximum(127);
        horizontalScrollBar_2->setOrientation(Qt::Horizontal);
        listWidget_4 = new QListWidget(widget_4);
        listWidget_4->setObjectName(QString::fromUtf8("listWidget_4"));
        listWidget_4->setEnabled(true);
        listWidget_4->setGeometry(QRect(40, 0, 212, 40));
        listWidget_4->setFocusPolicy(Qt::WheelFocus);
        listWidget_4->setStyleSheet(QString::fromUtf8("QListWidget {\n"
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
        horizontalScrollBarFocus2 = new QLabel(widget_4);
        horizontalScrollBarFocus2->setObjectName(QString::fromUtf8("horizontalScrollBarFocus2"));
        horizontalScrollBarFocus2->setGeometry(QRect(680, 10, 67, 17));
        horizontalScrollBarFocus2->setFocusPolicy(Qt::NoFocus);
        widget_5 = new QWidget(SystemSetting);
        widget_5->setObjectName(QString::fromUtf8("widget_5"));
        widget_5->setGeometry(QRect(0, 250, 800, 40));
        lineEdit_5 = new QLineEdit(widget_5);
        lineEdit_5->setObjectName(QString::fromUtf8("lineEdit_5"));
        lineEdit_5->setGeometry(QRect(300, 5, 41, 40));
        lineEdit_5->setFocusPolicy(Qt::NoFocus);
        lineEdit_5->setStyleSheet(QString::fromUtf8("QLineEdit\n"
"{\n"
"    border: none;\n"
"font: 14pt \"Ubuntu\";\n"
"text-align: left;\n"
"     background: transparent;\n"
"color: rgb(105, 115, 119);\n"
"}\n"
"QLineEdit:focus\n"
"{\n"
"    border:none;\n"
"    outline: none;\n"
"    font: bold 20pt;\n"
"    color:white;\n"
"text-align: left;\n"
"    background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(48, 60, 76, 255), stop:1 rgba(7, 61, 82, 255));\n"
"}\n"
"\n"
"QLineEdit:selected{\n"
"    border: none;\n"
"    outline: none;\n"
"    font: bold 20pt;\n"
"    color:white;\n"
"    background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(48, 60, 76, 255), stop:1 rgba(7, 61, 82, 255));\n"
"}\n"
""));
        lineEdit_5->setEchoMode(QLineEdit::Normal);
        lineEdit_5->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        lineEdit_5->setDragEnabled(false);
        lineEdit_5->setReadOnly(true);
        listWidget_5 = new QListWidget(widget_5);
        listWidget_5->setObjectName(QString::fromUtf8("listWidget_5"));
        listWidget_5->setEnabled(true);
        listWidget_5->setGeometry(QRect(40, 0, 212, 40));
        listWidget_5->setFocusPolicy(Qt::WheelFocus);
        listWidget_5->setStyleSheet(QString::fromUtf8("QListWidget {\n"
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
        label_8 = new QLabel(widget_5);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(350, 5, 71, 40));
        label_8->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"font: 15pt  \"Ubuntu\";\n"
"color: rgb(105, 115, 119);\n"
"}\n"
"QLabel:focus{\n"
"    border:none;\n"
"    outline: none;\n"
"    font: bold 20pt;\n"
"    color:white;\n"
"    background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(48, 60, 76, 255), stop:1 rgba(7, 61, 82, 255));\n"
"}\n"
"\n"
"QLabel:selected{\n"
"    border: none;\n"
"    outline: none;\n"
"    font: bold 20pt;\n"
"    color:white;\n"
"    background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(48, 60, 76, 255), stop:1 rgba(7, 61, 82, 255));\n"
"}\n"
""));
        widget_6 = new QWidget(SystemSetting);
        widget_6->setObjectName(QString::fromUtf8("widget_6"));
        widget_6->setGeometry(QRect(0, 300, 800, 120));
        listWidget_6 = new QListWidget(widget_6);
        listWidget_6->setObjectName(QString::fromUtf8("listWidget_6"));
        listWidget_6->setEnabled(true);
        listWidget_6->setGeometry(QRect(40, 0, 241, 40));
        listWidget_6->setFocusPolicy(Qt::WheelFocus);
        listWidget_6->setStyleSheet(QString::fromUtf8("QListWidget {\n"
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
        identificationSetting = new QTableWidget(widget_6);
        identificationSetting->setObjectName(QString::fromUtf8("identificationSetting"));
        identificationSetting->setGeometry(QRect(300, 10, 491, 91));
        identificationSetting->setFocusPolicy(Qt::NoFocus);
        identificationSetting->setStyleSheet(QString::fromUtf8("QWidget\n"
"{\n"
"    border:none;\n"
"    outline: none;\n"
"background: transparent;\n"
"}\n"
"QWidget:focus{\n"
"    border:none;\n"
"    outline: none;\n"
"    font: bold 20pt;\n"
"    color:white;\n"
"    background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(48, 60, 76, 255), stop:1 rgba(7, 61, 82, 255));\n"
"}\n"
"\n"
"QWidget:selected{\n"
"    border: none;\n"
"    outline: none;\n"
"    font: bold 20pt;\n"
"    color:white;\n"
"    background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(48, 60, 76, 255), stop:1 rgba(7, 61, 82, 255));\n"
"}\n"
""));
        label = new QLabel(widget_6);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(300, 10, 170, 30));
        label->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"font: 15pt \"Ubuntu\";\n"
"color: rgb(105, 115, 119);\n"
"}\n"
"QLabel:focus{\n"
"    border:none;\n"
"    outline: none;\n"
"    font: bold 20pt;\n"
"    color:white;\n"
"    background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(48, 60, 76, 255), stop:1 rgba(7, 61, 82, 255));\n"
"}\n"
"\n"
"QLabel:selected{\n"
"    border: none;\n"
"    outline: none;\n"
"    font: bold 20pt;\n"
"    color:white;\n"
"    background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(48, 60, 76, 255), stop:1 rgba(7, 61, 82, 255));\n"
"}\n"
""));
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_2 = new QLabel(widget_6);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(300, 40, 170, 30));
        label_2->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"font: 15pt \"Ubuntu\";\n"
"color: rgb(105, 115, 119);\n"
"}\n"
""));
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_3 = new QLabel(widget_6);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(300, 70, 170, 30));
        label_3->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"font: 15pt \"Ubuntu\";\n"
"color: rgb(105, 115, 119);\n"
"}\n"
""));
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_4 = new QLabel(widget_6);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(490, 10, 111, 30));
        label_4->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"font: 15pt  \"Ubuntu\";\n"
"color: rgb(105, 115, 119);\n"
"}\n"
"QLabel:focus{\n"
"    border:none;\n"
"    outline: none;\n"
"    font: bold 20pt;\n"
"    color:white;\n"
"    background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(48, 60, 76, 255), stop:1 rgba(7, 61, 82, 255));\n"
"}\n"
"\n"
"QLabel:selected{\n"
"    border: none;\n"
"    outline: none;\n"
"    font: bold 20pt;\n"
"    color:white;\n"
"    background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(48, 60, 76, 255), stop:1 rgba(7, 61, 82, 255));\n"
"}\n"
""));
        label_5 = new QLabel(widget_6);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(490, 40, 151, 30));
        label_5->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"font: 15pt \"Ubuntu\";\n"
"color: rgb(105, 115, 119);\n"
"}\n"
"QLabel:focus{\n"
"    border:none;\n"
"    outline: none;\n"
"    font: bold 20pt;\n"
"    color:white;\n"
"    background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(48, 60, 76, 255), stop:1 rgba(7, 61, 82, 255));\n"
"}\n"
"\n"
"QLabel:selected{\n"
"    border: none;\n"
"    outline: none;\n"
"    font: bold 20pt;\n"
"    color:white;\n"
"    background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(48, 60, 76, 255), stop:1 rgba(7, 61, 82, 255));\n"
"}\n"
""));
        label_6 = new QLabel(widget_6);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(490, 70, 261, 30));
        label_6->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"font: 15pt \"Ubuntu\";\n"
"color: rgb(105, 115, 119);\n"
"}\n"
"\n"
""));
        widget_7 = new QWidget(SystemSetting);
        widget_7->setObjectName(QString::fromUtf8("widget_7"));
        widget_7->setGeometry(QRect(0, 420, 800, 40));
        comboBox_2 = new QComboBox(widget_7);
        comboBox_2->setObjectName(QString::fromUtf8("comboBox_2"));
        comboBox_2->setGeometry(QRect(300, 5, 292, 40));
        comboBox_2->setFocusPolicy(Qt::NoFocus);
        comboBox_2->setStyleSheet(QString::fromUtf8("QComboBox{\n"
"border:0px;\n"
"background: transparent;\n"
"font: 14pt \"Ubuntu\";\n"
"color: rgb(105, 115, 119);\n"
"}\n"
"\n"
"QComboBox::down-arrow\n"
"{\n"
"image: url(:/images/System_Arrow_Down);\n"
"}\n"
"QComboBox::drop-down\n"
"{\n"
"border:0px;\n"
"}\n"
"QComboBox QAbstractItemView::item\n"
" {\n"
"height:100px;\n"
"margin:10px;\n"
"\n"
"}\n"
"QComboBox QAbstractItemView {\n"
"border:0px;\n"
"outer:0px;\n"
"selection-background-color: rgb(140, 146, 150);\n"
"background-color: rgb(140, 146, 150);\n"
"}\n"
""));
        listWidget_7 = new QListWidget(widget_7);
        listWidget_7->setObjectName(QString::fromUtf8("listWidget_7"));
        listWidget_7->setEnabled(true);
        listWidget_7->setGeometry(QRect(40, 0, 212, 40));
        listWidget_7->setFocusPolicy(Qt::WheelFocus);
        listWidget_7->setStyleSheet(QString::fromUtf8("QListWidget {\n"
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

        retranslateUi(SystemSetting);

        QMetaObject::connectSlotsByName(SystemSetting);
    } // setupUi

    void retranslateUi(QWidget *SystemSetting)
    {
        SystemSetting->setWindowTitle(QApplication::translate("SystemSetting", "Form", 0, QApplication::UnicodeUTF8));
        label_7->setText(QString());
        homeTBnt->setText(QApplication::translate("SystemSetting", "&Home", 0, QApplication::UnicodeUTF8));
        aboutTBtn->setText(QApplication::translate("SystemSetting", "&About", 0, QApplication::UnicodeUTF8));
        testTBtn->setText(QApplication::translate("SystemSetting", "&Test", 0, QApplication::UnicodeUTF8));
        settingTBtn->setText(QApplication::translate("SystemSetting", "Setting", 0, QApplication::UnicodeUTF8));
        languageFocus->setText(QString());
        printFocus->setText(QString());
        lineEdit->setText(QApplication::translate("SystemSetting", "2", 0, QApplication::UnicodeUTF8));
        lineEdit_2->setText(QApplication::translate("SystemSetting", "0", 0, QApplication::UnicodeUTF8));
        lineEdit_3->setText(QApplication::translate("SystemSetting", "1", 0, QApplication::UnicodeUTF8));
        lineEdit_4->setText(QApplication::translate("SystemSetting", "5", 0, QApplication::UnicodeUTF8));
        lineEdit_6->setText(QApplication::translate("SystemSetting", "/", 0, QApplication::UnicodeUTF8));
        lineEdit_7->setText(QApplication::translate("SystemSetting", "1", 0, QApplication::UnicodeUTF8));
        lineEdit_8->setText(QApplication::translate("SystemSetting", "0", 0, QApplication::UnicodeUTF8));
        lineEdit_9->setText(QApplication::translate("SystemSetting", "/", 0, QApplication::UnicodeUTF8));
        lineEdit_10->setText(QApplication::translate("SystemSetting", "2", 0, QApplication::UnicodeUTF8));
        lineEdit_11->setText(QApplication::translate("SystemSetting", "0", 0, QApplication::UnicodeUTF8));
        lineEdit_12->setText(QApplication::translate("SystemSetting", "1", 0, QApplication::UnicodeUTF8));
        lineEdit_13->setText(QApplication::translate("SystemSetting", "6", 0, QApplication::UnicodeUTF8));
        lineEdit_14->setText(QApplication::translate("SystemSetting", ":", 0, QApplication::UnicodeUTF8));
        lineEdit_15->setText(QApplication::translate("SystemSetting", "4", 0, QApplication::UnicodeUTF8));
        lineEdit_16->setText(QApplication::translate("SystemSetting", "0", 0, QApplication::UnicodeUTF8));
        lineEdit_17->setText(QApplication::translate("SystemSetting", ":", 0, QApplication::UnicodeUTF8));
        lineEdit_18->setText(QApplication::translate("SystemSetting", "1", 0, QApplication::UnicodeUTF8));
        lineEdit_19->setText(QApplication::translate("SystemSetting", "1", 0, QApplication::UnicodeUTF8));
        lineEdit_20->setText(QString());
        dateTimeButton->setText(QString());
        horizontalScrollBarFocus->setText(QString());
        lineEdit_5->setText(QApplication::translate("SystemSetting", "10", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("SystemSetting", "msec", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("SystemSetting", "123", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("SystemSetting", "123", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("SystemSetting", "TextLabel", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("SystemSetting", "NULL", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("SystemSetting", "NULL", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("SystemSetting", "NULL", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class SystemSetting: public Ui_SystemSetting {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SYSTEMSETTING_H

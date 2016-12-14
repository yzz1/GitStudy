/********************************************************************************
** Form generated from reading UI file 'scanfrequencyview.ui'
**
** Created: Wed May 4 11:49:56 2016
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SCANFREQUENCYVIEW_H
#define UI_SCANFREQUENCYVIEW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QListWidget>
#include <QtGui/QPushButton>
#include <QtGui/QToolButton>
#include <QtGui/QWidget>
#include "widgets/titlewidget.h"

QT_BEGIN_NAMESPACE

class Ui_ScanFrequencyView
{
public:
    TitleWidget *titleWidget;
    QWidget *controlWidget;
    QToolButton *homeBtn;
    QToolButton *receiveBtn;
    QPushButton *startBnt;
    QPushButton *stopBnt;
    QFrame *Contactsline;
    QListWidget *listWidget;
    QListWidget *listWidget_2;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QPushButton *pushButton;

    void setupUi(QWidget *ScanFrequencyView)
    {
        if (ScanFrequencyView->objectName().isEmpty())
            ScanFrequencyView->setObjectName(QString::fromUtf8("ScanFrequencyView"));
        ScanFrequencyView->resize(800, 544);
        titleWidget = new TitleWidget(ScanFrequencyView);
        titleWidget->setObjectName(QString::fromUtf8("titleWidget"));
        titleWidget->setGeometry(QRect(0, 0, 800, 45));
        controlWidget = new QWidget(ScanFrequencyView);
        controlWidget->setObjectName(QString::fromUtf8("controlWidget"));
        controlWidget->setGeometry(QRect(0, 470, 800, 72));
        controlWidget->setAutoFillBackground(false);
        controlWidget->setStyleSheet(QString::fromUtf8(" background-color:rgb(10,21,31);"));
        homeBtn = new QToolButton(controlWidget);
        homeBtn->setObjectName(QString::fromUtf8("homeBtn"));
        homeBtn->setGeometry(QRect(80, 0, 141, 61));
        homeBtn->setFocusPolicy(Qt::NoFocus);
        homeBtn->setStyleSheet(QString::fromUtf8("QToolButton{\n"
"    border:none;\n"
"    outline: none;\n"
"    color:rgb(86, 74, 74);\n"
"\n"
"     background: transparent;\n"
"        font: 18pt \"Ubuntu\";\n"
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
        icon.addFile(QString::fromUtf8(":/images/home_normal"), QSize(), QIcon::Selected, QIcon::Off);
        icon.addFile(QString::fromUtf8(":/images/home_hover"), QSize(), QIcon::Selected, QIcon::On);
        homeBtn->setIcon(icon);
        homeBtn->setIconSize(QSize(56, 42));
        homeBtn->setPopupMode(QToolButton::DelayedPopup);
        homeBtn->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        receiveBtn = new QToolButton(controlWidget);
        receiveBtn->setObjectName(QString::fromUtf8("receiveBtn"));
        receiveBtn->setGeometry(QRect(610, 0, 141, 61));
        receiveBtn->setFocusPolicy(Qt::NoFocus);
        receiveBtn->setStyleSheet(QString::fromUtf8("QToolButton{\n"
"    border:none;\n"
"    outline: none;\n"
"    color:rgb(86, 74, 74);\n"
"     background: transparent;\n"
"        font: 18pt \"Ubuntu\";\n"
"\n"
"}\n"
"QToolButton:focus{\n"
"    color:white;\n"
"\n"
"}\n"
"\n"
""));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/images/Scan_ICO_SelYes.png"), QSize(), QIcon::Normal, QIcon::On);
        icon1.addFile(QString::fromUtf8(":/images/images/station_gray.png"), QSize(), QIcon::Selected, QIcon::Off);
        icon1.addFile(QString::fromUtf8(":/images/images/individual_white.png"), QSize(), QIcon::Selected, QIcon::On);
        receiveBtn->setIcon(icon1);
        receiveBtn->setIconSize(QSize(40, 40));
        receiveBtn->setPopupMode(QToolButton::DelayedPopup);
        receiveBtn->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        startBnt = new QPushButton(ScanFrequencyView);
        startBnt->setObjectName(QString::fromUtf8("startBnt"));
        startBnt->setGeometry(QRect(590, 420, 64, 36));
        startBnt->setFocusPolicy(Qt::NoFocus);
        startBnt->setAutoFillBackground(false);
        startBnt->setStyleSheet(QString::fromUtf8("QPushButton{    border: none;\n"
"    border-radius:10px;\n"
"        color:rgb(86, 74, 74);\n"
"    border-radius:10px;\n"
"        background-color: rgb(16, 34, 56);\n"
"        font: 18pt \"Ubuntu\";\n"
"}\n"
"QPushButton:focus{\n"
"    color:white;\n"
"}"));
        startBnt->setCheckable(true);
        stopBnt = new QPushButton(ScanFrequencyView);
        stopBnt->setObjectName(QString::fromUtf8("stopBnt"));
        stopBnt->setGeometry(QRect(690, 420, 64, 36));
        stopBnt->setFocusPolicy(Qt::NoFocus);
        stopBnt->setAutoFillBackground(false);
        stopBnt->setStyleSheet(QString::fromUtf8("QPushButton{    border: none;\n"
"    border-radius:10px;\n"
"        color:rgb(86, 74, 74);\n"
"    border-radius:10px;\n"
"        background-color: rgb(16, 34, 56);\n"
"        font: 18pt \"Ubuntu\";\n"
"}\n"
"QPushButton:focus{\n"
"    color:white;\n"
"}"));
        stopBnt->setCheckable(true);
        Contactsline = new QFrame(ScanFrequencyView);
        Contactsline->setObjectName(QString::fromUtf8("Contactsline"));
        Contactsline->setGeometry(QRect(0, 410, 800, 5));
        Contactsline->setFrameShape(QFrame::HLine);
        Contactsline->setFrameShadow(QFrame::Sunken);
        listWidget = new QListWidget(ScanFrequencyView);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setGeometry(QRect(95, 99, 330, 301));
        listWidget->setStyleSheet(QString::fromUtf8("QListWidget {\n"
"    border:none;\n"
"    outline: none;\n"
"    background: transparent;\n"
"    padding-right:30px;\n"
"   color:gray;\n"
"}\n"
"\n"
"QListWidget::item{\n"
"   height:30px;\n"
"    font: bold 20pt;\n"
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
"    font: bold 17pt;\n"
"    color:white;\n"
"    background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(48, 60, 76, 255), stop:1 rgba(7, 61, 82, 255));\n"
"}\n"
"\n"
"QListWidget::item:selected{\n"
"    border: none;\n"
"    outline: none;\n"
"    font: bold 17pt;\n"
"    color:white;\n"
"    background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(48, 60, 76, 255), stop:1 rgba(7, 61, 82, 255));\n"
"}"));
        listWidget_2 = new QListWidget(ScanFrequencyView);
        listWidget_2->setObjectName(QString::fromUtf8("listWidget_2"));
        listWidget_2->setGeometry(QRect(440, 99, 330, 301));
        listWidget_2->setStyleSheet(QString::fromUtf8("QListWidget {\n"
"    border:none;\n"
"    outline: none;\n"
"    background: transparent;\n"
"    padding-right:30px;\n"
"   color:gray;\n"
"}\n"
"\n"
"QListWidget::item{\n"
"   height:30px;\n"
"    font: bold 20pt;\n"
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
"    font: bold 17pt;\n"
"    color:white;\n"
"    background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(48, 60, 76, 255), stop:1 rgba(7, 61, 82, 255));\n"
"}\n"
"\n"
"QListWidget::item:selected{\n"
"    border: none;\n"
"    outline: none;\n"
"    font: bold 17pt;\n"
"    color:white;\n"
"    background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(48, 60, 76, 255), stop:1 rgba(7, 61, 82, 255));\n"
"}"));
        label = new QLabel(ScanFrequencyView);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(100, 60, 67, 21));
        label->setStyleSheet(QString::fromUtf8("font: 57 20pt \"Ubuntu\";\n"
"        color: rgb(217, 215, 215);"));
        label_2 = new QLabel(ScanFrequencyView);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(220, 60, 67, 21));
        label_2->setStyleSheet(QString::fromUtf8("font: 57 20pt \"Ubuntu\";\n"
"        color: rgb(217, 215, 215);"));
        label_3 = new QLabel(ScanFrequencyView);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(320, 60, 67, 21));
        label_3->setStyleSheet(QString::fromUtf8("font: 57 20pt \"Ubuntu\";\n"
"        color: rgb(217, 215, 215);"));
        label_4 = new QLabel(ScanFrequencyView);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(450, 60, 67, 21));
        label_4->setStyleSheet(QString::fromUtf8("font: 57 20pt \"Ubuntu\";\n"
"         color: rgb(217, 215, 215);"));
        label_5 = new QLabel(ScanFrequencyView);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(570, 60, 67, 21));
        label_5->setStyleSheet(QString::fromUtf8("font: 57 20pt \"Ubuntu\";\n"
"        color: rgb(217, 215, 215);"));
        label_6 = new QLabel(ScanFrequencyView);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(660, 60, 67, 21));
        label_6->setStyleSheet(QString::fromUtf8("font: 57 20pt \"Ubuntu\";\n"
"         color: rgb(217, 215, 215);"));
        pushButton = new QPushButton(ScanFrequencyView);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(330, 110, 98, 27));

        retranslateUi(ScanFrequencyView);

        QMetaObject::connectSlotsByName(ScanFrequencyView);
    } // setupUi

    void retranslateUi(QWidget *ScanFrequencyView)
    {
        ScanFrequencyView->setWindowTitle(QApplication::translate("ScanFrequencyView", "Form", 0, QApplication::UnicodeUTF8));
        homeBtn->setText(QApplication::translate("ScanFrequencyView", "&Home", 0, QApplication::UnicodeUTF8));
        receiveBtn->setText(QApplication::translate("ScanFrequencyView", "Scan", 0, QApplication::UnicodeUTF8));
        startBnt->setText(QApplication::translate("ScanFrequencyView", "&Start", 0, QApplication::UnicodeUTF8));
        stopBnt->setText(QApplication::translate("ScanFrequencyView", "S&top", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("ScanFrequencyView", "NO.", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("ScanFrequencyView", "Tx", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("ScanFrequencyView", "Rx", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("ScanFrequencyView", "NO.", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("ScanFrequencyView", "Tx", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("ScanFrequencyView", "Rx", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("ScanFrequencyView", "PushButton", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ScanFrequencyView: public Ui_ScanFrequencyView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SCANFREQUENCYVIEW_H

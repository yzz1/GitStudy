/********************************************************************************
** Form generated from reading UI file 'individualselectview.ui'
**
** Created: Wed May 4 11:49:55 2016
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INDIVIDUALSELECTVIEW_H
#define UI_INDIVIDUALSELECTVIEW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QTableView>
#include <QtGui/QToolButton>
#include <QtGui/QWidget>
#include "widgets/titlewidget.h"

QT_BEGIN_NAMESPACE

class Ui_IndividualSelectView
{
public:
    QPushButton *cancelBtn;
    QPushButton *arrowUpButton;
    QLabel *callcodeLabel;
    QLabel *nameLabel;
    TitleWidget *tiltewidget;
    QPushButton *okBtn;
    QPushButton *arrowDownButton;
    QTableView *tableView;
    QWidget *controlWidget;
    QToolButton *homeBtn;
    QToolButton *receiveBtn;
    QToolButton *callBtn;
    QFrame *Contactsline;

    void setupUi(QWidget *IndividualSelectView)
    {
        if (IndividualSelectView->objectName().isEmpty())
            IndividualSelectView->setObjectName(QString::fromUtf8("IndividualSelectView"));
        IndividualSelectView->resize(800, 544);
        cancelBtn = new QPushButton(IndividualSelectView);
        cancelBtn->setObjectName(QString::fromUtf8("cancelBtn"));
        cancelBtn->setGeometry(QRect(500, 420, 99, 30));
        cancelBtn->setFocusPolicy(Qt::NoFocus);
        cancelBtn->setStyleSheet(QString::fromUtf8("QPushButton:focus{\n"
"    color:white;\n"
"}\n"
"\n"
""));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/cancel"), QSize(), QIcon::Normal, QIcon::Off);
        cancelBtn->setIcon(icon);
        arrowUpButton = new QPushButton(IndividualSelectView);
        arrowUpButton->setObjectName(QString::fromUtf8("arrowUpButton"));
        arrowUpButton->setGeometry(QRect(370, 390, 30, 15));
        arrowUpButton->setFocusPolicy(Qt::NoFocus);
        arrowUpButton->setAutoFillBackground(false);
        arrowUpButton->setStyleSheet(QString::fromUtf8("    border: none;\n"
"background-image: url(:/images/Arrow_up_gray);\n"
"selection-background-color: url(:/images/Arrow_up_white);"));
        callcodeLabel = new QLabel(IndividualSelectView);
        callcodeLabel->setObjectName(QString::fromUtf8("callcodeLabel"));
        callcodeLabel->setGeometry(QRect(520, 50, 144, 61));
        callcodeLabel->setStyleSheet(QString::fromUtf8("background-image: url(:/images/Ellipse_144_61);\n"
"font: 20pt \"Ubuntu\";\n"
"color: rgb(183, 183, 183);"));
        callcodeLabel->setAlignment(Qt::AlignCenter);
        nameLabel = new QLabel(IndividualSelectView);
        nameLabel->setObjectName(QString::fromUtf8("nameLabel"));
        nameLabel->setGeometry(QRect(60, 50, 144, 61));
        nameLabel->setStyleSheet(QString::fromUtf8("background-image: url(:/images/Ellipse_144_61);\n"
"font: 20pt \"Ubuntu\";\n"
"color: rgb(183, 183, 183);"));
        nameLabel->setAlignment(Qt::AlignCenter);
        tiltewidget = new TitleWidget(IndividualSelectView);
        tiltewidget->setObjectName(QString::fromUtf8("tiltewidget"));
        tiltewidget->setGeometry(QRect(0, 9, 800, 45));
        okBtn = new QPushButton(IndividualSelectView);
        okBtn->setObjectName(QString::fromUtf8("okBtn"));
        okBtn->setGeometry(QRect(160, 420, 99, 30));
        okBtn->setFocusPolicy(Qt::NoFocus);
        okBtn->setStyleSheet(QString::fromUtf8("QPushButton:focus{\n"
"    color:white;\n"
"}\n"
"\n"
""));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/images/OK.png"), QSize(), QIcon::Normal, QIcon::Off);
        okBtn->setIcon(icon1);
        arrowDownButton = new QPushButton(IndividualSelectView);
        arrowDownButton->setObjectName(QString::fromUtf8("arrowDownButton"));
        arrowDownButton->setGeometry(QRect(450, 390, 30, 15));
        arrowDownButton->setFocusPolicy(Qt::NoFocus);
        arrowDownButton->setAutoFillBackground(false);
        arrowDownButton->setStyleSheet(QString::fromUtf8("    border: none;\n"
"background-image: url(:/images/Arrow_down_gray);\n"
"selection-background-color: url(:/images/Arrow_down_white);"));
        tableView = new QTableView(IndividualSelectView);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setGeometry(QRect(0, 110, 800, 281));
        tableView->setFocusPolicy(Qt::StrongFocus);
        tableView->setStyleSheet(QString::fromUtf8(" color: gray;\n"
"background: transparent;\n"
"selection-background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(48, 60, 76, 255), stop:1 rgba(7, 61, 82, 255));\n"
"selection-color: rgb(255, 255, 255);\n"
"font: 16pt \"Ubuntu\";\n"
"    border:none;\n"
""));
        tableView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableView->setAutoScroll(true);
        tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableView->setTabKeyNavigation(false);
        tableView->setShowGrid(false);
        tableView->setWordWrap(true);
        tableView->horizontalHeader()->setVisible(false);
        tableView->verticalHeader()->setDefaultSectionSize(40);
        controlWidget = new QWidget(IndividualSelectView);
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
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/images/home_normal"), QSize(), QIcon::Normal, QIcon::On);
        icon2.addFile(QString::fromUtf8(":/images/home_normal"), QSize(), QIcon::Selected, QIcon::Off);
        icon2.addFile(QString::fromUtf8(":/images/home_hover"), QSize(), QIcon::Selected, QIcon::On);
        homeBtn->setIcon(icon2);
        homeBtn->setIconSize(QSize(56, 42));
        homeBtn->setPopupMode(QToolButton::DelayedPopup);
        homeBtn->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        receiveBtn = new QToolButton(controlWidget);
        receiveBtn->setObjectName(QString::fromUtf8("receiveBtn"));
        receiveBtn->setGeometry(QRect(640, 0, 141, 61));
        receiveBtn->setFocusPolicy(Qt::NoFocus);
        receiveBtn->setStyleSheet(QString::fromUtf8("QToolButton{\n"
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
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/images/images/Receive_Bnt_SelNo.png"), QSize(), QIcon::Normal, QIcon::On);
        icon3.addFile(QString::fromUtf8(":/images/images/station_gray.png"), QSize(), QIcon::Selected, QIcon::Off);
        icon3.addFile(QString::fromUtf8(":/images/images/individual_white.png"), QSize(), QIcon::Selected, QIcon::On);
        receiveBtn->setIcon(icon3);
        receiveBtn->setIconSize(QSize(40, 40));
        receiveBtn->setPopupMode(QToolButton::DelayedPopup);
        receiveBtn->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        callBtn = new QToolButton(controlWidget);
        callBtn->setObjectName(QString::fromUtf8("callBtn"));
        callBtn->setGeometry(QRect(450, 0, 145, 61));
        callBtn->setFocusPolicy(Qt::NoFocus);
        callBtn->setStyleSheet(QString::fromUtf8("QToolButton{\n"
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
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/images/images/Call_Bnt_SelNo.png"), QSize(), QIcon::Normal, QIcon::On);
        icon4.addFile(QString::fromUtf8(":/images/images/individual_gray.png"), QSize(), QIcon::Selected, QIcon::Off);
        icon4.addFile(QString::fromUtf8(":/images/images/individual_white.png"), QSize(), QIcon::Selected, QIcon::On);
        callBtn->setIcon(icon4);
        callBtn->setIconSize(QSize(40, 40));
        callBtn->setPopupMode(QToolButton::DelayedPopup);
        callBtn->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        Contactsline = new QFrame(IndividualSelectView);
        Contactsline->setObjectName(QString::fromUtf8("Contactsline"));
        Contactsline->setGeometry(QRect(0, 410, 800, 5));
        Contactsline->setFrameShape(QFrame::HLine);
        Contactsline->setFrameShadow(QFrame::Sunken);

        retranslateUi(IndividualSelectView);

        QMetaObject::connectSlotsByName(IndividualSelectView);
    } // setupUi

    void retranslateUi(QWidget *IndividualSelectView)
    {
        IndividualSelectView->setWindowTitle(QApplication::translate("IndividualSelectView", "Form", 0, QApplication::UnicodeUTF8));
        cancelBtn->setText(QApplication::translate("IndividualSelectView", "Ca&ncel", 0, QApplication::UnicodeUTF8));
        arrowUpButton->setText(QString());
        callcodeLabel->setText(QApplication::translate("IndividualSelectView", "Callcode", 0, QApplication::UnicodeUTF8));
        nameLabel->setText(QApplication::translate("IndividualSelectView", "Name", 0, QApplication::UnicodeUTF8));
        okBtn->setText(QApplication::translate("IndividualSelectView", "&OK", 0, QApplication::UnicodeUTF8));
        arrowDownButton->setText(QString());
        homeBtn->setText(QApplication::translate("IndividualSelectView", "&Home", 0, QApplication::UnicodeUTF8));
        receiveBtn->setText(QApplication::translate("IndividualSelectView", "&Receive", 0, QApplication::UnicodeUTF8));
        callBtn->setText(QApplication::translate("IndividualSelectView", "&Transmit", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class IndividualSelectView: public Ui_IndividualSelectView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INDIVIDUALSELECTVIEW_H

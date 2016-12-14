/********************************************************************************
** Form generated from reading UI file 'contactsindview.ui'
**
** Created: Wed May 4 11:49:55 2016
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONTACTSINDVIEW_H
#define UI_CONTACTSINDVIEW_H

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

class Ui_ContactsIndView
{
public:
    QPushButton *editBnt;
    QPushButton *deleteBnt;
    QPushButton *optionBnt;
    QPushButton *contactsCancelBnt;
    QLabel *nameLabel;
    QLabel *callcodeLabel;
    QFrame *Contactsline;
    QPushButton *arrowUpButton;
    QPushButton *arrowDownButton;
    TitleWidget *contactsTiltewidget;
    QTableView *tableView;
    QPushButton *exportBnt;
    QPushButton *importBnt;
    QPushButton *printBnt;
    QWidget *controlWidget;
    QToolButton *homeTBnt;
    QToolButton *stationTBnt;
    QToolButton *individualTBnt;
    QPushButton *newBnt;

    void setupUi(QWidget *ContactsIndView)
    {
        if (ContactsIndView->objectName().isEmpty())
            ContactsIndView->setObjectName(QString::fromUtf8("ContactsIndView"));
        ContactsIndView->resize(800, 544);
        ContactsIndView->setStyleSheet(QString::fromUtf8(""));
        editBnt = new QPushButton(ContactsIndView);
        editBnt->setObjectName(QString::fromUtf8("editBnt"));
        editBnt->setGeometry(QRect(110, 420, 64, 36));
        editBnt->setFocusPolicy(Qt::NoFocus);
        editBnt->setAutoFillBackground(false);
        editBnt->setStyleSheet(QString::fromUtf8("QPushButton{    border: none;\n"
"    border-radius:10px;\n"
"	color:rgb(86, 74, 74);\n"
"    border-radius:10px;\n"
"	background-color: rgb(16, 34, 56);\n"
"	font: 18pt \"Ubuntu\";\n"
"}\n"
"QPushButton:focus{\n"
"    color:white;\n"
"}"));
        editBnt->setCheckable(true);
        deleteBnt = new QPushButton(ContactsIndView);
        deleteBnt->setObjectName(QString::fromUtf8("deleteBnt"));
        deleteBnt->setGeometry(QRect(190, 420, 85, 36));
        deleteBnt->setFocusPolicy(Qt::NoFocus);
        deleteBnt->setAutoFillBackground(false);
        deleteBnt->setStyleSheet(QString::fromUtf8("QPushButton{    border: none;\n"
"    border-radius:10px;\n"
"	color:rgb(86, 74, 74);\n"
"    border-radius:10px;\n"
"	background-color: rgb(16, 34, 56);\n"
"	font: 18pt \"Ubuntu\";\n"
"}\n"
"QPushButton:focus{\n"
"    color:white;\n"
"}"));
        deleteBnt->setCheckable(true);
        optionBnt = new QPushButton(ContactsIndView);
        optionBnt->setObjectName(QString::fromUtf8("optionBnt"));
        optionBnt->setGeometry(QRect(550, 420, 105, 36));
        optionBnt->setFocusPolicy(Qt::NoFocus);
        optionBnt->setAutoFillBackground(false);
        optionBnt->setStyleSheet(QString::fromUtf8("QPushButton{    border: none;\n"
"    border-radius:10px;\n"
"	color:rgb(86, 74, 74);\n"
"    border-radius:10px;\n"
"	background-color: rgb(16, 34, 56);\n"
"	font: 18pt \"Ubuntu\";\n"
"}\n"
"QPushButton:focus{\n"
"    color:white;\n"
"}"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/optionLeft"), QSize(), QIcon::Normal, QIcon::Off);
        optionBnt->setIcon(icon);
        optionBnt->setCheckable(true);
        contactsCancelBnt = new QPushButton(ContactsIndView);
        contactsCancelBnt->setObjectName(QString::fromUtf8("contactsCancelBnt"));
        contactsCancelBnt->setGeometry(QRect(670, 420, 105, 36));
        contactsCancelBnt->setFocusPolicy(Qt::NoFocus);
        contactsCancelBnt->setAutoFillBackground(false);
        contactsCancelBnt->setStyleSheet(QString::fromUtf8("QPushButton{    border: none;\n"
"    border-radius:10px;\n"
"	color:rgb(86, 74, 74);\n"
"    border-radius:10px;\n"
"	background-color: rgb(16, 34, 56);\n"
"	font: 18pt \"Ubuntu\";\n"
"}\n"
"QPushButton:focus{\n"
"    color:white;\n"
"}"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/cancel"), QSize(), QIcon::Normal, QIcon::Off);
        contactsCancelBnt->setIcon(icon1);
        contactsCancelBnt->setCheckable(true);
        nameLabel = new QLabel(ContactsIndView);
        nameLabel->setObjectName(QString::fromUtf8("nameLabel"));
        nameLabel->setGeometry(QRect(60, 50, 144, 61));
        nameLabel->setStyleSheet(QString::fromUtf8("background-image: url(:/images/Ellipse_144_61);\n"
"font: 20pt \"Ubuntu\";\n"
"color: rgb(183, 183, 183);"));
        nameLabel->setAlignment(Qt::AlignCenter);
        callcodeLabel = new QLabel(ContactsIndView);
        callcodeLabel->setObjectName(QString::fromUtf8("callcodeLabel"));
        callcodeLabel->setGeometry(QRect(520, 50, 144, 61));
        callcodeLabel->setStyleSheet(QString::fromUtf8("background-image: url(:/images/Ellipse_144_61);\n"
"font: 20pt \"Ubuntu\";\n"
"color: rgb(183, 183, 183);"));
        callcodeLabel->setAlignment(Qt::AlignCenter);
        Contactsline = new QFrame(ContactsIndView);
        Contactsline->setObjectName(QString::fromUtf8("Contactsline"));
        Contactsline->setGeometry(QRect(0, 410, 800, 5));
        Contactsline->setFrameShape(QFrame::HLine);
        Contactsline->setFrameShadow(QFrame::Sunken);
        arrowUpButton = new QPushButton(ContactsIndView);
        arrowUpButton->setObjectName(QString::fromUtf8("arrowUpButton"));
        arrowUpButton->setGeometry(QRect(370, 390, 30, 15));
        arrowUpButton->setFocusPolicy(Qt::NoFocus);
        arrowUpButton->setAutoFillBackground(false);
        arrowUpButton->setStyleSheet(QString::fromUtf8("    border: none;\n"
"background-image: url(:/images/Arrow_up_gray);\n"
"selection-background-color: url(:/images/Arrow_up_white);"));
        arrowDownButton = new QPushButton(ContactsIndView);
        arrowDownButton->setObjectName(QString::fromUtf8("arrowDownButton"));
        arrowDownButton->setGeometry(QRect(450, 390, 30, 15));
        arrowDownButton->setFocusPolicy(Qt::NoFocus);
        arrowDownButton->setAutoFillBackground(false);
        arrowDownButton->setStyleSheet(QString::fromUtf8("    border: none;\n"
"background-image: url(:/images/Arrow_down_gray);\n"
"selection-background-color: url(:/images/Arrow_down_white);"));
        contactsTiltewidget = new TitleWidget(ContactsIndView);
        contactsTiltewidget->setObjectName(QString::fromUtf8("contactsTiltewidget"));
        contactsTiltewidget->setGeometry(QRect(0, 9, 800, 45));
        tableView = new QTableView(ContactsIndView);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setGeometry(QRect(0, 110, 800, 281));
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
        exportBnt = new QPushButton(ContactsIndView);
        exportBnt->setObjectName(QString::fromUtf8("exportBnt"));
        exportBnt->setGeometry(QRect(480, 320, 71, 45));
        QFont font;
        font.setFamily(QString::fromUtf8("Ubuntu"));
        font.setPointSize(14);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        exportBnt->setFont(font);
        exportBnt->setFocusPolicy(Qt::NoFocus);
        exportBnt->setStyleSheet(QString::fromUtf8("QPushButton{    border: none;\n"
"	color: rgb(105, 115, 119);\n"
"	background-color:rgb(65, 85, 100);\n"
"	font: 14pt \"Ubuntu\";\n"
"   text-align:left;\n"
"}\n"
"QPushButton:focus{\n"
"    color:rgb(255, 255, 255);\n"
"	background-color: rgb(16, 34, 56);\n"
"}"));
        importBnt = new QPushButton(ContactsIndView);
        importBnt->setObjectName(QString::fromUtf8("importBnt"));
        importBnt->setGeometry(QRect(480, 365, 71, 45));
        importBnt->setFont(font);
        importBnt->setFocusPolicy(Qt::NoFocus);
        importBnt->setStyleSheet(QString::fromUtf8("QPushButton{    border: none;\n"
"	color: rgb(105, 115, 119);\n"
"	background-color:rgb(65, 85, 100);\n"
"	font: 14pt \"Ubuntu\";\n"
"   text-align:left;\n"
"}\n"
"QPushButton:focus{\n"
"    color:rgb(255, 255, 255);\n"
"	background-color: rgb(16, 34, 56);\n"
"}"));
        importBnt->setCheckable(true);
        printBnt = new QPushButton(ContactsIndView);
        printBnt->setObjectName(QString::fromUtf8("printBnt"));
        printBnt->setGeometry(QRect(480, 410, 71, 45));
        printBnt->setFont(font);
        printBnt->setFocusPolicy(Qt::NoFocus);
        printBnt->setStyleSheet(QString::fromUtf8("QPushButton{    border: none;\n"
"	color: rgb(105, 115, 119);\n"
"	background-color:rgb(65, 85, 100);\n"
"	font: 14pt \"Ubuntu\";\n"
"   text-align:left;\n"
"}\n"
"QPushButton:focus{\n"
"    color:rgb(255, 255, 255);\n"
"	background-color: rgb(16, 34, 56);\n"
"}"));
        printBnt->setCheckable(true);
        controlWidget = new QWidget(ContactsIndView);
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
"\n"
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
        homeTBnt->setIcon(icon2);
        homeTBnt->setIconSize(QSize(56, 42));
        homeTBnt->setPopupMode(QToolButton::DelayedPopup);
        homeTBnt->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        stationTBnt = new QToolButton(controlWidget);
        stationTBnt->setObjectName(QString::fromUtf8("stationTBnt"));
        stationTBnt->setGeometry(QRect(663, 0, 111, 61));
        stationTBnt->setFocusPolicy(Qt::NoFocus);
        stationTBnt->setStyleSheet(QString::fromUtf8("QToolButton{\n"
"    border:none;\n"
"    outline: none;\n"
"    color:rgb(86, 74, 74);\n"
"\n"
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
        icon3.addFile(QString::fromUtf8(":/images/images/station_gray.png"), QSize(), QIcon::Normal, QIcon::On);
        icon3.addFile(QString::fromUtf8(":/images/images/station_gray.png"), QSize(), QIcon::Selected, QIcon::Off);
        icon3.addFile(QString::fromUtf8(":/images/images/individual_white.png"), QSize(), QIcon::Selected, QIcon::On);
        stationTBnt->setIcon(icon3);
        stationTBnt->setIconSize(QSize(18, 31));
        stationTBnt->setPopupMode(QToolButton::DelayedPopup);
        stationTBnt->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        individualTBnt = new QToolButton(controlWidget);
        individualTBnt->setObjectName(QString::fromUtf8("individualTBnt"));
        individualTBnt->setEnabled(false);
        individualTBnt->setGeometry(QRect(450, 0, 145, 61));
        individualTBnt->setFocusPolicy(Qt::NoFocus);
        individualTBnt->setStyleSheet(QString::fromUtf8("QToolButton{\n"
"    border:none;\n"
"    outline: none;\n"
"    color:rgb(86, 74, 74);\n"
"\n"
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
        icon4.addFile(QString::fromUtf8(":/images/images/individual_white.png"), QSize(), QIcon::Normal, QIcon::On);
        icon4.addFile(QString::fromUtf8(":/images/images/name_green.png"), QSize(), QIcon::Disabled, QIcon::On);
        icon4.addFile(QString::fromUtf8(":/images/images/individual_gray.png"), QSize(), QIcon::Selected, QIcon::Off);
        icon4.addFile(QString::fromUtf8(":/images/images/individual_white.png"), QSize(), QIcon::Selected, QIcon::On);
        individualTBnt->setIcon(icon4);
        individualTBnt->setIconSize(QSize(25, 31));
        individualTBnt->setPopupMode(QToolButton::DelayedPopup);
        individualTBnt->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        newBnt = new QPushButton(ContactsIndView);
        newBnt->setObjectName(QString::fromUtf8("newBnt"));
        newBnt->setGeometry(QRect(30, 420, 64, 36));
        newBnt->setFocusPolicy(Qt::NoFocus);
        newBnt->setAutoFillBackground(false);
        newBnt->setStyleSheet(QString::fromUtf8("QPushButton{    border: none;\n"
"    border-radius:10px;\n"
"	color:rgb(86, 74, 74);\n"
"    border-radius:10px;\n"
"	background-color: rgb(16, 34, 56);\n"
"	font: 18pt \"Ubuntu\";\n"
"}\n"
"QPushButton:focus{\n"
"    color:white;\n"
"}"));
        newBnt->setCheckable(true);

        retranslateUi(ContactsIndView);

        QMetaObject::connectSlotsByName(ContactsIndView);
    } // setupUi

    void retranslateUi(QWidget *ContactsIndView)
    {
        ContactsIndView->setWindowTitle(QApplication::translate("ContactsIndView", "Form", 0, QApplication::UnicodeUTF8));
        editBnt->setText(QApplication::translate("ContactsIndView", "&Edit", 0, QApplication::UnicodeUTF8));
        deleteBnt->setText(QApplication::translate("ContactsIndView", "&Delete", 0, QApplication::UnicodeUTF8));
        optionBnt->setText(QApplication::translate("ContactsIndView", "Op&tion", 0, QApplication::UnicodeUTF8));
        contactsCancelBnt->setText(QApplication::translate("ContactsIndView", "Ca&ncel", 0, QApplication::UnicodeUTF8));
        nameLabel->setText(QApplication::translate("ContactsIndView", "Name", 0, QApplication::UnicodeUTF8));
        callcodeLabel->setText(QApplication::translate("ContactsIndView", "Callcode", 0, QApplication::UnicodeUTF8));
        arrowUpButton->setText(QString());
        arrowDownButton->setText(QString());
        exportBnt->setText(QApplication::translate("ContactsIndView", "E&xport", 0, QApplication::UnicodeUTF8));
        importBnt->setText(QApplication::translate("ContactsIndView", "I&mport", 0, QApplication::UnicodeUTF8));
        printBnt->setText(QApplication::translate("ContactsIndView", " &Print", 0, QApplication::UnicodeUTF8));
        homeTBnt->setText(QApplication::translate("ContactsIndView", "&Home", 0, QApplication::UnicodeUTF8));
        stationTBnt->setText(QApplication::translate("ContactsIndView", "&Station", 0, QApplication::UnicodeUTF8));
        individualTBnt->setText(QApplication::translate("ContactsIndView", "Individual", 0, QApplication::UnicodeUTF8));
        newBnt->setText(QApplication::translate("ContactsIndView", "Ne&w", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ContactsIndView: public Ui_ContactsIndView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONTACTSINDVIEW_H

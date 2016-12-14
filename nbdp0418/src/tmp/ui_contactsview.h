/********************************************************************************
** Form generated from reading UI file 'contactsview.ui'
**
** Created: Wed May 4 11:49:55 2016
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONTACTSVIEW_H
#define UI_CONTACTSVIEW_H

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

class Ui_ContactsView
{
public:
    QPushButton *editBnt;
    QPushButton *deleteBnt;
    QPushButton *optionBnt;
    QPushButton *contactsCancelBnt;
    QLabel *nameLabel;
    QLabel *callsignLabel;
    QLabel *countryLabel;
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

    void setupUi(QWidget *ContactsView)
    {
        if (ContactsView->objectName().isEmpty())
            ContactsView->setObjectName(QString::fromUtf8("ContactsView"));
        ContactsView->resize(800, 544);
        ContactsView->setStyleSheet(QString::fromUtf8(""));
        editBnt = new QPushButton(ContactsView);
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
        deleteBnt = new QPushButton(ContactsView);
        deleteBnt->setObjectName(QString::fromUtf8("deleteBnt"));
        deleteBnt->setGeometry(QRect(190, 420, 85, 36));
        deleteBnt->setFocusPolicy(Qt::NoFocus);
        deleteBnt->setAutoFillBackground(false);
        deleteBnt->setStyleSheet(QString::fromUtf8("QPushButton{    border: none;\n"
"    border-radius:10px;\n"
"    color:rgb(86, 74, 74);\n"
"    border-radius:10px;\n"
"	background-color: rgb(16, 34, 56);\n"
"	font: 18pt \"Ubuntu\";\n"
"}\n"
"QPushButton:focus{\n"
"    color:white;\n"
"}"));
        deleteBnt->setCheckable(true);
        optionBnt = new QPushButton(ContactsView);
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
        contactsCancelBnt = new QPushButton(ContactsView);
        contactsCancelBnt->setObjectName(QString::fromUtf8("contactsCancelBnt"));
        contactsCancelBnt->setGeometry(QRect(670, 420, 105, 36));
        contactsCancelBnt->setFocusPolicy(Qt::NoFocus);
        contactsCancelBnt->setAutoFillBackground(false);
        contactsCancelBnt->setStyleSheet(QString::fromUtf8("QPushButton{    border: none;\n"
"    border-radius:10px;\n"
"    color:rgb(86, 74, 74);\n"
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
        nameLabel = new QLabel(ContactsView);
        nameLabel->setObjectName(QString::fromUtf8("nameLabel"));
        nameLabel->setGeometry(QRect(20, 50, 144, 61));
        nameLabel->setStyleSheet(QString::fromUtf8("background-image: url(:/images/Ellipse_144_61);\n"
"font: 20pt \"Ubuntu\";\n"
"color: rgb(183, 183, 183);"));
        nameLabel->setAlignment(Qt::AlignCenter);
        callsignLabel = new QLabel(ContactsView);
        callsignLabel->setObjectName(QString::fromUtf8("callsignLabel"));
        callsignLabel->setGeometry(QRect(340, 49, 144, 61));
        callsignLabel->setStyleSheet(QString::fromUtf8("background-image: url(:/images/Ellipse_144_61);\n"
"font: 20pt \"Ubuntu\";\n"
"color: rgb(183, 183, 183);"));
        callsignLabel->setAlignment(Qt::AlignCenter);
        countryLabel = new QLabel(ContactsView);
        countryLabel->setObjectName(QString::fromUtf8("countryLabel"));
        countryLabel->setGeometry(QRect(600, 50, 144, 61));
        countryLabel->setStyleSheet(QString::fromUtf8("background-image: url(:/images/Ellipse_144_61);\n"
"font: 20pt \"Ubuntu\";\n"
"color: rgb(183, 183, 183);"));
        countryLabel->setAlignment(Qt::AlignCenter);
        Contactsline = new QFrame(ContactsView);
        Contactsline->setObjectName(QString::fromUtf8("Contactsline"));
        Contactsline->setGeometry(QRect(0, 410, 800, 5));
        Contactsline->setFrameShape(QFrame::HLine);
        Contactsline->setFrameShadow(QFrame::Sunken);
        arrowUpButton = new QPushButton(ContactsView);
        arrowUpButton->setObjectName(QString::fromUtf8("arrowUpButton"));
        arrowUpButton->setGeometry(QRect(370, 390, 30, 15));
        arrowUpButton->setFocusPolicy(Qt::NoFocus);
        arrowUpButton->setAutoFillBackground(false);
        arrowUpButton->setStyleSheet(QString::fromUtf8("    border: none;\n"
"background-image: url(:/images/Arrow_up_gray);\n"
"selection-background-color: url(:/images/Arrow_up_white);"));
        arrowDownButton = new QPushButton(ContactsView);
        arrowDownButton->setObjectName(QString::fromUtf8("arrowDownButton"));
        arrowDownButton->setGeometry(QRect(450, 390, 30, 15));
        arrowDownButton->setFocusPolicy(Qt::NoFocus);
        arrowDownButton->setAutoFillBackground(false);
        arrowDownButton->setStyleSheet(QString::fromUtf8("    border: none;\n"
"background-image: url(:/images/Arrow_down_gray);\n"
"selection-background-color: url(:/images/Arrow_down_white);"));
        contactsTiltewidget = new TitleWidget(ContactsView);
        contactsTiltewidget->setObjectName(QString::fromUtf8("contactsTiltewidget"));
        contactsTiltewidget->setGeometry(QRect(0, 9, 800, 45));
        tableView = new QTableView(ContactsView);
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
        exportBnt = new QPushButton(ContactsView);
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
        importBnt = new QPushButton(ContactsView);
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
        printBnt = new QPushButton(ContactsView);
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
        controlWidget = new QWidget(ContactsView);
        controlWidget->setObjectName(QString::fromUtf8("controlWidget"));
        controlWidget->setGeometry(QRect(0, 470, 800, 72));
        controlWidget->setAutoFillBackground(false);
        controlWidget->setStyleSheet(QString::fromUtf8(" background-color:rgb(10,21,31);"));
        homeTBnt = new QToolButton(controlWidget);
        homeTBnt->setObjectName(QString::fromUtf8("homeTBnt"));
        homeTBnt->setGeometry(QRect(80, 0, 141, 61));
        homeTBnt->setStyleSheet(QString::fromUtf8("QToolButton{\n"
"    border:none;\n"
"    outline: none;\n"
"    color:rgb(86, 74, 74);\n"
"	\n"
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
        icon2.addFile(QString::fromUtf8(":/images/home_hover"), QSize(), QIcon::Active, QIcon::On);
        icon2.addFile(QString::fromUtf8(":/images/home_normal"), QSize(), QIcon::Selected, QIcon::Off);
        icon2.addFile(QString::fromUtf8(":/images/home_hover"), QSize(), QIcon::Selected, QIcon::On);
        homeTBnt->setIcon(icon2);
        homeTBnt->setIconSize(QSize(56, 42));
        homeTBnt->setPopupMode(QToolButton::DelayedPopup);
        homeTBnt->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        stationTBnt = new QToolButton(controlWidget);
        stationTBnt->setObjectName(QString::fromUtf8("stationTBnt"));
        stationTBnt->setEnabled(false);
        stationTBnt->setGeometry(QRect(663, 0, 111, 61));
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
        icon3.addFile(QString::fromUtf8(":/images/images/station_white.png"), QSize(), QIcon::Normal, QIcon::On);
        icon3.addFile(QString::fromUtf8(":/images/images/station_white.png"), QSize(), QIcon::Disabled, QIcon::Off);
        icon3.addFile(QString::fromUtf8(":/images/images/station_white.png"), QSize(), QIcon::Disabled, QIcon::On);
        icon3.addFile(QString::fromUtf8(":/images/images/station_white.png"), QSize(), QIcon::Selected, QIcon::Off);
        icon3.addFile(QString::fromUtf8(":/images/images/individual_white.png"), QSize(), QIcon::Selected, QIcon::On);
        stationTBnt->setIcon(icon3);
        stationTBnt->setIconSize(QSize(18, 31));
        stationTBnt->setPopupMode(QToolButton::DelayedPopup);
        stationTBnt->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        individualTBnt = new QToolButton(controlWidget);
        individualTBnt->setObjectName(QString::fromUtf8("individualTBnt"));
        individualTBnt->setGeometry(QRect(450, 0, 151, 61));
        individualTBnt->setStyleSheet(QString::fromUtf8("QToolButton{\n"
"    border:none;\n"
"    outline: none;\n"
"    color:rgb(86, 74, 74);\n"
"	\n"
"     background: transparent;\n"
"	font: 18pt \"Ubuntu\";\n"
"}\n"
"QToolButton:focus{\n"
"    color:white;\n"
"}\n"
"\n"
""));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/images/images/individual_gray.png"), QSize(), QIcon::Normal, QIcon::On);
        icon4.addFile(QString::fromUtf8(":/images/images/individual_gray.png"), QSize(), QIcon::Selected, QIcon::Off);
        icon4.addFile(QString::fromUtf8(":/images/images/individual_white.png"), QSize(), QIcon::Selected, QIcon::On);
        individualTBnt->setIcon(icon4);
        individualTBnt->setIconSize(QSize(25, 31));
        individualTBnt->setPopupMode(QToolButton::DelayedPopup);
        individualTBnt->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        newBnt = new QPushButton(ContactsView);
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

        retranslateUi(ContactsView);

        QMetaObject::connectSlotsByName(ContactsView);
    } // setupUi

    void retranslateUi(QWidget *ContactsView)
    {
        ContactsView->setWindowTitle(QApplication::translate("ContactsView", "Form", 0, QApplication::UnicodeUTF8));
        editBnt->setText(QApplication::translate("ContactsView", "&Edit", 0, QApplication::UnicodeUTF8));
        deleteBnt->setText(QApplication::translate("ContactsView", "&Delete", 0, QApplication::UnicodeUTF8));
        optionBnt->setText(QApplication::translate("ContactsView", "Op&tion", 0, QApplication::UnicodeUTF8));
        contactsCancelBnt->setText(QApplication::translate("ContactsView", "Ca&ncel", 0, QApplication::UnicodeUTF8));
        nameLabel->setText(QApplication::translate("ContactsView", "Name", 0, QApplication::UnicodeUTF8));
        callsignLabel->setText(QApplication::translate("ContactsView", "Callsign", 0, QApplication::UnicodeUTF8));
        countryLabel->setText(QApplication::translate("ContactsView", "Country", 0, QApplication::UnicodeUTF8));
        arrowUpButton->setText(QString());
        arrowDownButton->setText(QString());
        exportBnt->setText(QApplication::translate("ContactsView", " E&xport", 0, QApplication::UnicodeUTF8));
        importBnt->setText(QApplication::translate("ContactsView", " I&mport", 0, QApplication::UnicodeUTF8));
        printBnt->setText(QApplication::translate("ContactsView", " &Print", 0, QApplication::UnicodeUTF8));
        homeTBnt->setText(QApplication::translate("ContactsView", "&Home", 0, QApplication::UnicodeUTF8));
        stationTBnt->setText(QApplication::translate("ContactsView", "Station", 0, QApplication::UnicodeUTF8));
        individualTBnt->setText(QApplication::translate("ContactsView", "&Individual", 0, QApplication::UnicodeUTF8));
        newBnt->setText(QApplication::translate("ContactsView", "Ne&w", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ContactsView: public Ui_ContactsView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONTACTSVIEW_H

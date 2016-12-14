/********************************************************************************
** Form generated from reading UI file 'managermacro.ui'
**
** Created: Wed May 4 11:49:55 2016
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MANAGERMACRO_H
#define UI_MANAGERMACRO_H

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

class Ui_ManagerMacro
{
public:
    QPushButton *editBnt;
    QPushButton *deleteBnt;
    QPushButton *optionBnt;
    QLabel *nameLabel;
    QLabel *datetimeLabel;
    QFrame *Contactsline;
    QPushButton *arrowUpButton;
    QPushButton *arrowDownButton;
    TitleWidget *contactsTiltewidget;
    QTableView *tableView;
    QPushButton *exportBnt;
    QPushButton *importBnt;
    QWidget *controlWidget;
    QToolButton *homeTBnt;
    QToolButton *phrasebookTBnt;
    QToolButton *macroTBnt;
    QToolButton *fileTBnt;
    QPushButton *newBnt;

    void setupUi(QWidget *ManagerMacro)
    {
        if (ManagerMacro->objectName().isEmpty())
            ManagerMacro->setObjectName(QString::fromUtf8("ManagerMacro"));
        ManagerMacro->resize(800, 544);
        ManagerMacro->setStyleSheet(QString::fromUtf8(""));
        editBnt = new QPushButton(ManagerMacro);
        editBnt->setObjectName(QString::fromUtf8("editBnt"));
        editBnt->setGeometry(QRect(110, 420, 64, 36));
        editBnt->setFocusPolicy(Qt::NoFocus);
        editBnt->setAutoFillBackground(false);
        editBnt->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"    border: none;\n"
"selection-color: rgb(255, 255, 255);\n"
"    border-radius:10px;\n"
"color: rgb(86, 74, 74);\n"
"    border-radius:10px;\n"
"background-color: rgb(16, 34, 56);\n"
"font: 18pt \"Ubuntu\";\n"
"}\n"
"QPushButton:focus{\n"
"    color:white;\n"
"}\n"
""));
        editBnt->setCheckable(true);
        deleteBnt = new QPushButton(ManagerMacro);
        deleteBnt->setObjectName(QString::fromUtf8("deleteBnt"));
        deleteBnt->setGeometry(QRect(190, 420, 85, 36));
        deleteBnt->setFocusPolicy(Qt::NoFocus);
        deleteBnt->setAutoFillBackground(false);
        deleteBnt->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"    border: none;\n"
"selection-color: rgb(255, 255, 255);\n"
"    border-radius:10px;\n"
"color: rgb(86, 74, 74);\n"
"    border-radius:10px;\n"
"background-color: rgb(16, 34, 56);\n"
"font: 18pt \"Ubuntu\";\n"
"}\n"
"QPushButton:focus{\n"
"    color:white;\n"
"}\n"
""));
        deleteBnt->setCheckable(true);
        optionBnt = new QPushButton(ManagerMacro);
        optionBnt->setObjectName(QString::fromUtf8("optionBnt"));
        optionBnt->setGeometry(QRect(660, 420, 105, 36));
        optionBnt->setFocusPolicy(Qt::NoFocus);
        optionBnt->setAutoFillBackground(false);
        optionBnt->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"    border: none;\n"
"selection-color: rgb(255, 255, 255);\n"
"    border-radius:10px;\n"
"color: rgb(86, 74, 74);\n"
"    border-radius:10px;\n"
"background-color: rgb(16, 34, 56);\n"
"font: 18pt \"Ubuntu\";\n"
"}\n"
"QPushButton:focus{\n"
"    color:white;\n"
"}\n"
""));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/optionLeft"), QSize(), QIcon::Normal, QIcon::Off);
        optionBnt->setIcon(icon);
        optionBnt->setCheckable(true);
        nameLabel = new QLabel(ManagerMacro);
        nameLabel->setObjectName(QString::fromUtf8("nameLabel"));
        nameLabel->setGeometry(QRect(50, 50, 144, 61));
        nameLabel->setStyleSheet(QString::fromUtf8("background-image: url(:/images/Ellipse_144_61);\n"
"font: 20pt \"Ubuntu\";\n"
"color: rgb(183, 183, 183);"));
        nameLabel->setAlignment(Qt::AlignCenter);
        datetimeLabel = new QLabel(ManagerMacro);
        datetimeLabel->setObjectName(QString::fromUtf8("datetimeLabel"));
        datetimeLabel->setGeometry(QRect(480, 50, 191, 61));
        datetimeLabel->setStyleSheet(QString::fromUtf8("background-image: url(:/images/manager_File_dateTimeEllipse);\n"
"background-image-size:100px 200px;\n"
"font: 20pt \"Ubuntu\";\n"
"color: rgb(183, 183, 183); "));
        datetimeLabel->setAlignment(Qt::AlignCenter);
        Contactsline = new QFrame(ManagerMacro);
        Contactsline->setObjectName(QString::fromUtf8("Contactsline"));
        Contactsline->setGeometry(QRect(0, 410, 800, 5));
        Contactsline->setFrameShape(QFrame::HLine);
        Contactsline->setFrameShadow(QFrame::Sunken);
        arrowUpButton = new QPushButton(ManagerMacro);
        arrowUpButton->setObjectName(QString::fromUtf8("arrowUpButton"));
        arrowUpButton->setGeometry(QRect(370, 390, 30, 15));
        arrowUpButton->setFocusPolicy(Qt::NoFocus);
        arrowUpButton->setAutoFillBackground(false);
        arrowUpButton->setStyleSheet(QString::fromUtf8("    border: none;\n"
"background-image: url(:/images/Arrow_up_gray);\n"
"selection-background-color: url(:/images/Arrow_up_white);"));
        arrowDownButton = new QPushButton(ManagerMacro);
        arrowDownButton->setObjectName(QString::fromUtf8("arrowDownButton"));
        arrowDownButton->setGeometry(QRect(450, 390, 30, 15));
        arrowDownButton->setFocusPolicy(Qt::NoFocus);
        arrowDownButton->setAutoFillBackground(false);
        arrowDownButton->setStyleSheet(QString::fromUtf8("    border: none;\n"
"background-image: url(:/images/Arrow_down_gray);\n"
"selection-background-color: url(:/images/Arrow_down_white);"));
        contactsTiltewidget = new TitleWidget(ManagerMacro);
        contactsTiltewidget->setObjectName(QString::fromUtf8("contactsTiltewidget"));
        contactsTiltewidget->setGeometry(QRect(0, 9, 800, 45));
        tableView = new QTableView(ManagerMacro);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setGeometry(QRect(0, 110, 800, 281));
        tableView->setFocusPolicy(Qt::WheelFocus);
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
        exportBnt = new QPushButton(ManagerMacro);
        exportBnt->setObjectName(QString::fromUtf8("exportBnt"));
        exportBnt->setGeometry(QRect(590, 365, 71, 45));
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
        importBnt = new QPushButton(ManagerMacro);
        importBnt->setObjectName(QString::fromUtf8("importBnt"));
        importBnt->setGeometry(QRect(590, 410, 71, 45));
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
        controlWidget = new QWidget(ManagerMacro);
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
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/home_normal"), QSize(), QIcon::Normal, QIcon::On);
        icon1.addFile(QString::fromUtf8(":/images/home_normal"), QSize(), QIcon::Selected, QIcon::Off);
        icon1.addFile(QString::fromUtf8(":/images/home_hover"), QSize(), QIcon::Selected, QIcon::On);
        homeTBnt->setIcon(icon1);
        homeTBnt->setIconSize(QSize(56, 42));
        homeTBnt->setPopupMode(QToolButton::DelayedPopup);
        homeTBnt->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        phrasebookTBnt = new QToolButton(controlWidget);
        phrasebookTBnt->setObjectName(QString::fromUtf8("phrasebookTBnt"));
        phrasebookTBnt->setGeometry(QRect(620, 0, 171, 61));
        phrasebookTBnt->setStyleSheet(QString::fromUtf8("QToolButton{\n"
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
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/images/manager_PhraseBook_Btn_SelNo"), QSize(), QIcon::Normal, QIcon::On);
        icon2.addFile(QString::fromUtf8(":/images/manager_PhraseBook_Btn_SelNo"), QSize(), QIcon::Selected, QIcon::Off);
        icon2.addFile(QString::fromUtf8(":/images/manager_PhraseBook_Btn_SelNo"), QSize(), QIcon::Selected, QIcon::On);
        phrasebookTBnt->setIcon(icon2);
        phrasebookTBnt->setIconSize(QSize(26, 19));
        phrasebookTBnt->setPopupMode(QToolButton::DelayedPopup);
        phrasebookTBnt->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        macroTBnt = new QToolButton(controlWidget);
        macroTBnt->setObjectName(QString::fromUtf8("macroTBnt"));
        macroTBnt->setEnabled(false);
        macroTBnt->setGeometry(QRect(500, 0, 101, 61));
        macroTBnt->setStyleSheet(QString::fromUtf8("QToolButton{\n"
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
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/images/manager_Macro_Btn_SelYes"), QSize(), QIcon::Normal, QIcon::On);
        icon3.addFile(QString::fromUtf8(":/images/manager_Macro_Btn_SelYes"), QSize(), QIcon::Disabled, QIcon::Off);
        macroTBnt->setIcon(icon3);
        macroTBnt->setIconSize(QSize(26, 19));
        macroTBnt->setPopupMode(QToolButton::DelayedPopup);
        macroTBnt->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        fileTBnt = new QToolButton(controlWidget);
        fileTBnt->setObjectName(QString::fromUtf8("fileTBnt"));
        fileTBnt->setGeometry(QRect(400, 0, 81, 61));
        fileTBnt->setStyleSheet(QString::fromUtf8("QToolButton{\n"
"    border:none;\n"
"    outline: none;\n"
"    color:rgb(86, 74, 74);\n"
" \n"
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
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/images/manager_File_Btn_SelNo"), QSize(), QIcon::Normal, QIcon::On);
        icon4.addFile(QString::fromUtf8(":/images/manager_File_Btn_SelNo"), QSize(), QIcon::Selected, QIcon::Off);
        icon4.addFile(QString::fromUtf8(":/images/manager_File_Btn_SelNo"), QSize(), QIcon::Selected, QIcon::On);
        fileTBnt->setIcon(icon4);
        fileTBnt->setIconSize(QSize(26, 19));
        fileTBnt->setPopupMode(QToolButton::DelayedPopup);
        fileTBnt->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        newBnt = new QPushButton(ManagerMacro);
        newBnt->setObjectName(QString::fromUtf8("newBnt"));
        newBnt->setGeometry(QRect(30, 420, 64, 36));
        newBnt->setFocusPolicy(Qt::NoFocus);
        newBnt->setAutoFillBackground(false);
        newBnt->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"    border: none;\n"
"selection-color: rgb(255, 255, 255);\n"
"    border-radius:10px;\n"
"color: rgb(86, 74, 74);\n"
"    border-radius:10px;\n"
"background-color: rgb(16, 34, 56);\n"
"font: 18pt \"Ubuntu\";\n"
"}\n"
"QPushButton:focus{\n"
"    color:white;\n"
"}\n"
""));
        newBnt->setCheckable(true);

        retranslateUi(ManagerMacro);

        QMetaObject::connectSlotsByName(ManagerMacro);
    } // setupUi

    void retranslateUi(QWidget *ManagerMacro)
    {
        ManagerMacro->setWindowTitle(QApplication::translate("ManagerMacro", "Form", 0, QApplication::UnicodeUTF8));
        editBnt->setText(QApplication::translate("ManagerMacro", "&Edit", 0, QApplication::UnicodeUTF8));
        deleteBnt->setText(QApplication::translate("ManagerMacro", "&Delete", 0, QApplication::UnicodeUTF8));
        optionBnt->setText(QApplication::translate("ManagerMacro", "Op&tion", 0, QApplication::UnicodeUTF8));
        nameLabel->setText(QApplication::translate("ManagerMacro", "Number", 0, QApplication::UnicodeUTF8));
        datetimeLabel->setText(QApplication::translate("ManagerMacro", "Name", 0, QApplication::UnicodeUTF8));
        arrowUpButton->setText(QString());
        arrowDownButton->setText(QString());
        exportBnt->setText(QApplication::translate("ManagerMacro", " E&xport", 0, QApplication::UnicodeUTF8));
        importBnt->setText(QApplication::translate("ManagerMacro", " I&mport", 0, QApplication::UnicodeUTF8));
        homeTBnt->setText(QApplication::translate("ManagerMacro", "&Home", 0, QApplication::UnicodeUTF8));
        phrasebookTBnt->setText(QApplication::translate("ManagerMacro", "Phr&asebook", 0, QApplication::UnicodeUTF8));
        macroTBnt->setText(QApplication::translate("ManagerMacro", "Macro", 0, QApplication::UnicodeUTF8));
        fileTBnt->setText(QApplication::translate("ManagerMacro", "&File", 0, QApplication::UnicodeUTF8));
        newBnt->setText(QApplication::translate("ManagerMacro", "Ne&w", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ManagerMacro: public Ui_ManagerMacro {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MANAGERMACRO_H

/********************************************************************************
** Form generated from reading UI file 'managerfileeditview.ui'
**
** Created: Wed May 4 11:49:55 2016
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MANAGERFILEEDITVIEW_H
#define UI_MANAGERFILEEDITVIEW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QTextEdit>
#include <QtGui/QToolButton>
#include <QtGui/QWidget>
#include "widgets/titlewidget.h"

QT_BEGIN_NAMESPACE

class Ui_ManagerFileEditView
{
public:
    QPushButton *undoBnt;
    QPushButton *copyBnt;
    QPushButton *cutBnt;
    QFrame *Contactsline;
    QPushButton *arrowUpButton;
    QPushButton *arrowDownButton;
    QWidget *controlWidget;
    QToolButton *macroTBnt;
    QToolButton *homeTBnt;
    QToolButton *fileTBnt_2;
    QToolButton *phrasebookTBnt;
    QPushButton *pasteBnt;
    QTextEdit *textEdit;
    QPushButton *cancelBnt;
    QPushButton *saveBnt;
    TitleWidget *contactsTiltewidget;

    void setupUi(QWidget *ManagerFileEditView)
    {
        if (ManagerFileEditView->objectName().isEmpty())
            ManagerFileEditView->setObjectName(QString::fromUtf8("ManagerFileEditView"));
        ManagerFileEditView->resize(800, 544);
        ManagerFileEditView->setStyleSheet(QString::fromUtf8(""));
        undoBnt = new QPushButton(ManagerFileEditView);
        undoBnt->setObjectName(QString::fromUtf8("undoBnt"));
        undoBnt->setGeometry(QRect(30, 420, 64, 36));
        undoBnt->setFocusPolicy(Qt::StrongFocus);
        undoBnt->setAutoFillBackground(false);
        undoBnt->setStyleSheet(QString::fromUtf8("QPushButton{\n"
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
        undoBnt->setCheckable(true);
        copyBnt = new QPushButton(ManagerFileEditView);
        copyBnt->setObjectName(QString::fromUtf8("copyBnt"));
        copyBnt->setGeometry(QRect(110, 420, 64, 36));
        copyBnt->setFocusPolicy(Qt::NoFocus);
        copyBnt->setAutoFillBackground(false);
        copyBnt->setStyleSheet(QString::fromUtf8("QPushButton{\n"
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
        copyBnt->setCheckable(true);
        cutBnt = new QPushButton(ManagerFileEditView);
        cutBnt->setObjectName(QString::fromUtf8("cutBnt"));
        cutBnt->setGeometry(QRect(190, 420, 61, 36));
        cutBnt->setFocusPolicy(Qt::NoFocus);
        cutBnt->setAutoFillBackground(false);
        cutBnt->setStyleSheet(QString::fromUtf8("QPushButton{\n"
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
        cutBnt->setCheckable(true);
        Contactsline = new QFrame(ManagerFileEditView);
        Contactsline->setObjectName(QString::fromUtf8("Contactsline"));
        Contactsline->setGeometry(QRect(0, 410, 800, 5));
        Contactsline->setFrameShape(QFrame::HLine);
        Contactsline->setFrameShadow(QFrame::Sunken);
        arrowUpButton = new QPushButton(ManagerFileEditView);
        arrowUpButton->setObjectName(QString::fromUtf8("arrowUpButton"));
        arrowUpButton->setGeometry(QRect(370, 390, 30, 15));
        arrowUpButton->setFocusPolicy(Qt::NoFocus);
        arrowUpButton->setAutoFillBackground(false);
        arrowUpButton->setStyleSheet(QString::fromUtf8("    border: none;\n"
"background-image: url(:/images/Arrow_up_gray);\n"
"selection-background-color: url(:/images/Arrow_up_white);"));
        arrowDownButton = new QPushButton(ManagerFileEditView);
        arrowDownButton->setObjectName(QString::fromUtf8("arrowDownButton"));
        arrowDownButton->setGeometry(QRect(450, 390, 30, 15));
        arrowDownButton->setFocusPolicy(Qt::NoFocus);
        arrowDownButton->setAutoFillBackground(false);
        arrowDownButton->setStyleSheet(QString::fromUtf8("    border: none;\n"
"background-image: url(:/images/Arrow_down_gray);\n"
"selection-background-color: url(:/images/Arrow_down_white);"));
        controlWidget = new QWidget(ManagerFileEditView);
        controlWidget->setObjectName(QString::fromUtf8("controlWidget"));
        controlWidget->setGeometry(QRect(0, 470, 800, 72));
        controlWidget->setAutoFillBackground(false);
        controlWidget->setStyleSheet(QString::fromUtf8(" background-color:rgb(10,21,31);"));
        macroTBnt = new QToolButton(controlWidget);
        macroTBnt->setObjectName(QString::fromUtf8("macroTBnt"));
        macroTBnt->setGeometry(QRect(500, 0, 145, 61));
        macroTBnt->setStyleSheet(QString::fromUtf8("QToolButton{\n"
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
        icon.addFile(QString::fromUtf8(":/images/manager_Macro_Btn_SelNo"), QSize(), QIcon::Normal, QIcon::On);
        icon.addFile(QString::fromUtf8(":/images/manager_Macro_Btn_SelNo"), QSize(), QIcon::Selected, QIcon::Off);
        icon.addFile(QString::fromUtf8(":/images/manager_Macro_Btn_SelNo"), QSize(), QIcon::Selected, QIcon::On);
        macroTBnt->setIcon(icon);
        macroTBnt->setIconSize(QSize(26, 19));
        macroTBnt->setPopupMode(QToolButton::DelayedPopup);
        macroTBnt->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        homeTBnt = new QToolButton(controlWidget);
        homeTBnt->setObjectName(QString::fromUtf8("homeTBnt"));
        homeTBnt->setGeometry(QRect(80, 0, 141, 61));
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
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/home_normal"), QSize(), QIcon::Normal, QIcon::On);
        icon1.addFile(QString::fromUtf8(":/images/home_normal"), QSize(), QIcon::Selected, QIcon::Off);
        icon1.addFile(QString::fromUtf8(":/images/home_hover"), QSize(), QIcon::Selected, QIcon::On);
        homeTBnt->setIcon(icon1);
        homeTBnt->setIconSize(QSize(56, 42));
        homeTBnt->setPopupMode(QToolButton::DelayedPopup);
        homeTBnt->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        fileTBnt_2 = new QToolButton(controlWidget);
        fileTBnt_2->setObjectName(QString::fromUtf8("fileTBnt_2"));
        fileTBnt_2->setEnabled(false);
        fileTBnt_2->setGeometry(QRect(400, 0, 81, 61));
        fileTBnt_2->setStyleSheet(QString::fromUtf8("QToolButton{\n"
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
        icon2.addFile(QString::fromUtf8(":/images/manager_File_Btn_SelYes"), QSize(), QIcon::Normal, QIcon::On);
        icon2.addFile(QString::fromUtf8(":/images/manager_File_Btn_SelYes"), QSize(), QIcon::Disabled, QIcon::Off);
        icon2.addFile(QString::fromUtf8(":/images/manager_File_Btn_SelNo"), QSize(), QIcon::Selected, QIcon::Off);
        icon2.addFile(QString::fromUtf8(":/images/manager_File_Btn_SelNo"), QSize(), QIcon::Selected, QIcon::On);
        fileTBnt_2->setIcon(icon2);
        fileTBnt_2->setIconSize(QSize(26, 19));
        fileTBnt_2->setPopupMode(QToolButton::DelayedPopup);
        fileTBnt_2->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        phrasebookTBnt = new QToolButton(controlWidget);
        phrasebookTBnt->setObjectName(QString::fromUtf8("phrasebookTBnt"));
        phrasebookTBnt->setGeometry(QRect(613, 0, 161, 61));
        phrasebookTBnt->setStyleSheet(QString::fromUtf8("QToolButton{\n"
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
        icon3.addFile(QString::fromUtf8(":/images/manager_PhraseBook_Btn_SelNo"), QSize(), QIcon::Normal, QIcon::On);
        icon3.addFile(QString::fromUtf8(":/images/manager_PhraseBook_Btn_SelNo"), QSize(), QIcon::Selected, QIcon::Off);
        icon3.addFile(QString::fromUtf8(":/images/manager_PhraseBook_Btn_SelNo"), QSize(), QIcon::Selected, QIcon::On);
        phrasebookTBnt->setIcon(icon3);
        phrasebookTBnt->setIconSize(QSize(26, 19));
        phrasebookTBnt->setPopupMode(QToolButton::DelayedPopup);
        phrasebookTBnt->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        pasteBnt = new QPushButton(ManagerFileEditView);
        pasteBnt->setObjectName(QString::fromUtf8("pasteBnt"));
        pasteBnt->setGeometry(QRect(270, 420, 81, 36));
        pasteBnt->setFocusPolicy(Qt::NoFocus);
        pasteBnt->setAutoFillBackground(false);
        pasteBnt->setStyleSheet(QString::fromUtf8("QPushButton{\n"
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
        pasteBnt->setCheckable(true);
        textEdit = new QTextEdit(ManagerFileEditView);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(43, 70, 721, 311));
        textEdit->setFocusPolicy(Qt::NoFocus);
        textEdit->setStyleSheet(QString::fromUtf8("font: 22pt \"Ubuntu\"; \n"
"color: rgb(255, 255, 255);\n"
"border:none;\n"
"background: transparent;\n"
""));
        textEdit->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        textEdit->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        textEdit->setTabChangesFocus(false);
        textEdit->setTabStopWidth(0);
        cancelBnt = new QPushButton(ManagerFileEditView);
        cancelBnt->setObjectName(QString::fromUtf8("cancelBnt"));
        cancelBnt->setGeometry(QRect(670, 420, 101, 36));
        cancelBnt->setFocusPolicy(Qt::NoFocus);
        cancelBnt->setAutoFillBackground(false);
        cancelBnt->setStyleSheet(QString::fromUtf8("QPushButton{\n"
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
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/images/cancel"), QSize(), QIcon::Normal, QIcon::Off);
        cancelBnt->setIcon(icon4);
        cancelBnt->setCheckable(true);
        saveBnt = new QPushButton(ManagerFileEditView);
        saveBnt->setObjectName(QString::fromUtf8("saveBnt"));
        saveBnt->setGeometry(QRect(580, 420, 71, 36));
        saveBnt->setFocusPolicy(Qt::NoFocus);
        saveBnt->setAutoFillBackground(false);
        saveBnt->setStyleSheet(QString::fromUtf8("QPushButton{\n"
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
        saveBnt->setCheckable(true);
        contactsTiltewidget = new TitleWidget(ManagerFileEditView);
        contactsTiltewidget->setObjectName(QString::fromUtf8("contactsTiltewidget"));
        contactsTiltewidget->setGeometry(QRect(0, 0, 800, 50));

        retranslateUi(ManagerFileEditView);

        QMetaObject::connectSlotsByName(ManagerFileEditView);
    } // setupUi

    void retranslateUi(QWidget *ManagerFileEditView)
    {
        ManagerFileEditView->setWindowTitle(QApplication::translate("ManagerFileEditView", "Form", 0, QApplication::UnicodeUTF8));
        undoBnt->setText(QApplication::translate("ManagerFileEditView", "&Undo", 0, QApplication::UnicodeUTF8));
        copyBnt->setText(QApplication::translate("ManagerFileEditView", "&Copy", 0, QApplication::UnicodeUTF8));
        cutBnt->setText(QApplication::translate("ManagerFileEditView", "Cu&t", 0, QApplication::UnicodeUTF8));
        arrowUpButton->setText(QString());
        arrowDownButton->setText(QString());
        macroTBnt->setText(QApplication::translate("ManagerFileEditView", "&Macro", 0, QApplication::UnicodeUTF8));
        homeTBnt->setText(QApplication::translate("ManagerFileEditView", "&Home", 0, QApplication::UnicodeUTF8));
        fileTBnt_2->setText(QApplication::translate("ManagerFileEditView", "File", 0, QApplication::UnicodeUTF8));
        phrasebookTBnt->setText(QApplication::translate("ManagerFileEditView", "Phr&asebook", 0, QApplication::UnicodeUTF8));
        pasteBnt->setText(QApplication::translate("ManagerFileEditView", "&Paste", 0, QApplication::UnicodeUTF8));
        textEdit->setHtml(QApplication::translate("ManagerFileEditView", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:22pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:11pt;\"><br /></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:11pt;\"><br /></p></body></html>", 0, QApplication::UnicodeUTF8));
        cancelBnt->setText(QApplication::translate("ManagerFileEditView", "Ca&ncel", 0, QApplication::UnicodeUTF8));
        saveBnt->setText(QApplication::translate("ManagerFileEditView", "&Save", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ManagerFileEditView: public Ui_ManagerFileEditView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MANAGERFILEEDITVIEW_H

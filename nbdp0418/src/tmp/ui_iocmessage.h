/********************************************************************************
** Form generated from reading UI file 'iocmessage.ui'
**
** Created: Wed May 4 11:49:56 2016
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IOCMESSAGE_H
#define UI_IOCMESSAGE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QFrame>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QTextEdit>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_IocMessage
{
public:
    QWidget *widget_title;
    QHBoxLayout *horizontalLayout_2;
    QLabel *lab_Title;
    QWidget *widget_main;
    QFrame *line;
    QFrame *line_2;
    QLabel *label_ico;
    QTextEdit *textEdit1;
    QTextEdit *textEdit2;
    QTextEdit *textEdit3;
    QPushButton *okBtn;
    QPushButton *cancelBtn;

    void setupUi(QDialog *IocMessage)
    {
        if (IocMessage->objectName().isEmpty())
            IocMessage->setObjectName(QString::fromUtf8("IocMessage"));
        IocMessage->resize(751, 251);
        IocMessage->setStyleSheet(QString::fromUtf8("background-color: rgb(69, 89, 104);"));
        widget_title = new QWidget(IocMessage);
        widget_title->setObjectName(QString::fromUtf8("widget_title"));
        widget_title->setGeometry(QRect(0, 2, 751, 41));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(widget_title->sizePolicy().hasHeightForWidth());
        widget_title->setSizePolicy(sizePolicy);
        widget_title->setMinimumSize(QSize(100, 28));
        horizontalLayout_2 = new QHBoxLayout(widget_title);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        lab_Title = new QLabel(widget_title);
        lab_Title->setObjectName(QString::fromUtf8("lab_Title"));
        lab_Title->setEnabled(true);
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(lab_Title->sizePolicy().hasHeightForWidth());
        lab_Title->setSizePolicy(sizePolicy1);
        QFont font;
        font.setFamily(QString::fromUtf8("Ubuntu"));
        font.setPointSize(22);
        font.setBold(true);
        font.setItalic(false);
        font.setWeight(75);
        lab_Title->setFont(font);
        lab_Title->setStyleSheet(QString::fromUtf8("font: 22pt \"Ubuntu\";\n"
"color: rgb(255, 255, 255);\n"
"font-weight:bold;"));
        lab_Title->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(lab_Title);

        widget_main = new QWidget(IocMessage);
        widget_main->setObjectName(QString::fromUtf8("widget_main"));
        widget_main->setEnabled(true);
        widget_main->setGeometry(QRect(0, 42, 751, 210));
        widget_main->setStyleSheet(QString::fromUtf8(""));
        line = new QFrame(widget_main);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(0, 0, 751, 16));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        line_2 = new QFrame(widget_main);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setGeometry(QRect(0, 130, 751, 16));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);
        label_ico = new QLabel(widget_main);
        label_ico->setObjectName(QString::fromUtf8("label_ico"));
        label_ico->setGeometry(QRect(0, 27, 81, 91));
        label_ico->setContextMenuPolicy(Qt::NoContextMenu);
        label_ico->setStyleSheet(QString::fromUtf8(""));
        label_ico->setAlignment(Qt::AlignCenter);
        textEdit1 = new QTextEdit(widget_main);
        textEdit1->setObjectName(QString::fromUtf8("textEdit1"));
        textEdit1->setEnabled(false);
        textEdit1->setGeometry(QRect(90, 40, 671, 35));
        textEdit1->setStyleSheet(QString::fromUtf8("border:none;\n"
"   outline:none;\n"
"   background: transparent;\n"
"color: rgb(255, 255, 255);"));
        textEdit1->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        textEdit1->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        textEdit2 = new QTextEdit(widget_main);
        textEdit2->setObjectName(QString::fromUtf8("textEdit2"));
        textEdit2->setEnabled(false);
        textEdit2->setGeometry(QRect(90, 60, 671, 35));
        textEdit2->setStyleSheet(QString::fromUtf8("border:none;\n"
"   outline:none;\n"
"   background: transparent;\n"
"color: rgb(255, 255, 255);"));
        textEdit2->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        textEdit2->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        textEdit3 = new QTextEdit(widget_main);
        textEdit3->setObjectName(QString::fromUtf8("textEdit3"));
        textEdit3->setEnabled(false);
        textEdit3->setGeometry(QRect(90, 80, 671, 35));
        textEdit3->setStyleSheet(QString::fromUtf8("border:none;\n"
"   outline:none;\n"
"   background: transparent;\n"
"color: rgb(255, 255, 255);"));
        textEdit3->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        textEdit3->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        okBtn = new QPushButton(widget_main);
        okBtn->setObjectName(QString::fromUtf8("okBtn"));
        okBtn->setGeometry(QRect(80, 160, 100, 35));
        okBtn->setCursor(QCursor(Qt::PointingHandCursor));
        okBtn->setFocusPolicy(Qt::StrongFocus);
        okBtn->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"    color:rgb(86, 74, 74);\n"
" border: none;\n"
" border-radius:10px;\n"
"background-color:qlineargradient(spread:pad, x1:0.46, y1:0.017, x2:0.49, y2:1, stop:0 rgba(122, 124, 125, 255), stop:0.95 rgba(108, 131, 140, 255));\n"
"}\n"
"\n"
"QPushButton:focus{\n"
"    color:white;\n"
"}\n"
""));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/images/OK.png"), QSize(), QIcon::Normal, QIcon::Off);
        okBtn->setIcon(icon);
        okBtn->setIconSize(QSize(20, 20));
        cancelBtn = new QPushButton(widget_main);
        cancelBtn->setObjectName(QString::fromUtf8("cancelBtn"));
        cancelBtn->setGeometry(QRect(550, 160, 100, 35));
        cancelBtn->setCursor(QCursor(Qt::PointingHandCursor));
        cancelBtn->setFocusPolicy(Qt::StrongFocus);
        cancelBtn->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"    color:rgb(86, 74, 74);\n"
" border: none;\n"
" border-radius:10px;\n"
"background-color:qlineargradient(spread:pad, x1:0.46, y1:0.017, x2:0.49, y2:1, stop:0 rgba(122, 124, 125, 255), stop:0.95 rgba(108, 131, 140, 255));\n"
"}\n"
"\n"
"QPushButton:focus{\n"
"    color:white;\n"
"}\n"
""));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/cancel"), QSize(), QIcon::Normal, QIcon::Off);
        cancelBtn->setIcon(icon1);
        cancelBtn->setIconSize(QSize(20, 20));

        retranslateUi(IocMessage);

        QMetaObject::connectSlotsByName(IocMessage);
    } // setupUi

    void retranslateUi(QDialog *IocMessage)
    {
        IocMessage->setWindowTitle(QApplication::translate("IocMessage", "Dialog", 0, QApplication::UnicodeUTF8));
        lab_Title->setText(QApplication::translate("IocMessage", "title", 0, QApplication::UnicodeUTF8));
        label_ico->setText(QString());
        textEdit1->setHtml(QApplication::translate("IocMessage", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:15pt;\">   </span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:15pt;\"><br /></p></body></html>", 0, QApplication::UnicodeUTF8));
        textEdit2->setHtml(QApplication::translate("IocMessage", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:15pt;\">   </span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:15pt;\"><br /></p></body></html>", 0, QApplication::UnicodeUTF8));
        textEdit3->setHtml(QApplication::translate("IocMessage", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:15pt;\">   </span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:15pt;\"><br /></p></body></html>", 0, QApplication::UnicodeUTF8));
        okBtn->setText(QApplication::translate("IocMessage", "&OK", 0, QApplication::UnicodeUTF8));
        cancelBtn->setText(QApplication::translate("IocMessage", "Ca&ncel", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class IocMessage: public Ui_IocMessage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IOCMESSAGE_H

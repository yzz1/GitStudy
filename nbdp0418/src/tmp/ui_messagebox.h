/********************************************************************************
** Form generated from reading UI file 'messagebox.ui'
**
** Created: Wed May 4 11:49:55 2016
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MESSAGEBOX_H
#define UI_MESSAGEBOX_H

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
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MessageBox
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widget_title;
    QHBoxLayout *horizontalLayout_2;
    QLabel *lab_Ico;
    QWidget *widget_menu;
    QHBoxLayout *horizontalLayout;
    QLabel *lab_Title;
    QWidget *widget_main;
    QFrame *line;
    QFrame *line_2;
    QPushButton *cancelBtn;
    QPushButton *okBtn;
    QLabel *labInfo;
    QPushButton *okBtn_2;

    void setupUi(QDialog *MessageBox)
    {
        if (MessageBox->objectName().isEmpty())
            MessageBox->setObjectName(QString::fromUtf8("MessageBox"));
        MessageBox->resize(493, 272);
        MessageBox->setModal(true);
        verticalLayout = new QVBoxLayout(MessageBox);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 1, 0, 1);
        widget_title = new QWidget(MessageBox);
        widget_title->setObjectName(QString::fromUtf8("widget_title"));
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
        lab_Ico = new QLabel(widget_title);
        lab_Ico->setObjectName(QString::fromUtf8("lab_Ico"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(lab_Ico->sizePolicy().hasHeightForWidth());
        lab_Ico->setSizePolicy(sizePolicy1);
        lab_Ico->setMinimumSize(QSize(31, 0));
        lab_Ico->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(lab_Ico);

        widget_menu = new QWidget(widget_title);
        widget_menu->setObjectName(QString::fromUtf8("widget_menu"));
        sizePolicy1.setHeightForWidth(widget_menu->sizePolicy().hasHeightForWidth());
        widget_menu->setSizePolicy(sizePolicy1);
        horizontalLayout = new QHBoxLayout(widget_menu);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        lab_Title = new QLabel(widget_menu);
        lab_Title->setObjectName(QString::fromUtf8("lab_Title"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(lab_Title->sizePolicy().hasHeightForWidth());
        lab_Title->setSizePolicy(sizePolicy2);
        QFont font;
        font.setPointSize(18);
        lab_Title->setFont(font);
        lab_Title->setStyleSheet(QString::fromUtf8(""));
        lab_Title->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(lab_Title);


        horizontalLayout_2->addWidget(widget_menu);


        verticalLayout->addWidget(widget_title);

        widget_main = new QWidget(MessageBox);
        widget_main->setObjectName(QString::fromUtf8("widget_main"));
        widget_main->setEnabled(true);
        widget_main->setStyleSheet(QString::fromUtf8(""));
        line = new QFrame(widget_main);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(0, 5, 493, 16));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        line_2 = new QFrame(widget_main);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setGeometry(QRect(0, 160, 493, 16));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);
        cancelBtn = new QPushButton(widget_main);
        cancelBtn->setObjectName(QString::fromUtf8("cancelBtn"));
        cancelBtn->setGeometry(QRect(350, 190, 86, 28));
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
"\n"
"}"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/cancel"), QSize(), QIcon::Normal, QIcon::Off);
        cancelBtn->setIcon(icon);
        cancelBtn->setIconSize(QSize(20, 20));
        okBtn = new QPushButton(widget_main);
        okBtn->setObjectName(QString::fromUtf8("okBtn"));
        okBtn->setGeometry(QRect(70, 190, 85, 28));
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
"\n"
"}"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/images/OK.png"), QSize(), QIcon::Normal, QIcon::Off);
        okBtn->setIcon(icon1);
        okBtn->setIconSize(QSize(20, 20));
        labInfo = new QLabel(widget_main);
        labInfo->setObjectName(QString::fromUtf8("labInfo"));
        labInfo->setGeometry(QRect(0, 13, 491, 141));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Ubuntu"));
        font1.setPointSize(14);
        font1.setBold(false);
        font1.setItalic(false);
        font1.setWeight(50);
        labInfo->setFont(font1);
        labInfo->setStyleSheet(QString::fromUtf8("    border: none;\n"
"    outline: none;"));
        labInfo->setScaledContents(false);
        labInfo->setAlignment(Qt::AlignCenter);
        labInfo->setWordWrap(true);
        labInfo->setMargin(5);
        okBtn_2 = new QPushButton(widget_main);
        okBtn_2->setObjectName(QString::fromUtf8("okBtn_2"));
        okBtn_2->setGeometry(QRect(210, 190, 85, 28));
        okBtn_2->setCursor(QCursor(Qt::PointingHandCursor));
        okBtn_2->setFocusPolicy(Qt::StrongFocus);
        okBtn_2->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"    color:rgb(86, 74, 74);\n"
" border: none;\n"
" border-radius:10px;\n"
"background-color:qlineargradient(spread:pad, x1:0.46, y1:0.017, x2:0.49, y2:1, stop:0 rgba(122, 124, 125, 255), stop:0.95 rgba(108, 131, 140, 255));\n"
"}\n"
"\n"
"QPushButton:focus{\n"
"    color:white;\n"
"\n"
"}"));
        okBtn_2->setIcon(icon1);
        okBtn_2->setIconSize(QSize(20, 20));

        verticalLayout->addWidget(widget_main);


        retranslateUi(MessageBox);

        QMetaObject::connectSlotsByName(MessageBox);
    } // setupUi

    void retranslateUi(QDialog *MessageBox)
    {
        MessageBox->setWindowTitle(QApplication::translate("MessageBox", "\346\217\220\347\244\272", 0, QApplication::UnicodeUTF8));
        lab_Ico->setText(QString());
        lab_Title->setText(QApplication::translate("MessageBox", "title", 0, QApplication::UnicodeUTF8));
        cancelBtn->setText(QApplication::translate("MessageBox", "Ca&ncel", 0, QApplication::UnicodeUTF8));
        okBtn->setText(QApplication::translate("MessageBox", "&OK", 0, QApplication::UnicodeUTF8));
        labInfo->setText(QApplication::translate("MessageBox", "Message", 0, QApplication::UnicodeUTF8));
        okBtn_2->setText(QApplication::translate("MessageBox", "&OK", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MessageBox: public Ui_MessageBox {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MESSAGEBOX_H

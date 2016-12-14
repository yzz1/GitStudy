/********************************************************************************
** Form generated from reading UI file 'titlewidget.ui'
**
** Created: Wed May 4 11:49:55 2016
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TITLEWIDGET_H
#define UI_TITLEWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TitleWidget
{
public:
    QHBoxLayout *horizontalLayout_2;
    QFrame *line;
    QLabel *label;
    QFrame *line_2;

    void setupUi(QWidget *TitleWidget)
    {
        if (TitleWidget->objectName().isEmpty())
            TitleWidget->setObjectName(QString::fromUtf8("TitleWidget"));
        TitleWidget->resize(800, 45);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(TitleWidget->sizePolicy().hasHeightForWidth());
        TitleWidget->setSizePolicy(sizePolicy);
        TitleWidget->setStyleSheet(QString::fromUtf8("background: transparent;"));
        horizontalLayout_2 = new QHBoxLayout(TitleWidget);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        line = new QFrame(TitleWidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setAutoFillBackground(false);
        line->setFrameShadow(QFrame::Plain);
        line->setFrameShape(QFrame::HLine);

        horizontalLayout_2->addWidget(line);

        label = new QLabel(TitleWidget);
        label->setObjectName(QString::fromUtf8("label"));
        QSizePolicy sizePolicy1(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy1);
        QFont font;
        font.setPointSize(20);
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("background: transparent;"));
        label->setAlignment(Qt::AlignCenter);
        label->setWordWrap(false);
        label->setMargin(5);

        horizontalLayout_2->addWidget(label);

        line_2 = new QFrame(TitleWidget);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShadow(QFrame::Plain);
        line_2->setFrameShape(QFrame::HLine);

        horizontalLayout_2->addWidget(line_2);


        retranslateUi(TitleWidget);

        QMetaObject::connectSlotsByName(TitleWidget);
    } // setupUi

    void retranslateUi(QWidget *TitleWidget)
    {
        TitleWidget->setWindowTitle(QApplication::translate("TitleWidget", "Form", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("TitleWidget", "TextLabel", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class TitleWidget: public Ui_TitleWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TITLEWIDGET_H

#include <QtGui/QApplication>
#include <QTextCodec>
#include <QDebug>
#include "mainwindow.h"

//int main(int argc, char *argv[])
//{
//    QApplication a(argc, argv);

//    //配置文字编码方式
//    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
//    QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF-8"));
//    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));

////    //MainWindow w;
////    QFile file(":/qss/stylesheet.qss");
////    if(!file.open(QFile::ReadOnly))
////            qDebug()<<"file open fail";
////    QString str_stylesheet=file.readAll().data();
////    qApp->setStyleSheet(str_stylesheet);

////   // w.show();
//    return a.exec();
//}

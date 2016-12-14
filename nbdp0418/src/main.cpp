#include <QApplication>
#include <QtGui/QMainWindow>

#include <QObject>
#include <QFile>
#include <QSharedMemory>
#include "views/nbdpview.h"
#include <QUuid>
#include <QDebug>
#include <QDir>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include <QtSql/QSqlDatabase>
#include "views/common/configreader.h"
#include "core/utils/pathresolve.h"
#include <QSqlDriver>
#include <QMessageBox>
#include <QTranslator>
#include "core/utils/pathresolve.h"
#include "widgets/messagebox.h"
#include "core/utils/configutils.h"
#include "core/utils/pathresolve.h"
#include <QTextCodec>
#include "core/utils/sqlitehelper.h"
#include "core/utils/pathresolve.h"
//#include <QDesktopWidget>
#include "views/common/constants.h"
#include "logging.h"
#include <QWSServer>
#include "../myCom/mainwindow.h"
#include "../myCom/UISerial.h"
#include "../myCom/nbdpWorkFlow.h"
#include "../myCom/maintimer.h"  //qthread
#include "../myCom/recetimer.h"  //Qthread
MainWindow* g_mainWorkFlow;
UISerial*  g_mSerial;
MainTimer g_mainTimer;
ReceTimer g_receTimer;

nbdpWorkflow *g_nbdpWorkFlow;
QString g_selfMMSI;

int main(int argc, char* argv[])
{
    QApplication a(argc, argv);
#ifdef Q_WS_QWS
    QWSServer::setCursorVisible(ConfigUtils::getCursorVisible());
#else
    if (!ConfigUtils::getCursorVisible())
    {
        a.setOverrideCursor(Qt::BlankCursor);
    }
#endif
    Logging::get()->info("start application");
    QTranslator translator;
    QString path2 = PathResolve::qtTranslationFileName(ConfigUtils::getLanguage());
    qDebug() << path2;
    translator.load(path2);
    a.installTranslator(&translator);

    QFile qssFile(":/qss/style");
    QString qss;
    qssFile.open(QFile::ReadOnly);
    
    if (qssFile.isOpen())
    {
        qss = QString(qssFile.readAll());
        qApp->setStyleSheet(qss);
        qssFile.close();
    }

    NbdpView w;
    w.move((SCREEN_SIZE_WIDTH - w.width()) / 2, (SCREEN_SIZE_HEIGHT - w.height()) / 2);
    w.show();


    //通过对对子窗口调 用：setWindowFlags（Qt::Dialog）；或setWindowFlags（Qt::Window）；将其设为窗口模式后


     g_selfMMSI=w.get_strSelfMMSI();   //每次修改MMSI后需要重启机器


     return a.exec();
}

#include <QThread>
#include <QDateTime>
#include "maintimer.h"
#include "mainwindow.h"

MainTimer::MainTimer(QObject *parent) :
    QThread(parent)
{
    stopped = false;
    m_mSec=0;
}
void MainTimer::run()
{
  QDateTime beginTime=QDateTime::currentDateTime();

  printMessage();
  while(!stopped)
   {
      int msecs=beginTime.msecsTo(QDateTime::currentDateTime());
      if( msecs >= 449 && msecs <=451)
          {
            beginTime=QDateTime::currentDateTime();
            printMessage();

          }
        usleep(1000);
  }
   stopped = false;
}

void MainTimer::stop()
{
   stopped = true;
}

void MainTimer::setMessage(QString message)
{
   messageStr = message;
}

void MainTimer::printMessage()
{
    g_mainWorkFlow->MainTimer_count();

    //msleep(448);
   // usleep(449*1000);
}

#include "recetimer.h"
#include "QThread"
#include "mainwindow.h"


ReceTimer::ReceTimer(QObject *parent) :
    QThread(parent)
{
    stopped = false;
    m_mSec=0;
}
void ReceTimer::run()
{
  while(!stopped)
   {
      printMessage();
  }
   stopped = false;
}

void ReceTimer::stop()
{
   stopped = true;
}

void ReceTimer::setMessage(QString message)
{
   messageStr = message;
}

void ReceTimer::printMessage()
{
    g_mainWorkFlow->ReceTimer_count();

    if(g_mainWorkFlow->ReceTimerCount == 1)
        usleep(138*1000);  //msleep(138);
    else
        usleep(448*1000);  //msleep(448);
}

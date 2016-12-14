#include "scanclass.h"

ScanClass* ScanClass::m_pInstance = 0;

ScanClass::~ScanClass()
{
    m_pInstance = 0;
}

ScanClass* ScanClass::get()
{
    if (0 == m_pInstance)
    {
        m_pInstance = new ScanClass();
    }
    
    return m_pInstance;
}

ScanClass::ScanClass()
{
}

void ScanClass::setIsScan(bool b)
{
    IsScan = b;
}

void ScanClass::setDwellTime(QString str)
{
    dwellTime = str;
}

void ScanClass::setScanMode(QString str)
{
    scanMode = str;
}

QString ScanClass::getDwellTime()
{
    return dwellTime;
}

QString ScanClass::getScanMode()
{
    return scanMode;
}

bool ScanClass::getIsScan()
{
    return IsScan;
}

void ScanClass::setScanGroup(int i)
{
    iScanGroup = i;
}

int ScanClass::getScanGroup()
{
    return iScanGroup;
}

void ScanClass::addChannelInfoClass(ChannelInfoClass cnlic)
{
    cnlicl.append(cnlic);
}

QList<ChannelInfoClass>* ScanClass::getChannelInfoList()
{
    return &cnlicl;
}

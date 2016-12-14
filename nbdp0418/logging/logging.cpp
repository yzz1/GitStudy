#include "logging.h"
#include <QCoreApplication>

Logging* Logging::m_pInstance = 0;

Logging* Logging::get()
{
    if (0 == m_pInstance)
    {
        m_pInstance = new Logging();
    }
    
    return m_pInstance;
}

Logging::Logging()
{
    Log4Qt::BasicConfigurator::configure();
    QString path = QCoreApplication::applicationDirPath() + "/config/log4qt.properties";
    Log4Qt::PropertyConfigurator::configure(path);
    m_pLoggger = Log4Qt::Logger::logger("NBDP");
}

Logging::~Logging()
{
    if (m_pInstance != 0)
    {
        delete m_pInstance;
        m_pInstance = 0;
    }
    
    if (m_pLoggger != 0)
    {
        //delete m_pLoggger;
        //m_pLoggger = 0;
    }
}

void Logging::debug(const QString& message)
{
    m_pLoggger->debug(message);
}

void Logging::info(const QString& message)
{
    m_pLoggger->info(message);
}

void Logging::error(const QString& message)
{
    m_pLoggger->error(message);
}

void Logging::warn(const QString& message)
{
    m_pLoggger->warn(message);
}

void Logging::fatal(const QString& message)
{
    m_pLoggger->fatal(message);
}

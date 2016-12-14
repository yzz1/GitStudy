#ifndef LOGGING_H
#define LOGGING_H

#include "logging_global.h"
#include "log4qt/logger.h"
#include "log4qt/ttcclayout.h"
#include "log4qt/fileappender.h"
#include "log4qt/basicconfigurator.h"
#include "log4qt/propertyconfigurator.h"
#include <QString>

class LOGGINGSHARED_EXPORT Logging
{

    public:
        static Logging* get();
        ~Logging();
        void debug(const QString& message);
        void info(const QString& message);
        void error(const QString& message);
        void warn(const QString& message);
        void fatal(const QString& message);
        
    private:
        Logging();
        static Logging* m_pInstance;
        Log4Qt::Logger* m_pLoggger;
};

#endif // LOGGING_H

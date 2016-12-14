#ifndef SERIALPORTCOMMUNICATION_H
#define SERIALPORTCOMMUNICATION_H
#include <stdio.h>
#include <termios.h>
#include <errno.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/ioctl.h>
#include <sys/select.h>
#include "serialbase.h"

class SerialPortCommunication: public SerialBase
{
    private:
        /*!
         * This method is a part of constructor.
         */
        void init();
        static SerialPortCommunication* m_printer;
    protected:
        QFile* Posix_File;
        struct termios Posix_CommConfig;
        struct timeval Posix_Timeout;
        struct timeval Posix_Copy_Timeout;
        
        
        
    public:
        virtual qint64 readData(char* data, qint64 maxSize);
        virtual qint64 writeData(const char* data, qint64 maxSize);
        SerialPortCommunication();
        SerialPortCommunication(const SerialPortCommunication& s);
        SerialPortCommunication(const QString& name, SerialBase::QueryMode mode = SerialBase::Polling);
        SerialPortCommunication(const PortSettings& settings, SerialBase::QueryMode mode = SerialBase::Polling);
        SerialPortCommunication(const QString& name, const PortSettings& settings,
                                SerialBase::QueryMode mode = SerialBase::Polling);
        SerialPortCommunication& operator=(const SerialPortCommunication& s);
        virtual ~SerialPortCommunication();
        static SerialPortCommunication* get();
        
        
        virtual void setBaudRate(BaudRateType);
        virtual void setDataBits(DataBitsType);
        virtual void setParity(ParityType);
        virtual void setStopBits(StopBitsType);
        virtual void setFlowControl(FlowType);
        virtual void setTimeout(long);
        
        virtual bool open(OpenMode mode);
        virtual void close();
        virtual void flush();
        
        virtual qint64 size() const;
        virtual qint64 bytesAvailable();
        
        virtual void ungetChar(char c);
        
        virtual void translateError(ulong error);
        
        virtual void setDtr(bool set = true);
        virtual void setRts(bool set = true);
        virtual ulong lineStatus();
        
};

#endif // SERIALPORTCOMMUNICATION_H

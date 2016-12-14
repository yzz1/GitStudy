#ifndef MANAGERFILESTYLE
#define MANAGERFILESTYLE

#include <QWidget>
#include <QColor>
#include <views/contacts/contactsstyle.h>

class ManagerFileStyle : public ContactsStyle
{
        Q_OBJECT
        Q_PROPERTY(int dateFormatColIndex  READ getDateFormatColIndex  WRITE setDateFormatColIndex DESIGNABLE true SCRIPTABLE
                   true)
        Q_PROPERTY(QString dateFormat READ getDateFormat  WRITE setDateFormat  DESIGNABLE true SCRIPTABLE true)
        Q_PROPERTY(QString selectedPixmap  READ getSelectedPixmap WRITE setSelectedPixmap DESIGNABLE true SCRIPTABLE true)
        Q_PROPERTY(QString checkNoPixmap  READ getCheckNoPixmap WRITE setCheckNoPixmap DESIGNABLE true SCRIPTABLE true)
        Q_PROPERTY(QString checkYesPixmap  READ getCheckYesPixmap WRITE setCheckYesPixmap DESIGNABLE true SCRIPTABLE true)
        Q_PROPERTY(QString checkSelYesPixmap  READ getCheckSelYesPixmap WRITE setCheckSelYesPixmap DESIGNABLE true SCRIPTABLE
                   true)
        Q_PROPERTY(QString checkSelNoPixmap  READ getCheckSelNoPixmap WRITE setCheckSelNoPixmap DESIGNABLE true SCRIPTABLE true)
        Q_PROPERTY(QColor msContentBgColor READ getMsContentBgColor WRITE setMsContentBgColor DESIGNABLE true SCRIPTABLE true)
    public:
        ManagerFileStyle(QWidget* parent = 0);
        
        Q_INVOKABLE    int  getDateFormatColIndex() {return m_dateFormatColIndex;}
        Q_INVOKABLE    QString  getDateFormat() {return m_dateFormat;}
        Q_INVOKABLE    QString  getCheckNoPixmap() {return m_checkNoPixmap;}
        Q_INVOKABLE    QString  getCheckYesPixmap() {return m_checkYesPixmap;}
        Q_INVOKABLE    QString  getCheckSelYesPixmap() {return m_checkSelYesPixmap;}
        Q_INVOKABLE    QString  getCheckSelNoPixmap() {return m_checkSelNoPixmap;}
        Q_INVOKABLE    QColor   getMsContentBgColor() {return m_msContentBgColor;}
        
        Q_INVOKABLE    void  setDateFormatColIndex(int dateFormatColIndex) {m_dateFormatColIndex =  dateFormatColIndex;}
        Q_INVOKABLE    void  setDateFormat(QString dateFormat) {m_dateFormat = dateFormat;}
        Q_INVOKABLE    void  setCheckNoPixmap(QString checkNoPixmap) {m_checkNoPixmap = checkNoPixmap;}
        Q_INVOKABLE    void  setCheckYesPixmap(QString checkYesPixmap) {m_checkYesPixmap = checkYesPixmap;}
        Q_INVOKABLE    void  setCheckSelYesPixmap(QString checkSelYesPixmap) {m_checkSelYesPixmap =  checkSelYesPixmap;}
        Q_INVOKABLE    void  setCheckSelNoPixmap(QString checkSelNoPixmap) {m_checkSelNoPixmap = checkSelNoPixmap;}
        Q_INVOKABLE    void  setMsContentBgColor(QColor msContentBgColor) {m_msContentBgColor = msContentBgColor;}
        
        
    private:
        QString m_dateFormat;
        int   m_dateFormatColIndex;
        QString m_checkNoPixmap;
        QString m_checkYesPixmap;
        QString m_checkSelYesPixmap;
        QString m_checkSelNoPixmap;
        QColor  m_msContentBgColor;
};

#endif // MANAGERFILESTYLE


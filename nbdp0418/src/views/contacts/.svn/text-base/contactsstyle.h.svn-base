#ifndef CONTACTSSTYLE_H
#define CONTACTSSTYLE_H
#include <QString>
#include <QWidget>

class ContactsStyle : public QWidget
{
        Q_OBJECT
        
        Q_PROPERTY(QString selectedPixmap  READ getSelectedPixmap WRITE setSelectedPixmap DESIGNABLE true SCRIPTABLE true)
        Q_PROPERTY(QString noSelectedPixmap  READ getNoSelectedPixmap WRITE setNoSelectedPixmap DESIGNABLE true SCRIPTABLE true)
        Q_PROPERTY(int selectedFontSize  READ getSelectedFontSize WRITE setSelectedFontSize DESIGNABLE true SCRIPTABLE true)
        Q_PROPERTY(int pixmapColummIndex  READ getPixmapColummIndex WRITE setPixmapColummIndex DESIGNABLE true SCRIPTABLE true)
        Q_PROPERTY(QColor selectedFontColor READ getSelectedFontColor WRITE setSelectedFontColor DESIGNABLE true SCRIPTABLE
                   true)
                   
    public:
        ContactsStyle(QWidget* parent = 0);
        Q_INVOKABLE    QString getSelectedPixmap() {return m_selectedPixmap;}
        Q_INVOKABLE    QString getNoSelectedPixmap() {return m_noSelectedPixmap;}
        Q_INVOKABLE    int getSelectedFontSize() {return m_selectedFontSize;}
        Q_INVOKABLE    int getPixmapColummIndex() {return m_pixmapColummIndex;}
        Q_INVOKABLE    QColor getSelectedFontColor() {return m_selectedFontColor;}
        Q_INVOKABLE     void setSelectedPixmap(QString strResourceURL);
        Q_INVOKABLE    void setNoSelectedPixmap(QString strResourceURL);
        Q_INVOKABLE    void setSelectedFontSize(int  intFontSize);
        Q_INVOKABLE    void setPixmapColummIndex(int  intPixmapColummIndex);
        Q_INVOKABLE    void setSelectedFontColor(QColor  strSelectedFontColor);
    private:
        QString m_selectedPixmap;
        QString m_noSelectedPixmap;
        int   m_selectedFontSize;
        QColor  m_selectedFontColor;
        int   m_pixmapColummIndex;
};

#endif // CONTACTSSTYLE_H

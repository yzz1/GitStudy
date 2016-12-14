#ifndef SHORTCUTMANAGER_H
#define SHORTCUTMANAGER_H

#include <QStringList>
#include <QObject>

class CAction;

class ShortCutManager : public QObject
{
        Q_OBJECT
    public:
        ShortCutManager();
        bool registerShortCut(int ShortCut);
    private:
        QStringList a;
};

class ShortCutMap
{
    public:
        ShortCutMap();
        ~ShortCutMap();
        bool addShortCut();
};

#endif // SHORTCUTMANAGER_H

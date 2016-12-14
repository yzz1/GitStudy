#ifndef GLOBALARRAY_H
#define GLOBALARRAY_H

#include <QMap>
#include <QString>
class GlobalArray
{
public:
    GlobalArray();
//private:
    QMap<int,QString> mapRToIS;
    QMap<QString,int> mapIsToN;
    QMap<int,QString> mapCNToCK;
    QMap<int,QString> mapFourMMSI;
    QMap<int,QString> mapFiveMMSIAdd;
    QMap<int,QString> mapFiveToFour;
    QMap<QString,int> mapLetterToNum;
    QMap<QString,int> mapSwitchLetterAndNum;
    //QMap<QString,int> mapNumToNum;

    QString CS1; QString CS2; QString CS3;
    QString CS4;
    //QString CS5;
    QString beta;
    QString alpha; QString RQ;
    QString RQ_RQ_RQ;
    QString alphaAlphaAlpha;
    QString betaAlphaBeta;

};

#endif // GLOBALARRAY_H

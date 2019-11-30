#ifndef STATISTICMANAGER_H
#define STATISTICMANAGER_H
#include<QVector>
#include "evm.h"
class StatisticManager
{
protected:
    QVector<QVector<int>> infomodelling;
    int numbertact;
    int timework;
    int tact;
public:
    StatisticManager(int,int);
    void tic();
    int getinfomodeling(int,int);
    void addclients(WeatherD* WeatherD);
};

#endif // STATISTICMANAGER_H

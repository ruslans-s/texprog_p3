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
    void StatisticManagers(int,int);
    void tic();
    QVector<QVector<int>> getinfomodeling();
    void addclients(WeatherD WeatherD);
};

#endif // STATISTICMANAGER_H

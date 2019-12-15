#ifndef STATISTICMANAGER_H
#define STATISTICMANAGER_H
#include<QVector>
#include "evm.h"
class StatisticManager
{
protected:
    QVector<QVector<int>> infomodelling;
    QVector<QVector<int>> information;
    int numbertact;
    int timework;
    int tact;
    int processed;
    int noProcessed;
public:
    void StatisticManagers(int,int);
    void tic();
    QVector<QVector<int>> getinfomodeling();
    void addclients(WeatherD WeatherD);
    void informationalTic(int,int,int,int);
    QVector<QVector<int>> getinformation();
};

#endif // STATISTICMANAGER_H

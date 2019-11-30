#ifndef MANAGER_H
#define MANAGER_H
#include<QVector>
#include "evm.h"
#include "generator.h"
#include "queue.h"
#include "statisticmanager.h"
#include "valve.h"
#include "weatherd.h"
class manager
{
protected:
    int timework;
    Generator* Generator;
    QVector<valve> ValveList;
    QVector<evm> EVMlist;
    QVector<WeatherD> WeatherDlist;
     StatisticManager* StatisticManager;
    int numberWeatherD;
    int tact;
    int numberEVM=2;
    int numberValve=3;
public:
    manager(int,int,QVector<int>);
};

#endif // MANAGER_H
//время работы, длительность такта,  время работы эвм,

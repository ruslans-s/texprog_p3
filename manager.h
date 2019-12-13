#ifndef MANAGER_H
#define MANAGER_H

#include "evm.h"
#include "generator.h"
#include "queue.h"
#include "statisticmanager.h"
#include "valve.h"
#include "weatherd.h"
#include<QVector>
class manager
{
protected:
    int timework;
   // Generator *Generator;
  //  StatisticManager *StatisticManager;
    QVector<valve> ValveList;
    QVector<evm> EVMlist;
    QVector<WeatherD> WeatherDlist;
    QVector<int> timeworkevm;
    QVector<QString> logText;
    int numberWeatherD;
    int intensyt;
    int numberEVM=2;
    int numberValve=3;
    Generator Generators;
    queue Queues;
public:
    manager();
    void settings(int,int,QVector<int>);
    bool startModel();
    QVector<QString> getLog();
};

#endif // MANAGER_H
//время работы, длительность такта,  время работы эвм,

#ifndef EVM_H
#define EVM_H
#include "weatherd.h"
#include "statisticmanager.h"
#include <chrono>
#include <thread>
#include <random>
class evm
{
protected:
    bool busy; //Занят или нет
    int averegeProcessinTime; // Среднее время работы
    int processinTime;
    int tact; //Длительность такта
    int workingtime; //Время работы с текущим клиентом
    WeatherD WeatherDt;
    bool timeEVM; //Нужно увеличивать время ожидания заявки если она в обработчике
    int waitTime;
    int processed;
    int tactNoBusy;
     //StatisticManager StatisticManagers;
public:
    evm();
    void setsetting(int,int,bool,int);
    void newWeatherD(WeatherD newWeatherD);
    bool chekBusy();
    bool tic();
    WeatherD deleteweatherd();
    WeatherD chekTimeDelete();
    bool chekTime();
    int countProcessed();
    int getTactNoBusy();

};

#endif // EVM_H

/*
Исправить название переменных
и сдавать 4 вместе с 5, что код в 5 и 4 был одинаков
Написать взаимодействие методов. Т.е. как они взаимодействуют
*/

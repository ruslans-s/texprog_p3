#ifndef EVM_H
#define EVM_H
#include "weatherd.h"
#include "statisticmanager.h"
class evm
{
protected:
    bool busy; //Занят или нет
    int processinTime; //Время работы
    int tact; //Длительность такта
    int workingtime; //Время работы с текущим клиентом
     WeatherD WeatherDt;
public:
    evm();
    void setsetting(int,int);
    void newWeatherD(WeatherD newWeatherD);
    bool chekBusy();
    void tic();
    void deleteweatherd();
};

#endif // EVM_H

/*
Исправить название переменных
и сдавать 4 вместе с 5, что код в 5 и 4 был одинаков
Написать взаимодействие методов. Т.е. как они взаимодействуют
*/

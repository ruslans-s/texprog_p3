#ifndef QUEUE_H
#define QUEUE_H
#include<QVector>
#include "weatherd.h"
#include "valve.h"
class queue
{
protected:
    QVector<WeatherD> WeatherDlist;
    WeatherD WeatherDs;
public:
    queue();
    bool chekWeatherD();
    int numberWeatherD();
    void addWeatherD();
    bool removeWeatherD();
    void tic();
    WeatherD getFirstWeatherD();
};

#endif // QUEUE_H

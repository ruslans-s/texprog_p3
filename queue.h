#ifndef QUEUE_H
#define QUEUE_H
#include<QVector>
#include "weatherd.h"
class queue
{
protected:
    QVector<WeatherD> WeatherDlist;
public:
    queue();
    bool chekWeatherD();
    int numberWeatherD();
    bool addWeatherD(WeatherD);
    bool removeWeatherD();
};

#endif // QUEUE_H

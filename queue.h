#ifndef QUEUE_H
#define QUEUE_H
#include<QVector>
#include "weatherd.h"
#include "valve.h"
class queue
{
protected:
    QVector<WeatherD> WeatherDlist;
public:
    queue();
    bool chekWeatherD();
    int numberWeatherD();
    void addWeatherD();
    bool removeWeatherD();
    void tic(QVector<valve>);
};

#endif // QUEUE_H
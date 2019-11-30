#ifndef GENERATOR_H
#define GENERATOR_H
#include "queue.h"


class Generator
{
protected:
    int timetocreate;
    int tact;
    int intensity;
    WeatherD* WeatherD;
public:
    Generator(int,int);
    void tic();
};

#endif // GENERATOR_H

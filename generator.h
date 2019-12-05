#ifndef GENERATOR_H
#define GENERATOR_H
#include "queue.h"
#include "stdlib.h"
#include "time.h"
#include <math.h>
#include <iostream>
#include <chrono>
#include <random>
#include "weatherd.h"
queue *queue;
class Generator
{
protected:
    int timetocreate;
    int tact;
    int numbercycles;
    int intensity;
    WeatherD *WeatherDs;
    QVector<int> poissonAp;
public:
    Generator(int,int);
    void tic();
};

#endif // GENERATOR_H

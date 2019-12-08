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

class Generator
{
protected:
    int timetocreate;
    int tact;
    int numbercycles=0;
    int intensity;
    WeatherD *WeatherDs;
    QVector<int> poissonAp;
    queue queue;

public:
    void generator(int,int);
    void tic();
};

#endif // GENERATOR_H

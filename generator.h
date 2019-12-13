#ifndef GENERATOR_H
#define GENERATOR_H
#include "mainwindow.h"
#include "stdlib.h"
#include "time.h"
#include <math.h>
#include <iostream>
#include <chrono>
#include <random>
#include <QVector>
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
   // queue queue;
    int timeWork;
public:
    QVector<int> getVec();
    void generator(int,int,int);
    int tic();
};

#endif // GENERATOR_H

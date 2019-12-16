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
#include <random>
#include<QString>
#include<math.h>
#include <chrono>
#include <thread>
#include <random>

class Generator
{
protected:
    int numbercycles=0;
    int intensity;
    WeatherD *WeatherDs;
    QVector<int> poissonAp;
    int timeWork;
public:
    QVector<int> getVec();
    void generator(int,int);
    int tic();
};

#endif // GENERATOR_H

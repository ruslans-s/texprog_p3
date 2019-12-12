#include "generator.h"
#include "stdlib.h"
#include "time.h"
#include <math.h>
#include <iostream>

void Generator::generator(int newintensity, int newtact,int newTimeWork){
    intensity = newintensity;
    tact = newtact;
    //int kol=20;
    timeWork=newTimeWork;
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine generator (seed);
    std::poisson_distribution<int> distribution (intensity);
    int summ=0,temp;
    for (int i=0; i<timeWork-1; ++i){
     poissonAp.push_back(distribution(generator));
      summ+=temp;
    }
}

QVector<int> Generator::getVec(){
return poissonAp;
}

void Generator::tic(){
    numbercycles++;
    int tempinc;
    while(poissonAp[numbercycles]>tempinc){
    queue.addWeatherD();
    tempinc++;
    }
}

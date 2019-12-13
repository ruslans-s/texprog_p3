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
   // int summ=0,temp;
    for (int i=1; i<=timeWork; ++i){
     poissonAp.push_back(distribution(generator));
     // summ+=temp;
    }
}

QVector<int> Generator::getVec(){
return poissonAp;
}
int Generator::tic(){
    numbercycles++;
    if (numbercycles>poissonAp.size()-1) numbercycles--;
 //   int tempinc;
 //  for(int i=0;i<=poissonAp[numbercycles];i++)  queue.addWeatherD();
return poissonAp[numbercycles-1];

}

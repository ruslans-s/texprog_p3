#include "generator.h"
#include "stdlib.h"
#include "time.h"
#include <math.h>
#include <iostream>

void Generator::generator(int newintensity, int newtact){
    intensity = newintensity;
    tact = newtact;
    int kol=20;
    poissonAp={1,2,3,0,1,3,4,5,0,2};
}
void Generator::tic(){
    numbercycles++;
    int tempinc;
    while(poissonAp[numbercycles]>tempinc){
    queue.addWeatherD();
    tempinc++;
    }
}

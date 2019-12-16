#include "generator.h"
#include <chrono>
#include <thread>
#include <random>
using namespace std;

void Generator::generator(int newintensity, int newTimeWork){
    intensity = newintensity;
    timeWork=newTimeWork;
    int seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine generator (seed);
    std::exponential_distribution<double> distribution (0.033);

  for (int i=1; i<=timeWork; ++i){
    poissonAp.push_back((int)ceil(distribution(generator)));

       }
}

QVector<int> Generator::getVec(){
return poissonAp;
}

int Generator::tic(){
    numbercycles++;
return poissonAp[numbercycles-1];
}

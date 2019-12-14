#include "generator.h"
#include <chrono>
#include <thread>
#include <random>
using namespace std;

void Generator::generator(int newintensity, int newtact,int newTimeWork){
    intensity = newintensity;
    tact = newtact;
    int kol=20;
    timeWork=newTimeWork;
//    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
//    std::default_random_engine generator (seed);
//    std::poisson_distribution<int> distribution (intensity/2);
//   // int summ=0,temp;
//    for (int i=1; i<=timeWork; ++i){
//     poissonAp.push_back(distribution(generator));
//     // summ+=temp;
//    }

    int seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine generator (seed);
    std::exponential_distribution<double> distribution (0.033);

  for (int i=1; i<=timeWork; ++i){
    poissonAp.push_back((int)ceil(distribution(generator)));

        // summ+=temp;
       }




}

QVector<int> Generator::getVec(){
return poissonAp;
}
int Generator::tic(){
    numbercycles++;

//    int temp=(int)ceil(distribution(generator));

//      // std::cout << "beep!" << std::endl;
//      return temp;

//return po;




//    if (numbercycles>poissonAp.size()-1) numbercycles--;
 //  int tempinc;
   //for(int i=0;i<=poissonAp[numbercycles];i++)  queue.addWeatherD();
return poissonAp[numbercycles-1];

}

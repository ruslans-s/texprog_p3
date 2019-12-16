#include "evm.h"
#include "statisticmanager.h"
evm::evm()
{
};
void evm::setsetting(int newprocessingTime, int newtact,bool newTimeEVM,int newWaitTime){
    averegeProcessinTime = newprocessingTime;
    tact = newtact;
    busy=false;
    timeEVM=newTimeEVM;
    waitTime=newWaitTime;
    processed=0;
    processinTime=-5;
    tactNoBusy=1;
  //  WeatherDt();
}
void evm::newWeatherD(WeatherD newWeatherD) {
    WeatherDt = newWeatherD;
    busy=true;
    workingtime=0;

//Генерирование случайного времени обработки 1 заявки
    int seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine generator (seed);
    float as=1,bs=60*averegeProcessinTime;
    std::exponential_distribution<double> distribution (as/bs);
    processinTime= (int)ceil(distribution(generator));
    if(processinTime==0) processinTime=1;


};
bool evm::chekBusy() {
    return busy;
};
bool evm::tic(){
    if (timeEVM==true){
        WeatherDt.tic();
    }
   if (busy==true) {
       workingtime++;
       tactNoBusy++;
    //   WeatherDt.tic();
   }
   if(processinTime==workingtime){
       return true;
   } else {
       return false;
   }

}
WeatherD evm::deleteweatherd(){
    busy=false;
    WeatherDt.setSucces();
    workingtime=0;
    processed++;
   return WeatherDt;
}
WeatherD evm::chekTimeDelete(){
       busy=false;
       return WeatherDt;
}
bool evm::chekTime(){
     if(WeatherDt.getwaitingtime()>waitTime && busy==true){
         return true;
     }else{
         return false;
     }
}
int evm::countProcessed(){
    return processed;
}
int evm::getTactNoBusy(){
    return tactNoBusy;
}

#include "evm.h"
#include "statisticmanager.h"
evm::evm()
{

};
void evm::setsetting(int newprocessingTime, int newtact){
    processinTime = newprocessingTime;
    tact = newtact;
    busy=false;
}
void evm::newWeatherD(WeatherD newWeatherD) {
    WeatherDt = newWeatherD;
    busy=true;
    workingtime=0;
};
bool evm::chekBusy() {
    return busy;
};
void evm::tic(){
  //  processinTime++;
    if (busy==true)  workingtime++;
   if(processinTime==workingtime){
       deleteweatherd();
   }
}
void evm::deleteweatherd(){
    busy=false;
    //StatisticManager.addclients(WeatherDt);
   // return WeatherDt;
}

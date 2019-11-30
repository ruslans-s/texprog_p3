#include "evm.h"
#include "statisticmanager.h"
evm::evm()
{

};
void evm::setsetting(int newprocessingTime, int newtact){
    processinTime = newprocessingTime;
    tact = newtact;
}
void evm::newWeatherD(WeatherD* newWeatherD) {
    WeatherDt = newWeatherD;
    busy=true;
};
bool evm::chekBusy() {
    return busy;
};
void evm::tic(){
    processinTime++;
    if (busy==true)  workingtime++;
}
void evm::deleteweatherd(){
    busy=false;
    //StatisticManager.addclients(WeatherDt);
   // return WeatherDt;
}

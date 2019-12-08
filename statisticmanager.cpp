#include "statisticmanager.h"

void StatisticManager::StatisticManagers(int ntact,int ntimework)
{
    tact=ntact;
    timework=ntimework;
}
void StatisticManager::tic(){
    numbertact++;
}

//StatisticManager(int,int,QVector<evm> EVM);
int StatisticManager::getinfomodeling(int tact ,int col){
    return infomodelling[tact][col];
}

void StatisticManager::addclients(WeatherD WeatherDs){
       infomodelling.resize(infomodelling.size()+1);
       infomodelling[infomodelling.size()-1].resize(3);
       infomodelling[infomodelling.size()-1][0]=numbertact;
       if (WeatherDs.cheksucces()==true){
           infomodelling[infomodelling.size()-1][1]=1;
       } else infomodelling[infomodelling.size()-1][1]=0;
       infomodelling[infomodelling.size()-1][2]=WeatherDs.getwaitingtime();
}

#include "statisticmanager.h"

void StatisticManager::StatisticManagers(int ntact,int ntimework)
{
    tact=ntact;
    timework=ntimework;
    numbertact=1;
}
void StatisticManager::tic(){
    numbertact++;
   // infomodelling.resize(infomodelling.size()+1);
}

//StatisticManager(int,int,QVector<evm> EVM);
QVector<QVector<int>> StatisticManager::getinfomodeling(){
    return infomodelling;
}

void StatisticManager::addclients(WeatherD WeatherDs){

       infomodelling.resize(infomodelling.size()+1);
       int sizeInfoModellingVec=infomodelling.size()-1;
       infomodelling[sizeInfoModellingVec].resize(3);
       infomodelling[sizeInfoModellingVec][0]=numbertact;
       if (WeatherDs.cheksucces()==true){
           infomodelling[sizeInfoModellingVec][1]=1;
       } else infomodelling[sizeInfoModellingVec][1]=0;
       infomodelling[sizeInfoModellingVec][2]=WeatherDs.getwaitingtime();
}

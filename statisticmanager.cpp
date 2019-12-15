#include "statisticmanager.h"

void StatisticManager::StatisticManagers(int ntact,int ntimework)
{
    tact=ntact;
    timework=ntimework;
    numbertact=1;
    processed=0;
    noProcessed=0;
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
           processed++;
       } else {
           infomodelling[sizeInfoModellingVec][1]=0;
       noProcessed++;
       }
       infomodelling[sizeInfoModellingVec][2]=WeatherDs.getwaitingtime();
}
void StatisticManager::informationalTic(int numberTact, int countWeatherD, int processedEVM1, int processedEVM2){
QVector<int> tempVec;
information.resize(information.size()+1);
int infoSieze=information.size()-1;
information[infoSieze].resize(6);
information[infoSieze][0]=numberTact;
information[infoSieze][1]=countWeatherD;
information[infoSieze][2]=processed;
information[infoSieze][3]=noProcessed;
information[infoSieze][4]=processedEVM1;
information[infoSieze][5]=processedEVM2;
//information.push_back(tempVec);
}
QVector<QVector<int>> StatisticManager::getinformation(){
    return information;
}

#include "manager.h"

manager::manager(){
}
void manager::settings(int newtimework,int nintensyt, QVector<int> newtimeworkEvm, int newShelfLife,bool newTimeEVM)
{
timeEVM=newTimeEVM;
timework=newtimework;
intensyt=nintensyt;
shelfLife=newShelfLife;
//timeworkevm=newtimeworkEvm;
//EVMlist.resize(2);
for(int i=0;i<=newtimeworkEvm.size()-1;i++){
   EVMlist.resize(EVMlist.size()+1);
   EVMlist[i].setsetting(newtimeworkEvm[i],1,timeEVM,shelfLife);
}
ValveList.resize(3);
}
bool manager::startModel(){
Generators.generator(intensyt,1,timework);
StatisticManagers.StatisticManagers(1,timework);
int f;
bool allBusy,evmSucess1=false,evmSucess2=false;
ValveList[0].setTimeCheker();
ValveList[0].getwaittime(shelfLife);
ValveList[1].open();
ValveList[2].open();
for(int i=1;i<=timework-1;i++){
    //Проверка на время ожидания в обработчике
    if(timeEVM==true){
        if(EVMlist[0].chekTime()==true){
            StatisticManagers.addclients(EVMlist[0].chekTimeDelete());
             logText.push_back(QString::number(i)+" Заявка была удалена с эвм 1 из-за слишком большаго времени ожидания");
        }
        if(EVMlist[1].chekTime()==true){
            StatisticManagers.addclients(EVMlist[1].chekTimeDelete());
             logText.push_back(QString::number(i)+" Заявка была удалена с эвм 2 из-за слишком большаго времени ожидания");
        }
    }
    //Проверка на то что обработчики закончили работу
    if(evmSucess1==true){
        StatisticManagers.addclients(EVMlist[0].deleteweatherd());
        logText.push_back(QString::number(i)+" ЭВМ 1 закончила обработку и удалила заявку");
    }
    if(evmSucess2==true){
        StatisticManagers.addclients(EVMlist[1].deleteweatherd());
        logText.push_back(QString::number(i)+" ЭВМ 2 закончила обработку и удалила заявку");
    }


    f=0;
    for(int r1=0;r1<Generators.tic();r1++){
        Queues.addWeatherD();
        f++;
    }
    logText.push_back(QString::number(i)+" Добавлено заявок: "+QString::number(f));
    ValveList[0].close();
    if(Queues.numberWeatherD()!=0){
      //   ui->logView->addItem("Заявка 213123удалена");
        ValveList[0].chekwaittime((Queues.getFirstWeatherD()).getwaitingtime());
        if(ValveList[0].chekopened()){//Удаляем заявку если прошло более 10 часов
            StatisticManagers.addclients(Queues.getFirstWeatherD());
            Queues.removeWeatherD();
    //        ui->logView->addItem("Заявка удалена");
             logText.push_back(QString::number(i)+" Заявка удалена из-за сликом большого времени ожидания");
        }


    if(EVMlist[0].chekBusy()==false){
        ValveList[1].open();
    }else{
        ValveList[1].close();
    }
    if(EVMlist[1].chekBusy()==false){
        ValveList[2].open();
    }else{
        ValveList[2].close();
    }

    allBusy=false;
    if((ValveList[1].chekopened()==false && ValveList[2].chekopened()==false) || Queues.numberWeatherD()==0) allBusy=true;
    while (allBusy==false) {
        // logText.push_back(QString::number(i)+" Добавленно в 15123123 эвм");
        if((ValveList[1].chekopened())==true){
            EVMlist[0].newWeatherD(Queues.getFirstWeatherD());
            Queues.removeWeatherD();
            ValveList[1].close();
            logText.push_back(QString::number(i)+" Добавленно в 1 эвм");
        }
     if((ValveList[1].chekopened()==false && ValveList[2].chekopened()==false) || Queues.numberWeatherD()==0) break;
        if(ValveList[2].chekopened()==true){
            EVMlist[1].newWeatherD(Queues.getFirstWeatherD());
            Queues.removeWeatherD();
            ValveList[2].close();
            logText.push_back(QString::number(i)+" Добавленно в 2 эвм");
        }
    if((ValveList[1].chekopened()==false && ValveList[2].chekopened()==false )|| Queues.numberWeatherD()==0) allBusy=true;
    }  }
Queues.tic();
StatisticManagers.tic();

evmSucess1=EVMlist[0].tic();
evmSucess2=EVMlist[1].tic();

logText.push_back(QString::number(Queues.numberWeatherD())+" Кол-во заявок");
}}

QVector<QString> manager::getLog(){
    return logText;
}
QVector<QVector<int>> manager::getInfoModelling(){
    return StatisticManagers.getinfomodeling();
}


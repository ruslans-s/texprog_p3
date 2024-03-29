#include "manager.h"

manager::manager(int newtimework,int nintensyt, QVector<int> newtimeworkEvm, int newShelfLife,bool newTimeEVM,int newTact){
    timeEVM=newTimeEVM;
    timework=newtimework;
    intensyt=nintensyt;
    shelfLife=newShelfLife;
    tact=newTact;
    //timeworkevm=newtimeworkEvm;
    //EVMlist.resize(2);
    for(int i=0;i<newtimeworkEvm.size();i++){
       EVMlist.resize(EVMlist.size()+1);
       EVMlist[i].setsetting(newtimeworkEvm[i],1,timeEVM,shelfLife);
    }
    ValveList.resize(3);
}
//void manager::settings(int newtimework,int nintensyt, QVector<int> newtimeworkEvm, int newShelfLife,bool newTimeEVM,int newTact)
//{
//timeEVM=newTimeEVM;
//timework=newtimework;
//intensyt=nintensyt;
//shelfLife=newShelfLife;
//tact=newTact;
//timeworkevm=newtimeworkEvm;
//EVMlist.resize(2);
//for(int i=0;i<=newtimeworkEvm.size()-1;i++){
//   EVMlist.resize(EVMlist.size()+1);
//   EVMlist[i].setsetting(newtimeworkEvm[i],1,timeEVM,shelfLife);
//}
//ValveList.resize(3);
//}
void manager::startModel(){
Generators.generator(intensyt,timework);
StatisticManagers.StatisticManagers(1,timework);
int tempInt=0,tempInt2=0,temptact=1;
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



if(tempInt==tempInt2){ //Добавление заявки
      Queues.addWeatherD();
      logText.push_back(QString::number(i)+" Добавлено заявка");
      tempInt2=0;
      tempInt=Generators.tic();
} else {
    tempInt2++;
}



    ValveList[0].close();
    if(Queues.numberWeatherD()>0){//Если количество заявок в очереди не равно 0 то начинается работа с заявками
        logText.push_back(QString::number(Queues.numberWeatherD())+" Заявка удалена из-за сликом большого времени ожидания");
        ValveList[0].chekwaittime((Queues.getFirstWeatherD()).getwaitingtime()); //Работа с 0 клапаном для проверки времени ожидания заявки
        if(ValveList[0].chekopened()){//Удаляем заявку если прошло более 10 часов
            StatisticManagers.addclients(Queues.getFirstWeatherD());
            Queues.removeWeatherD();
             logText.push_back(QString::number(i)+" Заявка удалена из-за сликом большого времени ожидания");
        }

    //Установка клапанов в необходимые положения
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
    while (allBusy==false) {//Добавление заявок в обработчики

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

Queues.tic(); // Увеличение системного времени в классах на 1 шаг
StatisticManagers.tic();
evmSucess1=EVMlist[0].tic();
evmSucess2=EVMlist[1].tic();


if(temptact==tact){
StatisticManagers.informationalTic(i,Queues.numberWeatherD(),EVMlist[0].countProcessed(),EVMlist[1].countProcessed());
temptact=0;
}else{
    temptact++;
}

if((EVMlist[0].chekBusy()==false && EVMlist[1].chekBusy()==false)){
    busy1++;
}
if((EVMlist[0].chekBusy()==false && EVMlist[1].chekBusy()==true)||(EVMlist[1].chekBusy()==false && EVMlist[0].chekBusy()==true)){
    busy2++;
}

}
logText.push_back(QString::number(busy1)+" Количество тактов когда обе эвм простаивают");
logText.push_back(QString::number(busy2)+" Количество тактов когда одна эвм простаивает");
StatisticManagers.informationalTic(timework-1,Queues.numberWeatherD(),EVMlist[0].countProcessed(),EVMlist[1].countProcessed());
}

QVector<QString> manager::getLog(){
    return logText;
}
QVector<QVector<int>> manager::getInfoModelling(){
    return StatisticManagers.getinfomodeling();
}
QVector<QVector<int>> manager::getInformation(){
    return StatisticManagers.getinformation();
}
QVector<int> manager::getBusyInfo(){
    return {busy1,busy2};
}

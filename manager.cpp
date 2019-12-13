#include "manager.h"

manager::manager(){
}
void manager::settings(int newtimework,int nintensyt, QVector<int> newtimeworkEvm)
{

timework=newtimework;
intensyt=nintensyt;
//timeworkevm=newtimeworkEvm;
//EVMlist.resize(2);
for(int i=0;i<=newtimeworkEvm.size()-1;i++){
   EVMlist.resize(EVMlist.size()+1);
   EVMlist[i].setsetting(newtimeworkEvm[i],1);
}
ValveList.resize(3);
}
bool manager::startModel(){
Generators.generator(intensyt,1,timework);
int f;
bool allBusy;
ValveList[0].setTimeCheker();
ValveList[0].getwaittime(10);
ValveList[1].open();
ValveList[2].open();
for(int i=1;i<=timework-1;i++){
    f=0;
    for(int r1=0;r1<Generators.tic();r1++){
        Queues.addWeatherD();
        f++;
    }
    logText.push_back(QString::number(i)+"Добавлено"+QString::number(f));
    ValveList[0].close();
    if(Queues.chekWeatherD()==true){
      //   ui->logView->addItem("Заявка 213123удалена");
        ValveList[0].chekwaittime((Queues.getFirstWeatherD()).getwaitingtime());
        if(ValveList[0].chekopened()){//Удаляем заявку если прошло более 10 часов
           // StatisticManager.addclients(queue.getFirstWeatherD());
            Queues.removeWeatherD();
    //        ui->logView->addItem("Заявка удалена");
             logText.push_back(QString::number(i)+"Удалена");
        }
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
    if(ValveList[1].chekopened()==false && ValveList[2].chekopened()==false) allBusy=true;
    while (allBusy==false) {
        // logText.push_back(QString::number(i)+"Добавленно в 15123123 эвм");
        if((ValveList[1].chekopened())==true){
            EVMlist[0].newWeatherD(Queues.getFirstWeatherD());
            Queues.removeWeatherD();
            ValveList[1].close();
            logText.push_back(QString::number(i)+"Добавленно в 1 эвм");
        }
        if(ValveList[2].chekopened()==true){
            EVMlist[1].newWeatherD(Queues.getFirstWeatherD());
            Queues.removeWeatherD();
            ValveList[2].close();
            logText.push_back(QString::number(i)+"Добавленно в 2 эвм");
        }
    if(ValveList[1].chekopened()==false && ValveList[2].chekopened()==false) allBusy=true;
    }
Queues.tic();
EVMlist[0].tic();
EVMlist[1].tic();
}}

QVector<QString> manager::getLog(){
    return logText;
}


#include "mainwindow.h"
#include "ui_mainwindow.h"
//#include "manager.h"
#include "generator.h"

#include "evm.h"

#include "queue.h"
#include "statisticmanager.h"
#include "valve.h"
#include "weatherd.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
ui->logView->clear();
Generator Generatr;
queue queue;
StatisticManager StatisticManager;
valve valves;
QVector<valve> valveList;
//manager *newManager;

int tact=10;
int timework=9;
int valvCount=3;
valveList.resize(valvCount);
valveList[0].setTimeCheker();
valveList[0].getwaittime(10);
QVector<int> timeWorkEvm={1,5};
int numbercycle=0;
//newManager->settings(timework,tact,timeWorkEvm);
//Generatr.generator(tact,timework);
Generatr.generator(3,1,24);
QVector<int> poisson=Generatr.getVec();
for(int i=0;i<=poisson.size()-1;i++)
{
    ui->logView->addItem(QString::number(poisson[i]));
}
while(numbercycle<timework){
Generatr.tic();
queue.tic();

valveList[0].close();
if(queue.chekWeatherD()){
    valveList[0].chekwaittime((queue.getFirstWeatherD()).getwaitingtime());
    if(valveList[0].chekopened()){//Удаляем заявку если прошло более 10 часов
        StatisticManager.addclients(queue.getFirstWeatherD());
        queue.removeWeatherD();
        ui->logView->addItem("Заявка удалена");
    }


}
numbercycle++;
}
}

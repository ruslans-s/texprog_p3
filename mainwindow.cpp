#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "manager.h"
#include "generator.h"

#include "evm.h"


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

//ui->logView->clear();
manager managers;
int timeWork=ui->lineEdit->text().toInt();
int intensity=ui->lineEdit_2->text().toInt();
QVector<int> timeWorkEvm{ui->lineEdit_3->text().toInt(),ui->lineEdit_4->text().toInt()};
managers.settings(timeWork,intensity,{1,5});
bool uspex=managers.startModel();
//Generator Generatr;

//StatisticManager StatisticManager;
//valve valves;
//QVector<valve> valveList;
//manager *newManager;

//int tact=10;
//int timework=23;
//int valvCount=3;
//valveList.resize(valvCount);
//valveList[0].setTimeCheker();
//valveList[0].getwaittime(10);
//QVector<int> timeWorkEvm={1,5};
//int numbercycle=0;
//newManager->settings(timework,tact,timeWorkEvm);
//Generatr.generator(tact,timework);
//Generatr.generator(3,1,24);
//QVector<int> poisson=Generatr.getVec();
//for(int i=0;i<=poisson.size()-1;i++)
//{
//    ui->logView->addItem(QString::number(poisson[i]));
//}
//while(numbercycle<timework){
//Generatr.tic(queue);
//queue.tic();
// ui->logView->addItem("Цикл");
//valveList[0].close();
//if(queue.chekWeatherD()==true){
//     ui->logView->addItem("Заявка 213123удалена");
//    valveList[0].chekwaittime((queue.getFirstWeatherD()).getwaitingtime());
//    if(valveList[0].chekopened()){//Удаляем заявку если прошло более 10 часов
//       // StatisticManager.addclients(queue.getFirstWeatherD());
//        queue.removeWeatherD();
//        ui->logView->addItem("Заявка удалена");
//    }


//}
//  ui->logView->addItem(QString::number(queue.numberWeatherD()));
//numbercycle++;
//}
QVector<QString> log = managers.getLog();
for(int i=0;i<=log.size()-1;i++){
     ui->logView->addItem(log[i]);
}
}

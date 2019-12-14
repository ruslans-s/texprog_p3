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
    setWindowTitle("СМО. Модель вычислительного центра");
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
bool timeEVM=false;
if(ui->radioButton->isChecked()){
    timeEVM=true;
}
ui->logView->clear();
manager managers;
int timeWork=ui->lineEdit->text().toInt();
int intensity=ui->spinBox_3->text().toInt();
int shelfLife=ui->shelfLife->text().toInt();
int tact=ui->spinBox_4->text().toInt();
QVector<int> timeWorkEvm{ui->spinBox->text().toInt(),ui->spinBox_2->text().toInt()};
managers.settings(timeWork*60,intensity,timeWorkEvm,shelfLife,timeEVM,tact);
bool uspex=managers.startModel();

QVector<QString> log = managers.getLog();
for(int i=0;i<=log.size()-1;i++){
    ui->logView->addItem(log[i]);
}
QVector<QVector<int>> infomod=managers.getInfoModelling();
QString str;
for(int i=0;i<=infomod.size()-1;i++){
    str.clear();
    for(int j=0;j<=infomod[i].size()-1;j++)
    {
        str=str+" "+QString::number(infomod[i][j]);
    }
    ui->logView->addItem(str);

}
}

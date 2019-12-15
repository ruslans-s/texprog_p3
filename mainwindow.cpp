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
managers.settings(timeWork*60,intensity,timeWorkEvm,shelfLife*60,timeEVM,tact);
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
str.clear();

QVector<QVector<int>> info=managers.getInformation();
QStandardItemModel *model = new QStandardItemModel;
QStandardItem *item;
QModelIndex index;
model = new QStandardItemModel(info.size(),6,this);
ui->tableView->setModel(model);
    model->setHeaderData(0,Qt::Horizontal,"Номер такта");
    model->setHeaderData(1,Qt::Horizontal,"Кол-Во заявок в очереди");
    model->setHeaderData(2,Qt::Horizontal,"Заявок обработанно");
    model->setHeaderData(3,Qt::Horizontal,"Не обработанных");
    model->setHeaderData(4,Qt::Horizontal,"Обработала 1 ЭВМ");
    model->setHeaderData(5,Qt::Horizontal,"Обработала 2 ЭВМ");
 //   ui->tableView->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Stretch);
     // ui->tableView->horizontalHeader()->setSectionResizeMode(2, QHeaderView::Stretch);
//    for(int i=1;i<=9;i++){
// model->setHeaderData(i,Qt::Horizontal, QChar(alph[i-1]));
//    }
//    for(int i=0;i<model->rowCount();i++){
// model->setHeaderData(i,Qt::Vertical, i);
//    }
for(int row=0;row<model->rowCount();row++){
     for(int col=0;col<model->columnCount();col++) {
       index=model->index(row,col);
       model->setData(index, QString::number(info[row][col]));
    }
}

str.clear();

}

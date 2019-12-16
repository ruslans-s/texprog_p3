#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "manager.h"
#include "generator.h"
#include"QFile"
#include "evm.h"
#include "QTextStream"
#include "QFileDialog"
#include "statisticmanager.h"
#include "valve.h"
#include "weatherd.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("СМО. Модель вычислительного центра");
    setWindowIcon(QIcon(":/icon.ico"));


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

int timeWork=ui->lineEdit->text().toInt();
int intensity=ui->spinBox_3->text().toInt();
int shelfLife=ui->shelfLife->text().toInt();
int tact=ui->spinBox_4->text().toInt();
QVector<int> timeWorkEvm{ui->spinBox->text().toInt(),ui->spinBox_2->text().toInt()};
manager managers(timeWork*60,intensity,timeWorkEvm,shelfLife*60,timeEVM,tact);
managers.startModel();

//log= managers.getLog();
//for(int i=0;i<=log.size()-1;i++){
//    ui->logView->addItem(log[i]);
//}
QVector<QVector<int>> infomod=managers.getInfoModelling();
QString str;
//for(int i=0;i<=infomod.size()-1;i++){
//    str.clear();
//    for(int j=0;j<=infomod[i].size()-1;j++)
//    {
//        str=str+" "+QString::number(infomod[i][j]);
//    }
//    ui->logView->addItem(str);

//}

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

for(int row=0;row<model->rowCount();row++){
     for(int col=0;col<model->columnCount();col++) {
       index=model->index(row,col);
       model->setData(index, QString::number(info[row][col]));
    }
}

str.clear();

QVector<int> busyInfo = managers.getBusyInfo();
double r=busyInfo[0],timeWorkD=timeWork*60;
ui->label_13->setText(QString::number(r/timeWorkD));
r=busyInfo[1];
ui->label_14->setText(QString::number(r/timeWorkD));

double directly=0,expected=0;
for(int i=0;i<infomod.size();i++){
    if(infomod[i][2]>0) {
        expected++;
    } else directly++;
}
expected=expected+info[info.size()-1][1];
ui->label_18->setNum((expected/(expected+directly)));
//ui->save->
ui->save->setEnabled(true);
ui->label_23->setNum(info[info.size()-1][4]);
ui->label_24->setNum(info[info.size()-1][5]);
ui->label_25->setNum(info[info.size()-1][2]);
ui->label_26->setNum(info[info.size()-1][3]);
}

void MainWindow::on_pushButton_2_clicked() // Октрытие окна задания
{
    TaskWindow = new Task;
    TaskWindow->show();
}
// Сохранение логов в файл
void MainWindow::on_save_clicked()
{
       // QVector<QString> log = managers.getLog();
    //Октрытие окна для выбора директорий сохранения
         QString fileName=QFileDialog::getSaveFileName( 0,"Сохранить файл как","C:\\Users\\RS\\Desktop","txt(*.txt)" );
        QFile file(fileName);
        QString str;
        QTextStream out(&file); //Создание потока для ввода текста в файл
        if (file.open(QIODevice::WriteOnly))
        {
            // out<<( str="Исходный текст: ")<< endl;
             for(int i=0;i<=log.size()-1;i++){ // Сохранение исходного текста
                 out<<log[i]<<endl;
             }


            file.close();
        }

}

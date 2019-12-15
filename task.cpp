#include "task.h"
#include "ui_task.h"

Task::Task(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Task)
{
    ui->setupUi(this);
    setWindowTitle("СМО. Модель вычислительного центра");
    setWindowIcon(QIcon(":/icon.ico"));
}

Task::~Task()
{
    delete ui;
}

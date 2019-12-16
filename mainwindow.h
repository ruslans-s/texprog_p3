#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "queue.h"
#include <QMainWindow>
#include "QStandardItemModel"
#include "QStandardItem"
#include "task.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    queue queue;
private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();

    void on_save_clicked();

protected:
  QVector<QString> log;
private:
    Ui::MainWindow *ui;
    Task *TaskWindow;
};

#endif // MAINWINDOW_H

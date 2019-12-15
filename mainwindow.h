#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "queue.h"
#include <QMainWindow>
#include "QStandardItemModel"
#include "QStandardItem"
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
protected:

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H

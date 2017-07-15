#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QListWidgetItem>
#include<ordercatalog.h>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:


    void ListUpdate();

    void SessionUpdate(QListWidgetItem* a);
    void Submit();
     void CreatOrder();
    void SeatUpdate(int);

private:
    Ui::MainWindow *ui;
    OrderCatalog *ordercatalog;
};

#endif // MAINWINDOW_H

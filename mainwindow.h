#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QListWidgetItem>
#include<ordercatalog.h>
#include<usercatalog.h>
#include<administrator.h>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
     bool isDigit(QString);//判断字符串是否是纯数字的函数
private slots:


    void ListUpdate();

    void SessionUpdate(QListWidgetItem* a);
    void Submit();
     void CreatOrder();
    void SeatUpdate(int);
    void doLogin();
    void setUp();
    void skinLogin();
    void skinSetup();


private:
    Ui::MainWindow *ui;
    OrderCatalog *ordercatalog;
   UserCatalog *usercatalog;
   User *currentUser;
   Administrator *admin;
};

#endif // MAINWINDOW_H

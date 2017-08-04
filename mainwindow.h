#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QListWidgetItem>
#include<ordercatalog.h>
#include<usercatalog.h>
#include<MovieCatalog.h>
#include<administrator.h>
#include<commentcatalog.h>
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
    void skinMovieList();
    void skinMovieComment();
    void skinMovieSeat();
    void skinOrder();
    void skinUser();
    void skinAdmin();

    void userShow(QListWidgetItem* a);
    void deletUser();
    void showMovieList(QListWidgetItem* a);
    void deletMovie();
    void editMovie();
    void addMovie();
    void deletSession();
    void addSession();
    void resetComment(QListWidgetItem* a);
    void addComment();
    void resetAdminComment();
    void deletAdminComment();
    void resetUserComment();
    void deletUserComment();
    void resetAdminOrder();
    void deletAdminOrder();
    void resetUserOrder();
    void deletUserOrder();
    void resetUser();
    void editUser();
private:
    Ui::MainWindow *ui;
    OrderCatalog *ordercatalog;
   UserCatalog *usercatalog;
   CommentCatalog *commentcatalog;
   User *currentUser;
   MovieCatalog *moviecatalog;
   Administrator *admin;
};

#endif // MAINWINDOW_H

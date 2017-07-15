#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<string>
#include"movie.h"
#include<QDebug>
#include<QString>
#include<QTableWidgetItem>
using namespace std;


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
   ordercatalog = new OrderCatalog();
    ui->setupUi(this);
    ui->Selection->hide();
    ui->widget->hide();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::ListUpdate(){
    QString s =ui->lineEdit->text();
    string a =s.toStdString();
    if(a.compare("")==0){
        ui->listWidget->reset();

}
    else{
    for(int i=ui->listWidget->count()-1;i>=0;i--){
        if(a.compare(ui->listWidget->item(i)->data(Qt::UserRole).toString().toStdString())!=0){
              ui->listWidget->takeItem(i);
        }
    }
    }
}

void MainWindow::SessionUpdate(QListWidgetItem *a){
    ui->comboBox->clear();
    for(int i=0;i<ui->listWidget->catalog->MovieList.size();i++){
       if(a->data(Qt::UserRole).toString().toStdString().compare(ui->listWidget->catalog->MovieList[i].getName())==0) {
                 for(int j=0;j<ui->listWidget->catalog->MovieList[i].getSessionList().size();j++){
                     string s =  ui->listWidget->catalog->MovieList[i].getSessionList()[j].getDate()+" "+ui->listWidget->catalog->MovieList[i].getSessionList()[j].getTime();
              QString a = QString::fromStdString(s);
              ui->comboBox->addItem(a);
           }
       }
    }
}

void MainWindow::SeatUpdate(int a){
    ui->tableWidget->clear();
    int movieindex =0;
    for(int k=0;k<ui->listWidget->catalog->MovieList.size();k++){
        if(ui->listWidget->currentItem()->data(Qt::UserRole).toString().toStdString().compare(ui->listWidget->catalog->MovieList[k].getName())==0){
            movieindex=k;
        }
    }


    if(a>=0){
    for(int i=0;i<ui->listWidget->catalog->MovieList[movieindex].getSessionList()[a].getSeatList().size();i++){
      QTableWidgetItem* checkBox=new QTableWidgetItem();
      if(ui->listWidget->catalog->MovieList[movieindex].getSessionList()[a].getSeatList()[i].getLocked()==false){
      checkBox->setCheckState(Qt::Unchecked);
      checkBox->setFlags(checkBox->flags()& ~Qt::ItemIsEditable);
      }
      else
      checkBox->setFlags(checkBox->flags()& ~Qt::ItemIsEditable);
      ui->tableWidget->setItem(ui->listWidget->catalog->MovieList[ui->listWidget->currentRow()].getSessionList()[a].getSeatList()[i].getRow()-1,ui->listWidget->catalog->MovieList[ui->listWidget->currentRow()].getSessionList()[a].getSeatList()[i].getLine()-1,checkBox);
    }
   }
}

void MainWindow::Submit(){
    int movieindex =0;
    for(int k=0;k<ui->listWidget->catalog->MovieList.size();k++){
        if(ui->listWidget->currentItem()->data(Qt::UserRole).toString().toStdString().compare(ui->listWidget->catalog->MovieList[k].getName())==0){
            movieindex=k;
        }
    }
   for(int i=0;i<5;i++){
       for(int j=0;j<8;j++){
           if(ui->tableWidget->item(i,j)->checkState()==Qt::Checked){
               ui->listWidget->catalog->MovieList[movieindex].getSessionList()[ui->comboBox->currentIndex()].getSeatList()[8*i+j].setLocked(true);

           }
       }
   }
}

void MainWindow::CreatOrder(){
   ui->sessioninfo->setText(ui->comboBox->currentText());
    int index =0;
    for(int k=0;k<ui->listWidget->catalog->MovieList.size();k++){
        if(ui->listWidget->currentItem()->data(Qt::UserRole).toString().toStdString().compare(ui->listWidget->catalog->MovieList[k].getName())==0){
            index=k;
        }
    }
 for(int i=0;i<5;i++){
       for(int j=0;j<8;j++){
           if(ui->tableWidget->item(i,j)->checkState()==Qt::Checked){
   ordercatalog->getOrderList().push_back(Order(index,ui->comboBox->currentIndex(),i+1,j+1,ordercatalog->getOrderList().size(),1234));
   int it=i+1;
   int jt=j+1;
   string s =std::to_string(it)+"排"+std::to_string(jt)+"座";
   QString a=QString::fromStdString(s);
   ui->listWidget_2->addItem(a);
           }
       }
   }

}

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<string>
#include"movie.h"
#include<QDebug>
#include<QString>
#include<QTableWidgetItem>
using namespace std;

bool MainWindow::isDigit(QString src){
    QByteArray ba = src.toLatin1();//QString 转换为 char*
         const char *s = ba.data();

        while(*s && *s>='0' && *s<='9') s++;

        if (*s)
        { //不是纯数字
            return false;
        }
        else
        { //纯数字
            return true;
        }
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
   ordercatalog = new OrderCatalog();
   usercatalog = new UserCatalog() ;
   admin=new Administrator();
    ui->setupUi(this);
    ui->Selection->hide();
    ui->CreatOrder->hide();
    ui->userList->setuserList(this->usercatalog);
}

MainWindow::~MainWindow()
{
    delete usercatalog;
    delete ui;
}

void MainWindow::skinLogin(){
    ui->layout->setCurrentWidget(ui->pageLogin);
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
void MainWindow::doLogin(){
    if(!isDigit(ui->setPassword->text())){
        ui->loginMessage->setText("密码必须为纯数字");
        return;
    }
    if(ui->setPassword->text()!=ui->twicePassword->text()){
        ui->loginMessage->setText("两次输入密码不一致");
        return;
    }
    if(!isDigit(ui->setPhone->text())){
        ui->loginMessage->setText("电话号码必须为纯数字");
        return;
    }
    if(usercatalog->findUser(ui->setName->text())!=NULL){
        ui->loginMessage->setText("用户名已存在");
        return;
    }
    bool ok;
    QString sex;
    if(ui->man->isChecked()){
        sex="男";

    }
    else{
        sex="女";
    }
    User temp(usercatalog->getUserList().size(),ui->setName->text(),ui->setPassword->text().toInt(&ok,10),ui->setNickName->text(),sex,ui->setEmail->text(),ui->setPhone->text().toInt(&ok,10),ui->setAddress->text());
    usercatalog->getUserList().push_back(temp);
    ui->loginMessage->setText("注册成功");
    skinSetup();
}
void MainWindow::skinSetup(){
    ui->layout->setCurrentWidget(ui->pageSetup);
}

void MainWindow::setUp(){
    bool ok;
    if(ui->user->isChecked()){
    if((currentUser=usercatalog->findUser(ui->name->text()))==NULL||currentUser->getPassword()!=ui->password->text().toInt(&ok,10)){
        ui->setupMessage->setText("用户名或密码错误");
    }
    else{
        ui->setupMessage->setText("登录成功");
     }
    }
    else{
        if(ui->name->text().toInt(&ok,10)==admin->getNumber()&&ui->password->text().toInt(&ok,10)==admin->getPasswoud()){
            ui->setupMessage->setText("登录成功");
        }
        else{
            ui->setupMessage->setText("用户名或密码错误");
        }
    }

}

void MainWindow::userShow(QListWidgetItem* a){
   User* temp=usercatalog->findUser(a->data(Qt::UserRole).toString());
   ui->labelUserInfo->setText("Id：\t"+QString::number(temp->getNumber())+"\n帐号名：\t"+temp->getName()+"\n昵称：\t"+temp->getNickName()+"\n性别：\t"+temp->getSex()+"\n电子邮箱：\t"+temp->getEmail()+"\n电话号码：\t"+QString::number(temp->getPhone())+"\n地址：\t"+temp->getAddress());
}
void MainWindow::deletUser(){
    int temp=0;
    for(int i=0;i<usercatalog->getUserList().size();i++){
        if(ui->userList->currentItem()->data(Qt::UserRole).toString()==usercatalog->getUserList()[i].getName()){
            temp=i;
        }
    }
    usercatalog->getUserList().erase(usercatalog->getUserList().begin()+temp);
    ui->userList->resetItems();
}

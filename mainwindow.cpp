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
   commentcatalog=new CommentCatalog();
   usercatalog = new UserCatalog() ;
   admin=new Administrator();
   moviecatalog= new MovieCatalog();
    ui->setupUi(this);
    ui->userList->setuserList(this->usercatalog);
    ui->listWidget->catalog=this->moviecatalog;
    ui->admin_movie->catalog=ui->listWidget->catalog;
    ui->MovieIntrodruce->moviecatalog=this->moviecatalog;
    ui->MovieIntroduice2->moviecatalog=this->moviecatalog;

}

MainWindow::~MainWindow()
{
    delete usercatalog;
    delete ordercatalog;
    delete admin;
    delete moviecatalog;
    delete commentcatalog;
    delete ui;

}

void MainWindow::skinLogin(){
    ui->layout->setCurrentWidget(ui->pageLogin);
}

void MainWindow::ListUpdate(){
    QString s =ui->lineEdit->text();
    if(s==""){
        ui->listWidget->resetMovie();

}
    else{
    for(int i=ui->listWidget->count()-1;i>=0;i--){
        if(s!=ui->listWidget->item(i)->data(Qt::UserRole).toString()){
              ui->listWidget->takeItem(i);
        }
    }
    }
}

void MainWindow::SessionUpdate(QListWidgetItem *a){
    ui->comboBox->clear();
    ui->comboBoxAdmin->clear();
    for(int i=0;i<moviecatalog->MovieList.size();i++){
       if(a->data(Qt::UserRole).toString()==moviecatalog->MovieList[i].getName()) {
                 for(int j=0;j<moviecatalog->MovieList[i].getSessionList().size();j++){
                     QString s = QString::number(moviecatalog->MovieList[i].getSessionList()[j].getID())+" "+moviecatalog->MovieList[i].getSessionList()[j].getDate()+" "+moviecatalog->MovieList[i].getSessionList()[j].getTime();
                    QVariant v;
                    v.setValue(QString::number(moviecatalog->MovieList[i].getSessionList()[j].getID()));
              ui->comboBox->addItem(s,v);
              ui->comboBoxAdmin->addItem(s,v);
           }
       }
    }
    ui->movieTittle->setText(a->data(Qt::UserRole).toString());
}

void MainWindow::SeatUpdate(int a){
    ui->tableWidget->clear();
    int movieindex =0;
    if(ui->listWidget->currentItem()!=NULL){
    for(int k=0;k<moviecatalog->MovieList.size();k++){
        if(ui->listWidget->currentItem()->data(Qt::UserRole).toString()==moviecatalog->MovieList[k].getName()){
            movieindex=k;
        }
    }



    if(a>=0){
    for(int i=0;i<moviecatalog->MovieList[movieindex].getSessionList()[a].getSeatList().size();i++){
      QTableWidgetItem* checkBox=new QTableWidgetItem();
      if(moviecatalog->MovieList[movieindex].getSessionList()[a].getSeatList()[i].getLocked()==false){
      checkBox->setCheckState(Qt::Unchecked);
      checkBox->setFlags(checkBox->flags()& ~Qt::ItemIsEditable);
      }
      else
      checkBox->setFlags(checkBox->flags()& ~Qt::ItemIsEditable);
      ui->tableWidget->setItem(moviecatalog->MovieList[ui->listWidget->currentRow()].getSessionList()[a].getSeatList()[i].getRow()-1,ui->listWidget->catalog->MovieList[ui->listWidget->currentRow()].getSessionList()[a].getSeatList()[i].getLine()-1,checkBox);
    }
   }
    }
}

void MainWindow::Submit(){
    int movieindex =0;
    for(int k=0;k<moviecatalog->MovieList.size();k++){
        if(ui->listWidget->currentItem()->data(Qt::UserRole).toString()==moviecatalog->MovieList[k].getName()){
            movieindex=k;
        }
    }
   for(int i=0;i<5;i++){
       for(int j=0;j<8;j++){
           if(ui->tableWidget->item(i,j)->checkState()==Qt::Checked){
               moviecatalog->MovieList[movieindex].getSessionList()[ui->comboBox->currentIndex()].getSeatList()[8*i+j].setLocked(true);

           }
       }
   }
}

void MainWindow::CreatOrder(){
    bool ok;
    ui->listWidget_2->clear();
   ui->sessioninfo->setText(ui->comboBox->currentText());
    int index =0;
    for(int k=0;k<moviecatalog->MovieList.size();k++){
        if(ui->listWidget->currentItem()->data(Qt::UserRole).toString()==moviecatalog->MovieList[k].getName()){
            index=k;
        }
    }
 for(int i=0;i<5;i++){
       for(int j=0;j<8;j++){
           if(ui->tableWidget->item(i,j)->checkState()==Qt::Checked){
   ordercatalog->getOrderList().push_back(Order(ui->listWidget->currentItem()->data(Qt::UserRole).toString(),ui->comboBox->currentData(Qt::UserRole).toString().toInt(&ok,10),i+1,j+1,ordercatalog->getOrderList().size(),currentUser->getName()));
   int it=i+1;
   int jt=j+1;
   string s =std::to_string(it)+"排"+std::to_string(jt)+"座";
   QString a=QString::fromStdString(s)+"\t"+currentUser->getName();
   ui->listWidget_2->addItem(a);
           }
       }
   }
 resetAdminOrder();
 resetUserOrder();

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
void MainWindow::skinAdmin(){
    ui->layout->setCurrentWidget(ui->pageAdmin);
}
void MainWindow::skinMovieList(){
    ui->layout->setCurrentWidget(ui->pageMovieList);
}
void MainWindow::skinMovieComment(){
    ui->layout->setCurrentWidget(ui->pageMovieComment);
}
void MainWindow::skinMovieSeat(){
    ui->layout->setCurrentWidget(ui->pageMovieSeat);
}
void MainWindow::skinOrder(){
    ui->layout->setCurrentWidget(ui->pageOrder);
}
void MainWindow::skinUser(){
    ui->layout->setCurrentWidget(ui->pageUser);
}

void MainWindow::setUp(){
    bool ok;
    if(ui->user->isChecked()){
    if((currentUser=usercatalog->findUser(ui->name->text()))==NULL||currentUser->getPassword()!=ui->password->text().toInt(&ok,10)){
        ui->setupMessage->setText("用户名或密码错误");
    }
    else{
        ui->setupMessage->setText("登录成功");
        resetUserComment();
        QString s="当前用户: ";
        ui->labelCurrentUser->setText(s+currentUser->getName());
        ui->labelCurrentUser2->setText(s+currentUser->getName());
        ui->labelCurrentUser3->setText(s+currentUser->getName());
        ui->labelCurrentUser4->setText(s+currentUser->getName());
        ui->labelCurrentUser1->setText(s+currentUser->getName());

        skinUser();
     }
    }
    else{
        if(ui->name->text().toInt(&ok,10)==admin->getNumber()&&ui->password->text().toInt(&ok,10)==admin->getPasswoud()){
            ui->setupMessage->setText("登录成功");
            skinAdmin();
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
void MainWindow::showMovieList(QListWidgetItem *a){
    Movie temp;
    for(int i=0;i<moviecatalog->MovieList.size();i++){
       if(a->text()==moviecatalog->MovieList[i].getName())
           temp=moviecatalog->MovieList[i];
    }
    ui->setMovieNo->setText(QString::number(temp.getMovie_no()));
    ui->setMovieName->setText(temp.getName());
    ui->setMovieActor->setText(temp.getActor());
    ui->setMovieDirector->setText(temp.getDirector());
    ui->setMovieIntroduce->setText(temp.getIntrotuce());
    ui->setMoviePrice->setText(QString::number(temp.getPrice()));
    ui->setMovieTime->setText(QString::number(temp.getWhole_time()));
    ui->setMovieType->setText(temp.getType());

}
void MainWindow::deletMovie(){
    for(int i=0;i<moviecatalog->MovieList.size();i++){
        if(ui->admin_movie->currentItem()->text()==moviecatalog->MovieList[i].getName()){
            moviecatalog->MovieList.erase(moviecatalog->MovieList.begin()+i);
            ui->admin_movie->resetMovieSimply();
            ui->listWidget->resetMovie();
        }
    }
}
void MainWindow::editMovie(){
    for(int i=0;i<moviecatalog->MovieList.size();i++){
        if(ui->admin_movie->currentItem()->text()==moviecatalog->MovieList[i].getName()){
            bool ok;
            moviecatalog->MovieList[i].setActor(ui->setMovieActor->text());
            moviecatalog->MovieList[i].setDirector(ui->setMovieDirector->text());
            moviecatalog->MovieList[i].setIntrotuce(ui->setMovieIntroduce->text());
            moviecatalog->MovieList[i].setMovie_no(ui->setMovieNo->text().toInt(&ok,10));
            moviecatalog->MovieList[i].setName(ui->setMovieName->text());
            moviecatalog->MovieList[i].setPrice(ui->setMoviePrice->text().toInt(&ok,10));
            moviecatalog->MovieList[i].setType(ui->setMovieType->text());
            moviecatalog->MovieList[i].setWhole_time(ui->setMovieTime->text().toInt(&ok,10));
            ui->admin_movie->resetMovieSimply();
            ui->listWidget->resetMovie();
           break;
        }
   }
}
void MainWindow::addMovie(){
    bool ok;
   Movie *temp=new Movie(ui->setMovieNo->text().toInt(&ok,10),ui->setMovieName->text(),ui->setMovieDirector->text(),ui->setMovieActor->text(),ui->setMoviePrice->text().toInt(&ok,10),ui->setMovieTime->text().toInt(&ok,10),ui->setMovieType->text(),ui->setMovieIntroduce->text());
   moviecatalog->MovieList.push_back(*temp);
   ui->admin_movie->resetMovieSimply();
   ui->listWidget->resetMovie();
}
void MainWindow::deletSession(){
for(int i=0;i<moviecatalog->MovieList.size();i++){
    if(ui->admin_movie->currentItem()->text()==moviecatalog->MovieList[i].getName()){
        moviecatalog->MovieList[i].getSessionList().erase(moviecatalog->MovieList[i].getSessionList().begin()+ui->comboBoxAdmin->currentIndex());
        SessionUpdate(ui->admin_movie->currentItem());
        break;
    }
}

}
void MainWindow::addSession(){
    bool ok;
    ui->addsessionMessage->setText("");
    Session *temp=new Session(ui->setSessionNo->text().toInt(&ok,10),ui->setSessionDate->text(),ui->setSessionTime->text());
    for(int i=0;i<moviecatalog->MovieList.size();i++){
        if(ui->admin_movie->currentItem()->text()==moviecatalog->MovieList[i].getName()){
            bool check=true;
            for(int j=0;j<moviecatalog->MovieList[i].getSessionList().size();j++){
               if(ui->setSessionNo->text().toInt(&ok,10)==moviecatalog->MovieList[i].getSessionList()[j].getID())
                   check=false;
            }
            if(check){
            moviecatalog->MovieList[i].getSessionList().push_back(*temp);
            SessionUpdate(ui->admin_movie->currentItem());
            ui->addsessionMessage->setText("添加场次成功");
            }
            else{
                ui->addsessionMessage->setText("场次号已存在");
            }
            break;
        }
    }
}
void MainWindow::resetComment(QListWidgetItem *a){
   QImage* img=new QImage;
   img->load(this->moviecatalog->findMovie(a->data(Qt::UserRole).toString())->getUrl());
   *img=img->scaled(151,171,Qt::KeepAspectRatio);
   ui->MoviePic->setPixmap(QPixmap::fromImage(*img));
  QListWidget *temp=ui->commentList;
    for(int i=temp->count()-1;i>=0;i--) {
   temp->takeItem(i);
    }
    for(int i=0;i<commentcatalog->getCommentList().size();i++){
        if(commentcatalog->getCommentList()[i].getMovie()==a->text()){
            QString src=commentcatalog->getCommentList()[i].getUser()+"\n"+commentcatalog->getCommentList()[i].getInformation();
            QListWidgetItem* commentTemp=new QListWidgetItem(src,ui->commentList);
            QVariant v;
            v.setValue(QString::number(i));
            commentTemp->setData(Qt::UserRole,v);
            temp->addItem(commentTemp);
        }
    }
}
void MainWindow::addComment(){
    Comment* temp=new Comment(ui->listWidget->currentItem()->data(Qt::UserRole).toString(),this->currentUser->getName(),ui->setComment->text());
    commentcatalog->getCommentList().push_back(*temp);
    resetComment(ui->listWidget->currentItem());
    resetUserComment();
}
void MainWindow::resetAdminComment(){
    ui->adminCommentList->clear();
    for(int i=0;i<commentcatalog->getCommentList().size();i++){
        QString src="评论人:"+commentcatalog->getCommentList()[i].getUser()+"\t评论电影:"+commentcatalog->getCommentList()[i].getMovie()+"\n"+commentcatalog->getCommentList()[i].getInformation();
        QListWidgetItem* temp=new QListWidgetItem(src,ui->adminCommentList);
        ui->adminCommentList->addItem(temp);
    }
}
void MainWindow::deletAdminComment(){
    int i=ui->adminCommentList->currentRow();
    commentcatalog->getCommentList().erase(commentcatalog->getCommentList().begin()+i);
    resetAdminComment();
}
void MainWindow::resetUserComment(){
    ui->userCommentList->clear();
    for(int i=0;i<commentcatalog->getCommentList().size();i++){
        if(currentUser->getName()==commentcatalog->getCommentList()[i].getUser()){
            QString src="评论电影:"+commentcatalog->getCommentList()[i].getMovie()+"\n"+commentcatalog->getCommentList()[i].getInformation();
           QListWidgetItem* temp=new QListWidgetItem(src,ui->userCommentList) ;
           QVariant v;
           v.setValue(QString::number(i));
           temp->setData(Qt::UserRole,v);
           ui->userCommentList->addItem(temp);
        }
    }

}
void MainWindow::deletUserComment(){
   bool ok;
    int i=ui->userCommentList->currentItem()->data(Qt::UserRole).toString().toInt(&ok,10);
    commentcatalog->getCommentList().erase(commentcatalog->getCommentList().begin()+i);
    resetUserComment();
    resetAdminComment();
}
void MainWindow::resetAdminOrder(){
    ui->adminOrderList->clear();
    for(int i=0;i<ordercatalog->getOrderList().size();i++){
       QString s="场次号:"+QString::number(ordercatalog->getOrderList()[i].getSession_no())+"    用户:"+ordercatalog->getOrderList()[i].getUser()+"\t电影名:"+ordercatalog->getOrderList()[i].getMovie()+"\n"+QString::number(ordercatalog->getOrderList()[i].getSeat_row())+"排"+QString::number(ordercatalog->getOrderList()[i].getSeat_line())+"座";
      QListWidgetItem* temp=new QListWidgetItem(s,ui->adminOrderList) ;
      ui->adminOrderList->addItem(temp);
    }
}

void MainWindow::deletAdminOrder(){
    int i=ui->adminOrderList->currentRow();
   moviecatalog->findMovie(ordercatalog->getOrderList()[i].getMovie())->findSession(ordercatalog->getOrderList()[i].getSession_no())->getSeatList()[(ordercatalog->getOrderList()[i].getSeat_row()-1)*8+ordercatalog->getOrderList()[i].getSeat_line()-1].setLocked(false);
    ordercatalog->getOrderList().erase(ordercatalog->getOrderList().begin()+i);

    resetAdminOrder();
}
void MainWindow::resetUserOrder(){
    ui->userOrderList->clear();
    if(currentUser==NULL)
        return;
    for(int i=0;i<ordercatalog->getOrderList().size();i++){
        if(ordercatalog->getOrderList()[i].getUser()==currentUser->getName()){
            QString s="电影名:"+ordercatalog->getOrderList()[i].getMovie()+"\t场次号:"+QString::number(ordercatalog->getOrderList()[i].getSession_no())+"  "+QString::number(ordercatalog->getOrderList()[i].getSeat_row())+"排"+QString::number(ordercatalog->getOrderList()[i].getSeat_line())+"座";
            QListWidgetItem* temp=new QListWidgetItem(s,ui->userOrderList);
            QVariant v;
            v.setValue(QString::number(i));
            temp->setData(Qt::UserRole,v);
            ui->userOrderList->addItem(temp);
        }
}
}
void MainWindow::deletUserOrder(){
    bool ok;
    int i=ui->userOrderList->currentItem()->data(Qt::UserRole).toString().toInt(&ok,10);
    moviecatalog->findMovie(ordercatalog->getOrderList()[i].getMovie())->findSession(ordercatalog->getOrderList()[i].getSession_no())->getSeatList()[(ordercatalog->getOrderList()[i].getSeat_row()-1)*8+ordercatalog->getOrderList()[i].getSeat_line()-1].setLocked(false);
    ordercatalog->getOrderList().erase(ordercatalog->getOrderList().begin()+i);
    resetUserOrder();
    resetAdminOrder();
}
void MainWindow::resetUser(){
    if(currentUser==NULL)
        return;
    ui->showID->setText(QString::number(currentUser->getNumber()));
    ui->showName->setText(currentUser->getName());
    ui->setUserNName->setText(currentUser->getNickName());
    ui->setUserPassword->setText(QString::number(currentUser->getPassword()));
    ui->setUserPhone->setText(QString::number(currentUser->getPhone()));
    ui->setUserAdd->setText(currentUser->getAddress());
    ui->setUserEmail->setText(currentUser->getEmail());
    if(currentUser->getSex()=="男"){
        ui->setMan->setChecked(true);
    }
    else
        ui->setWoman->setChecked(true);
}
void MainWindow::editUser(){
    bool ok;
    if(isDigit(ui->setUserPassword->text()))
    currentUser->setPassword(ui->setUserPassword->text().toInt(&ok,10));
    else{
        ui->editUserMessage->setText("密码必须为纯数字");
        return;
    }
    currentUser->setAddress(ui->setUserAdd->text());
    currentUser->setEmail(ui->setUserEmail->text());
    currentUser->setNickName(ui->setUserNName->text());
    if(isDigit(ui->setUserPhone->text()))
    currentUser->setPhone(ui->setUserPhone->text().toInt(&ok,10));
    else{
        ui->editUserMessage->setText("电话号码必须为纯数字");
        return;
    }
    if(ui->setMan->isChecked()){
        currentUser->setSex("男");
    }
    else
        currentUser->setSex("女");
    ui->editUserMessage->setText("修改成功");
    resetUser();
}

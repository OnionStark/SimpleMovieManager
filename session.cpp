#include "session.h"


Session::Session(int id, QString da, QString t){
    ID=id;
    date=da;
    time=t;
    for(int i=1;i<=5;i++){
    for(int j=1;j<=8;j++){
        Seat temp(i,j);
        this->SeatList.push_back(temp);
   }
}
}
Session::Session(){

}

QString Session::getTime(){
    return time;
}
QString Session::getDate(){
    return date;
}

int Session::getID(){
    return ID;
}
QVector<Seat>& Session::getSeatList(){
    return SeatList;
}
void Session::setDate(QString a){
    date=a;
}
void Session::setID(int a){
    ID=a;
}
void Session::setTime(QString a){
    time=a;
}

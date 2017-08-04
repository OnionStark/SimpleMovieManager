#include "movie.h"
#include<vector>
#include<iostream>
using namespace std;
Movie::Movie(int no, QString nam, QString dir, QString act, int pri, int who, QString tye, QString intro )
{
  movie_no=no;
  name=nam;
  director=dir;
  price=pri;
  whole_time=who;
  type=tye;
  introtuce=intro;
  actor=act;
  QString Url="./images/";
  url=Url+name+".jpg";

  }
Movie::Movie(){

}

int Movie::getMovie_no(){
    return movie_no;
}
QString Movie::getName(){
    return name;

}
QString Movie::getDirector(){
    return director;
}
QString Movie::getActor(){
    return actor;
}
int Movie::getPrice(){
    return price;
}
int Movie::getWhole_time(){
    return whole_time;
}
QString Movie::getType(){
    return type;
}
QString Movie::getIntrotuce(){
    return introtuce;
}

QVector<Session> &Movie::getSessionList(){
    return SessionList;
}
QString Movie::getUrl(){
    return url;
}
void Movie::setMovie_no(int a){
    movie_no=a;
}
void Movie::setName(QString a){
    name=a;
    url="./images/"+name+".jpg";
}
void Movie::setDirector(QString a){
    director=a;
}
void Movie::setActor(QString a){
    actor=a;
}
void Movie::setPrice(int a){
    price=a;
}
void Movie::setWhole_time(int a){
    whole_time=a;
}
void Movie::setType(QString a){
    type=a;
}
void Movie::setIntrotuce(QString a){
    introtuce=a;
}
void Movie::setUrl(QString a){
    url=a;
}
Session* Movie::findSession(int a){
    for(int i=0;i<SessionList.size();i++){
        if(SessionList[i].getID()==a){
            return &SessionList[i];
        }
    }
       return NULL;
}

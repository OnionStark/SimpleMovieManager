#ifndef MOVIE_H
#define MOVIE_H
#include<iostream>
#include<QDataStream>
#include<QVector>
#include<QString>
#include"seat.h"
#include"session.h"
using namespace std;

class Movie
{
public:
    Movie(int no, QString name, QString director, QString actor, int price, int wholetime, QString type, QString introtuce);
    Movie();
    int getMovie_no();
    QString getName();
    QString getDirector();
    QString getActor();
    int getPrice();
    int getWhole_time();
    QString getType();
    QString getIntrotuce();
    QVector<Session>& getSessionList();
    QString getUrl();
    void setMovie_no(int a);
    void setName(QString a);
    void setDirector(QString a);
    void setActor(QString a);
    void setPrice(int a);
    void setWhole_time(int a) ;
    void setType(QString a);
    void setIntrotuce(QString a);
    void setUrl(QString a);
    Session* findSession(int a);
friend QDataStream& operator << (QDataStream& out ,const Movie& movieTemp);
friend QDataStream& operator >>(QDataStream& in ,Movie& movieTemp);

private:
    int movie_no;
    QString name;
    QString director;
    QString actor;
    int price;
    int whole_time;
    QString type;
    QString introtuce;
    QVector<Session> SessionList;
    QString url;
};
inline QDataStream& operator <<(QDataStream& out,const Movie& movieTemp){
    out<<movieTemp.movie_no<<movieTemp.name<<movieTemp.director<<movieTemp.actor<<movieTemp.price<<movieTemp.whole_time<<movieTemp.type<<movieTemp.introtuce<<movieTemp.url<<movieTemp.SessionList;
    return out;
}
inline QDataStream& operator >>(QDataStream& in,Movie& movieTemp){
    in>>movieTemp.movie_no>>movieTemp.name>>movieTemp.director>>movieTemp.actor>>movieTemp.price>>movieTemp.whole_time>>movieTemp.type>>movieTemp.introtuce>>movieTemp.url>>movieTemp.SessionList;
    return in;
}

#endif // MOVIE_H

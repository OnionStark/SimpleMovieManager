#ifndef SESSION_H
#define SESSION_H
#include<QString>
#include"seat.h"
#include<QVector>
using namespace std;
class Session
{
public:
    Session(int ,QString ,QString);
    Session();
    QString getTime();
    QString getDate();
    int getID();
    QVector<Seat>& getSeatList();
    void setTime(QString a);
    void setDate(QString a);
    void setID(int a);
friend QDataStream& operator << (QDataStream& out ,const Session& sessionTemp);
friend QDataStream& operator >>(QDataStream& in ,Session& sessionTemp);

private:
    int ID;
    QString date;
    QString time;
    QVector<Seat> SeatList;
    };
inline QDataStream& operator << (QDataStream& out ,const Session& sessionTemp){
    out<<sessionTemp.ID<<sessionTemp.date<<sessionTemp.time<<sessionTemp.SeatList;
    return out;
}

inline QDataStream& operator >>(QDataStream& in ,Session& sessionTemp){
    in>>sessionTemp.ID>>sessionTemp.date>>sessionTemp.time>>sessionTemp.SeatList;
    return in;

}

#endif // SESSION_H

#ifndef ORDER_H
#define ORDER_H
#include<QString>
#include<QDataStream>
#include<QFile>

class Order
{
public:
    Order(QString move_n, int session_no, int seat_row, int seat_line, int order_no, QString user);
    Order();
    int getOrder_no();
    int getSession_no();
    int getSeat_row();
    int getSeat_line();
    QString getUser();
    QString getMovie();
    void setOrder_no(int a);
    void setSession_no(int a);
    void setSeat_row(int a);
    void setSeat_line(int a);
    void setMovie(QString a);
    void setUser(QString a);
friend QDataStream& operator << (QDataStream& out ,const Order& orderTemp);
friend  QDataStream& operator >>(QDataStream& in ,Order& orderTemp);

private:
    int order_no;
    int session_no;
    int seat_row;
    int seat_line;
    QString user;
    QString movie;
};
inline QDataStream& operator <<(QDataStream& out,const Order& orderTemp){
    out<<orderTemp.order_no<<orderTemp.session_no<<orderTemp.seat_row<<orderTemp.seat_line<<orderTemp.user<<orderTemp.movie;
    return out;
}
inline QDataStream& operator >>(QDataStream& in ,Order& orderTemp){
    in>>orderTemp.order_no>>orderTemp.session_no>>orderTemp.seat_row>>orderTemp.seat_line>>orderTemp.user>>orderTemp.movie;
    return in;
}

#endif // ORDER_H

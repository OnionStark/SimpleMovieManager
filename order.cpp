#include "order.h"

Order::Order(QString move_n,int session, int seat_r,int seat_l, int order, QString user_name)
{
  order_no=order;
  session_no=session;
  seat_row=seat_r;
  seat_line=seat_l;
  user=user_name;
  movie=move_n;
}
Order::Order(){

}

int Order::getOrder_no(){
    return order_no;
}
int Order::getSeat_row(){
    return seat_row;
}
int Order::getSeat_line(){
    return seat_line;
}

int Order::getSession_no(){
    return session_no;
}
QString Order::getUser(){
    return user;
}
QString Order::getMovie(){
    return movie;
}
void Order::setOrder_no(int a){
    order_no=a;
}
void Order::setSession_no(int a){
    session_no=a;
}
void Order::setSeat_row(int a){
    seat_row=a;
}
void Order::setSeat_line(int a){
    seat_line=a;
}
void Order::setMovie(QString a){
    movie=a;
}
void Order::setUser(QString a){
    user=a;
}

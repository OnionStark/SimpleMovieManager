#include "order.h"

Order::Order(int move_n,int session, int seat_r,int seat_l, int order=0, int user=1234)
{
  order_no=order;
  session_no=session;
  seat_row=seat_r;
  seat_line=seat_l;
  user_number=user;
  move_no=move_n;
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
int Order::getUser_number(){
    return user_number;
}
int Order::getMove_no(){
    return move_no;
}

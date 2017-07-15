#ifndef ORDER_H
#define ORDER_H


class Order
{
public:
    Order(int move_n, int session_no, int seat_row, int seat_line, int order_no, int user_number);
    int getOrder_no();
    int getSession_no();
    int getSeat_row();
    int getSeat_line();
    int getUser_number();
    int getMove_no();
private:
    int order_no;
    int session_no;
    int seat_row;
    int seat_line;
    int user_number;
    int move_no;
};

#endif // ORDER_H

#ifndef SEAT_H
#define SEAT_H


class Seat
{
public:
    Seat(int ,int);
    int getRow();
    int getLine();
    bool getLocked();
    void setLocked(bool);
private:
    int row;
   int line;
   bool locked;
};

#endif // SEAT_H

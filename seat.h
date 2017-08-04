#ifndef SEAT_H
#define SEAT_H
#include<QDataStream>

class Seat
{
public:
    Seat(int ,int);
    Seat();
    int getRow();
    int getLine();
    bool getLocked();
    void setLocked(bool);
friend QDataStream& operator << (QDataStream& out ,const Seat& seatTemp);
friend QDataStream& operator >>(QDataStream& in ,Seat& seatTemp);

private:
    int row;
   int line;
   bool locked;
};
inline QDataStream& operator << (QDataStream& out ,const Seat& seatTemp){
    out<<seatTemp.row<<seatTemp.line<<seatTemp.locked;
    return out;
}

inline QDataStream& operator >>(QDataStream& in ,Seat& seatTemp){
    in>>seatTemp.row>>seatTemp.line>>seatTemp.locked;
    return in;

}

#endif // SEAT_H

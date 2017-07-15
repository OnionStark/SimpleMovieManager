#include "session.h"


Session::Session(int id,string da,string t){
    ID=id;
    date=da;
    time=t;
}

string Session::getTime(){
    return time;
}
string Session::getDate(){
    return date;
}

int Session::getID(){
    return ID;
}
vector<Seat>& Session::getSeatList(){
    return SeatList;
}

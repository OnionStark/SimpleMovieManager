#ifndef SESSION_H
#define SESSION_H
#include<string>
#include"seat.h"
#include<vector>
using namespace std;
class Session
{
public:
    Session(int ,string ,string);
    string getTime();
    string getDate();
    int getID();
    vector<Seat>& getSeatList();
private:
    int ID;
    string date;
    string time;
    vector<Seat> SeatList;
    };

#endif // SESSION_H

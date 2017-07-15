#ifndef MOVIE_H
#define MOVIE_H
#include<iostream>
#include<vector>
#include<string>
#include"seat.h"
#include"session.h"
using namespace std;

class Movie
{
public:
    Movie(int no,string name,string director,string actor,int price,int wholetime,string type,string introtuce);
    int getMovie_no();
    string getName();
    string getDirector();
    string getActor();
    int getPrice();
    int getWhole_time();
    string getType();
    string getIntrotuce();
    //vector<Seat>& getRemainSeat();
    //vector<Session>& getRemainSession();
    vector<Session>& getSessionList();
private:
    int movie_no;
    string name;
    string director;
    string actor;
    int price;
    int whole_time;
    string type;
    string introtuce;
    vector<Session> SessionList;
    //poster;
};

#endif // MOVIE_H

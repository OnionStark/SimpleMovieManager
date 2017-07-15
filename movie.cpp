#include "movie.h"
#include<vector>
#include<iostream>
using namespace std;
Movie::Movie(int no, string nam, string dir,string act, int pri, int who, string tye, string intro)
{
  movie_no=no;
  name=nam;
  director=dir;
  price=pri;
  whole_time=who;
  type=tye;
  introtuce=intro;
  actor=act;
}
int Movie::getMovie_no(){
    return movie_no;
}
string Movie::getName(){
    return name;
}
string Movie::getDirector(){
    return director;
}
string Movie::getActor(){
    return actor;
}
int Movie::getPrice(){
    return price;
}
int Movie::getWhole_time(){
    return whole_time;
}
string Movie::getType(){
    return type;
}
string Movie::getIntrotuce(){
    return introtuce;
}

vector<Session>& Movie::getSessionList(){
    return SessionList;
}

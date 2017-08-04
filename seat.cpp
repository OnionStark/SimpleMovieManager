#include "seat.h"

Seat::Seat(int r,int l){
    row=r;
    line=l;
    locked=false;
}
Seat::Seat(){

}

int Seat::getLine(){
    return line;
}
bool Seat::getLocked(){
    return locked;
}
int Seat::getRow(){
    return row;
}
void Seat::setLocked(bool a){
    locked = a;
}

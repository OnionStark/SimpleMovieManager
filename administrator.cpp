#include "administrator.h"

Administrator::Administrator()
{
   number=1111;
   password=1111;
}
void Administrator::setNumber(int a){
    number=a;
}
void Administrator::setPassword(int a){
    password=a;
}
int Administrator::getNumber(){
    return number;
}
int Administrator::getPasswoud(){
    return password;
}

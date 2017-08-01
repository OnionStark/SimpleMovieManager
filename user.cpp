#include<QDataStream>
#include "user.h"
User::User(){

}

User::User(int num, QString nam, int pass, QString nname, QString se , QString email, int phone, QString add)
{
   number=num;
   name=nam;
   password=pass;
   nick_name=nname;
   sex=se;
   e_mail=email;
   phone_number=phone;
   address=add;
}
void User::setNumber(int a){
   number=a;
}

void User::setPassword(int a){
    password=a;
}

void User::setPhone(int a){
    phone_number=a;
}

void User::setSex(QString a){
    sex=a;
}

void User::setNickName(QString a ){
   nick_name=a;
}
void User::setName(QString a){
    name=a;
}
void User::setEmail(QString a){
    e_mail=a;
}
void User::setAddress(QString a){
    address=a;
}
int User::getNumber(){
    return number;
}
int User::getPassword(){
    return password;
}
int User::getPhone(){
    return phone_number;
}
QString User::getSex(){
    return sex;
}
QString User::getNickName(){
    return nick_name;
}
QString User::getName(){
    return name;
}
QString User::getEmail(){
    return e_mail;
}
QString User::getAddress(){
    return address;
}

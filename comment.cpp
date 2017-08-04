#include "comment.h"

Comment::Comment()
{

}
Comment::Comment(QString mo, QString user, QString info){
    movie=mo;
    user_name=user;
    information=info;

}

void Comment::setInformation(QString a){
    information=a;
}
void Comment::setMovie(QString a){
    movie=a;
}
void Comment::setUserName(QString a){
    user_name=a;
}
QString Comment::getInformation(){
    return information;
}
QString Comment::getMovie(){
    return movie;
}
QString Comment::getUser(){
    return user_name;
}

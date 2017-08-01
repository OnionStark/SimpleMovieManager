#include "comment.h"

Comment::Comment()
{

}
void Comment::setInformation(string a){
    information=a;
}
void Comment::setMovie(string a){
    movie=a;
}
void Comment::setUserName(string a){
    user_name=a;
}
string Comment::getInformation(){
    return information;
}
string Comment::getMovie(){
    return movie;
}
string Comment::getUser(){
    return user_name;
}

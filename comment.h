#ifndef COMMENT_H
#define COMMENT_H
#include<QString>
#include<QDataStream>
#include<iostream>
using namespace std;

class Comment
{
public:
    Comment();
   Comment(QString mo,QString user,QString info);
    void setMovie(QString a);
    void setUserName(QString a);
    void setInformation(QString a);
    QString getMovie();
    QString getUser();
    QString getInformation();
friend QDataStream& operator << (QDataStream& out ,const Comment& commentTemp);
friend  QDataStream& operator >>(QDataStream& in ,Comment& commentTemp);



private:
   QString movie;
   QString user_name;
   QString information;
};
inline QDataStream& operator << (QDataStream& out ,const Comment& commentTemp){
    out<<commentTemp.movie<<commentTemp.user_name<<commentTemp.information;
    return out;
}

inline QDataStream& operator >>(QDataStream& in ,Comment& commentTemp){
    in>>commentTemp.movie>>commentTemp.user_name>>commentTemp.information;
    return in;
}

#endif // COMMENT_H

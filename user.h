#ifndef USER_H
#define USER_H
#include<QString>
#include<QDataStream>
#include<iostream>
using namespace std;

class User
{
public:
    User(int num,QString name,int pass,QString nname,QString se,QString email,int phone,QString add);
    User();
    void setNumber(int );
    void setName(QString );
   void setPassword(int);
   void setNickName(QString);
   void setSex(QString);
   void setEmail(QString );
   void setPhone(int);
   void setAddress(QString);
   int getNumber();
   QString getName();
   int getPassword();
   QString getNickName();
   QString getSex();
   QString getEmail();
   int getPhone();
   QString getAddress();
friend QDataStream& operator << (QDataStream& out ,const User& userTemp);
friend  QDataStream& operator >>(QDataStream& in ,User& userTemp);

private:
    int number;
    QString name;
    int password;
    QString nick_name;
    QString sex;
    QString e_mail;
    int phone_number;
    QString address;
};

inline QDataStream& operator <<(QDataStream& out,const User& userTemp){
    out<<userTemp.number<<userTemp.name<<userTemp.password<<userTemp.nick_name<<userTemp.sex<<userTemp.e_mail<<userTemp.phone_number<<userTemp.address;
    return out;
}
inline QDataStream& operator >>(QDataStream& in ,User& userTemp){
    in>>userTemp.number>>userTemp.name>>userTemp.password>>userTemp.nick_name>>userTemp.sex>>userTemp.e_mail>>userTemp.phone_number>>userTemp.address;
    return in;
}


#endif // USER_H

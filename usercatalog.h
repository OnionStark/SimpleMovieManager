#ifndef USERCATALOG_H
#define USERCATALOG_H
#include<vector>
#include<QVector>
#include<fstream>
#include<iostream>
#include<QDataStream>
#include<QFile>
#include"user.h"
using namespace std;

class UserCatalog
{
public:
    UserCatalog();
    ~UserCatalog();
    QVector<User>& getUserList();
    User* findUser(QString nam);
  private:
    QVector<User> UserList;
};

#endif // USERCATALOG_H

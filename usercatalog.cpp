#include "usercatalog.h"
#include"user.h"
#include<iostream>
using namespace std;
UserCatalog::UserCatalog()
{
    QFile file("user.dat");
    file.open(QIODevice::ReadOnly);
    QDataStream in(&file);
    while(file.exists()&&!in.atEnd()){
        User temp;
        in>>temp;
        UserList.push_back(temp);

    }
     file.close();
   }

QVector<User>& UserCatalog::getUserList(){
    return UserList;
}

UserCatalog::~UserCatalog(){
    QFile file("user.dat");
    file.open(QIODevice::WriteOnly|QIODevice::Truncate);
    QDataStream out(&file);
    for(int i=0;i<UserList.size();i++){
       out<<UserList[i] ;
    }
    file.close();
}

User* UserCatalog::findUser(QString nam){
    User* result=NULL;
    for(int i=0;i<UserList.size();i++){
       if(UserList[i].getName()==nam) {
           result=&UserList[i];
           return result;
       }
    }
    return NULL;
}

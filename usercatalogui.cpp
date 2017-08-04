#include "usercatalogui.h"
#include<QListWidgetItem>

UserCatalogUI::UserCatalogUI(QWidget *parent)
{
}
UserCatalog* UserCatalogUI::getuserList(){
    return userList;
}
void UserCatalogUI::setuserList(UserCatalog *a){
   userList=a;
}
void UserCatalogUI::resetItems(){
    for(int i=this->count()-1;i>=0;i--){
        this->takeItem(i);
    }
    for(int i=0;i<userList->getUserList().size();i++){
        QListWidgetItem* temp= new QListWidgetItem(userList->getUserList()[i].getName(),this);
        QVariant v;
        v.setValue(userList->getUserList()[i].getName());
        temp->setData(Qt::UserRole,v);
        insertItem(i,temp);
    }
}

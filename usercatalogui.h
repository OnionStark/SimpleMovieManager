#ifndef USERCATALOGUI_H
#define USERCATALOGUI_H

#include<QListWidget>
#include"usercatalog.h"

class UserCatalogUI : public QListWidget
{
    Q_OBJECT
public:
    explicit UserCatalogUI(QWidget *parent = 0);
    UserCatalog* getuserList();
    void setuserList(UserCatalog *);
   private:
    UserCatalog* userList;

signals:

public slots:
     void resetItems();

};

#endif // USERCATALOGUI_H

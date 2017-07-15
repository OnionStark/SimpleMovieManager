#ifndef ORDERCATALOG_H
#define ORDERCATALOG_H
#include<vector>
#include"order.h"
using namespace std;
class OrderCatalog
{
public:
    OrderCatalog();
    vector<Order>& getOrderList();
private:
   vector<Order> OrderList;
};

#endif // ORDERCATALOG_H

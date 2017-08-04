#ifndef ORDERCATALOG_H
#define ORDERCATALOG_H
#include<QVector>
#include"order.h"
#include<QDataStream>
#include<QFile>
using namespace std;
class OrderCatalog
{
public:
    OrderCatalog();
    ~OrderCatalog();
    QVector<Order>& getOrderList();
private:
   QVector<Order> OrderList;
};

#endif // ORDERCATALOG_H

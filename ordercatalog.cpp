#include "ordercatalog.h"
#include<vector>
using namespace std;
OrderCatalog::OrderCatalog()
{
 QFile file("order.dat");
 file.open(QIODevice::ReadOnly);
 QDataStream in(&file);
 if(file.exists()&&!in.atEnd()){
     in>>OrderList;
 }
file.close();
}
QVector<Order>& OrderCatalog::getOrderList(){
   return OrderList;
}
OrderCatalog::~OrderCatalog(){
    QFile file("order.dat");
    file.open(QIODevice::WriteOnly|QIODevice::Truncate);
    QDataStream out(&file);
    out<<OrderList;
    file.close();
}

#include "ordercatalog.h"
#include<vector>
using namespace std;
OrderCatalog::OrderCatalog()
{

}
vector<Order>& OrderCatalog::getOrderList(){
   return OrderList;
}

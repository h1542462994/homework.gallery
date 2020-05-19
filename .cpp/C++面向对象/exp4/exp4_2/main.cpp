#include<iostream>
#include"GoodsStore.h"
using namespace std;

int main()
{
    GoodsStore::addStore(5, 23.5);
    GoodsStore::addStore(12, 24.56);
    GoodsStore::addStore(100, 21.5);
    cout << "当天总销售款为:" << GoodsStore::getSum() << "元，每件商品的平均售价为" << GoodsStore::getAveragePrice() << "元" << endl;
    return 0;
}
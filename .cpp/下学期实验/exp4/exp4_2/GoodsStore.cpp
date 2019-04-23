#include"GoodsStore.h"

int GoodsStore::_count = 0;
double GoodsStore::_price = 0;

void GoodsStore::reset()
{
    _count = 0;
    _price = 0;
}

void GoodsStore::addStore(int n,double price)
{
    _count += n;
    _price += n * price;
}

double GoodsStore::getSum()
{
    return _price;
}

double GoodsStore::getAveragePrice()
{
    if (_count == 0)
    {
        return -1;
    }
    else
    {
        return _price / _count;
    }
}
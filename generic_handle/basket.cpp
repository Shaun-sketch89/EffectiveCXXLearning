#include "basket.h"

inline bool compare(const Sales_item &lhs, const Sales_item &rhs){
    return lhs->book() < rhs->book();
}

Basket::Basket() : items(compare) {}

void Basket::add_item(const Sales_item &item){
    items.insert(item);
}

double Basket::total() const{
    double sum = 0;
    for(const_iterator iter = items.begin(); iter != items.end(); iter = items.upper_bound(*iter)){
        sum += (*iter)->net_price(items.count(*iter));
    }
    return sum;
}
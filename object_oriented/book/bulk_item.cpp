//
// Created by 姚轩 on 2024/1/10.
//
#include "bulk_item.h"

Bulk_item::Bulk_item(const std::string &book, double sales_price, std::size_t min_qauntity, double discount_rate):
Item_base(book, sales_price), min_qty(min_qauntity), discount(discount_rate) {}

double Bulk_item::net_price(std::size_t n) const {
    if (n < min_qty) {
        return Item_base::net_price(n);
    } else {
        return discount * Item_base::net_price(n);
    }
}

void Bulk_item::memfcn(const Bulk_item &d, const Item_base &b) {
    // ok: uses this->price
    double ret = price;
    // ok
    ret = d.price;
    // not ok
    //ret = b.price;
}

Bulk_item::~Bulk_item(){}
//
// Created by 姚轩 on 2024/1/10.
//
#include "bulk_item.h"

// refactor: initialize direct base class(Disc_item)
Bulk_item::Bulk_item(const std::string &book, double sales_price, std::size_t min_qauntity, double discount_rate):
Disc_item(book, sales_price, min_qauntity, discount_rate) {}

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
    // ok: Bulk_item can visit protected member of Bulk_item's object
    ret = d.price;
    // not ok: Bulk_item can not visit protected member of Item_base's object
    //ret = b.price;
}

Bulk_item::~Bulk_item(){}

Bulk_item* Bulk_item::clone() const {return new Bulk_item(*this); }
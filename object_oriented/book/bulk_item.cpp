//
// Created by 姚轩 on 2024/1/10.
//
#include "bulk_item.h"

Bulk_item::Bulk_item(const std::string &book, double sales_price, std::size_t min_qauntity, double discount_rate):
Item_base(book, sales_price), min_qty(min_qauntity), discount(discount_rate) {}

double Bulk_item::net_price(std::size_t n) const {return n < min_qty ? n * price : n * price * discount; }

Bulk_item::~Bulk_item(){}
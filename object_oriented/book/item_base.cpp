//
// Created by 姚轩 on 2024/1/9.
//
#include "item_base.h"

Item_base::Item_base(const std::string &book, double sales_price): isbn(book), price(sales_price) {}

std::string book() const {return isbn;}

double net_price(std::size_t n) const { return n * price; }

~Item_base(){}
//
// Created by 姚轩 on 2024/1/9.
//
//#include "item_base.h"
#include <iostream>
#include "bulk_item.h"

Item_base::Item_base(const std::string &book, double sales_price): isbn(book), price(sales_price) {}

Item_base &Item_base::operator=(const Bulk_item& bulkItem) {
    std::cout << "use defined assignment operator called" << std::endl;
    this -> isbn = bulkItem.isbn;
    this -> price = bulkItem.price;
    return *this;
}

Item_base::Item_base(const Bulk_item& bulkItem) {
    std::cout << "use defined copy constructor called" << std::endl;
    this -> isbn = bulkItem.isbn;
    this -> price = bulkItem.price;
}

std::string Item_base::book() const {return isbn;}

double Item_base::net_price(std::size_t n) const { return n * price; }

Item_base::~Item_base(){}
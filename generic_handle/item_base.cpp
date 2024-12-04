//
// Created by 姚轩 on 2024/1/9.
//
//#include "item_base.h"
#include <iostream>
#include "item_base.h"

Item_base::Item_base(const std::string &book, double sales_price): isbn(book), price(sales_price) {}

//Item_base &Item_base::operator=(const Bulk_item& bulkItem) {
Item_base &Item_base::operator=(const Item_base& itemBase) {
    std::cout << "use defined assignment operator called" << std::endl;
    this -> isbn = itemBase.isbn;
    this -> price = itemBase.price;
    return *this;
}

//Item_base::Item_base(const Bulk_item& bulkItem) {
Item_base::Item_base(const Item_base& itemBase) {
    std::cout << "use defined copy constructor called" << std::endl;
    this -> isbn = itemBase.isbn;
    this -> price = itemBase.price;
}

std::string Item_base::book() const {return isbn;}

double Item_base::net_price(std::size_t n) const { return n * price; }

Item_base::~Item_base(){}

Item_base* Item_base::clone() const { return new Item_base(*this);};
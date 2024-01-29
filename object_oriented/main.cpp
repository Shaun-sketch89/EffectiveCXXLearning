//
// Created by 姚轩 on 2024/1/10.
//
#include <iostream>

// user only need to know Sales_item
#include "sales_item.h"

// pass by value will cause slice problem, result of main function will only call Item_base::net_price()
// base class copy constructor will be called
//void print_total(const Item_base item, std::size_t n){

// dynamic binding
void print_total(const Item_base& item, std::size_t n){
    std::cout << "ISBN: " << item.book()
              << "\tnumber sold: " << n << "\ttotal_price: "
              << item.net_price(n) << std::endl;
}

int main() {
    Bulk_item bulkItem("0-201-54848-8", 30, 5, 0.9);
    bulkItem.discount_policy();
    print_total(bulkItem, 10);
    print_total(bulkItem, 3);
    //Item_base item = bulkItem; // compiler call copy constructor
    Item_base item;
    item = bulkItem; // compiler call assignment operator
    print_total(item, 10);

    Sales_item salesItem(bulkItem);
    salesItem->net_price(10); // equals to salesItem.operator->()->net_price(10)
    (*salesItem).net_price(10);
}
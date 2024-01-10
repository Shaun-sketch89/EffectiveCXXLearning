//
// Created by 姚轩 on 2024/1/10.
//
#include <iostream>
#include "bulk_item.h"

void print_total(const Item_base& item, std::size_t n){
    std::cout << "ISBN: " << item.book()
              << "\tnumber sold: " << n << "\ttotal_price: "
              << item.net_price(n) << std::endl;
}

int main() {
    Bulk_item bulkItem("0-201-54848-8", 32, 5, 0.9);
    print_total(bulkItem, 10);
}
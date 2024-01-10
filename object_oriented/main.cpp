//
// Created by 姚轩 on 2024/1/10.
//
#include <iostream>
#include "bulk_item.h"

int main() {
    Bulk_item bulkItem("0-201-54848-8", 32, 5, 0.9);
    std::cout << bulkItem.net_price(10) << std::endl;
}
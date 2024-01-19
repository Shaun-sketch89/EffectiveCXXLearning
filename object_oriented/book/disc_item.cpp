//
// Created by 姚轩 on 2024/1/19.
//
#include "disc_item.h"

Disc_item::Disc_item(const std::string& book, double sales_price, std::size_t qty, double disc_rate):
  Item_base(book, sales_price),
  min_qty(qty), discount(disc_rate) {}
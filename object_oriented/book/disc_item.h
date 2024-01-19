//
// Created by 姚轩 on 2024/1/19.
//
#include "item_base.h"

// refactor
class Disc_item : public Item_base{
public:
    Disc_item(const std::string& book = "",
              double sales_price = 0.0,
              std::size_t qty = 0,
              double disc_rate = 0.0);

protected:
    std::size_t min_qty;
    double discount;
};
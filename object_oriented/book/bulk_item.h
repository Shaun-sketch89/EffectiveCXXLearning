//
// Created by 姚轩 on 2024/1/10.
//
#include "item_base.h"

class Bulk_item: public Item_base{
public:
    Bulk_item(const std::string& book = "", double sales_price = 0, std::size_t min_quantity = 5, double discount_rate = 0.9);
    virtual double net_price(std::size_t) const;
    virtual ~Bulk_item();
private:
    std::size_t min_qty;
    double discount;
};
//
// Created by 姚轩 on 2024/1/10.
//
#include "disc_item.h"

// refactor: inherits from Disc_item which inherits from Item_base
class Bulk_item: public Disc_item{
public:
    Bulk_item(const std::string& book = "", double sales_price = 0.0, std::size_t min_quantity = 0, double discount_rate = 0.0);
    // a widget function that tests protected properties
    void memfcn(const Bulk_item& d, const Item_base& b);
    virtual double net_price(std::size_t) const;
    virtual ~Bulk_item();

// member refactor to Disc_item class
//private:
//    std::size_t min_qty;
//    double discount;
};
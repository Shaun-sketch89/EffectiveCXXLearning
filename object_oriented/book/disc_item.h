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

    // define a pure virtual function to prevent user from creating a Disc_item object. This class only aims to be inherited.
    virtual double net_price(std::size_t) const = 0;

    std::pair<std::size_t, double> discount_policy() const;

    virtual Disc_item* clone() const = 0;

protected:
    std::size_t min_qty;
    double discount;
};
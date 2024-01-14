//
// Created by 姚轩 on 2024/1/9.
//
#include <string>

// forward declaration for assignment operator
class Bulk_item;
class Item_base{
public:
    Item_base(const std::string& book = "", double sales_price = 0);
    // In real scenes, we generally have params as "const Item_base&".
    // default function will be: Item_base& operator=(const Item_base&);
    Item_base& operator=(const Bulk_item&);
    // In real scenes, we generally have params as "const Item_base&". this function is useless
    // default function will be: Item_base(const Item_base&);
    Item_base(const Bulk_item&);

    std::string book() const;
    virtual double net_price(std::size_t) const;
    virtual ~Item_base();
private:
    std::string isbn;
protected:
    double price;
};

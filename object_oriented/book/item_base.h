//
// Created by 姚轩 on 2024/1/9.
//
#include <string>

// forward declaration for assignment operator
//class Bulk_item;

class Item_base{
public:
    Item_base(const std::string& book = "", double sales_price = 0);
    // In real scenes, we don't need to have param "const Bulk_item&". Instead, default function will be: Item_base& operator=(const Item_base&);
    //Item_base& operator=(const Bulk_item&);
    Item_base& operator=(const Item_base&);
    // In real scenes, we don't need to have param "const Bulk_item&". Instead, default function will be: Item_base(const Item_base&);
    //Item_base(const Bulk_item&);
    Item_base(const Item_base&);

    std::string book() const;
    virtual double net_price(std::size_t) const;
    virtual ~Item_base();
private:
    std::string isbn;
protected:
    double price;
};

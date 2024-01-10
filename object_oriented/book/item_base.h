//
// Created by 姚轩 on 2024/1/9.
//
#include <string>

class Item_base{
public:
    Item_base(const std::string& book = "", double sales_price = 0);
    std::string book() const;
    virtual double net_price(std::size_t) const;
    virtual ~Item_base();
private:
    std::string isbn;
protected:
    double price;
};

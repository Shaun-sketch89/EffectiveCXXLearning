#include "sales_item.h"
#include <set>

class Basket{
    typedef bool (*Comp)(const Sales_item&, const Sales_item&);
public:
    typedef std::multiset<Sales_item, Comp> set_type;
    typedef set_type::size_type size_type;
    typedef set_type::const_iterator const_iterator;
    Basket();
    void add_item(const Sales_item&);
    double total() const;
private:
    set_type items;
};
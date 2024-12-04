//
// Created by 姚轩 on 2024/1/26.
//
#include "bulk_item.h"
#include "handle.h"

// Sales_item类使用句柄类时，无需关心指针的管理，实现更简单；
// 同时泛型句柄类可以被不同类型使用，是一个更通用抽象的设计
class Sales_item{
public:
    Sales_item();
    //Sales_item(Item_base*);
    //revised to following
    Sales_item(const Item_base&);
    Sales_item(const Sales_item&);
    Sales_item& operator=(const Sales_item&);
    Item_base& operator*();
    const Item_base& operator*() const;
    Item_base* operator->();
    const Item_base* operator->() const;
    //int get_count();
    ~Sales_item();
private:
    Handle<Item_base> h;
};
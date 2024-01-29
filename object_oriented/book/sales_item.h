//
// Created by 姚轩 on 2024/1/26.
//
#include "bulk_item.h"

// 面向对象编程一个具有讽刺意味的地方是，使用对象无法获得动态行为，而需要使用指针或引用
// 句柄类的作用是可以使得用户获得动态行为，但无需操心指针的管理
// C++中的一个通用技术就是使用包装类或者句柄类
class Sales_item{
public:
    Sales_item();
    Sales_item(Item_base&);
    Sales_item(const Sales_item&);
    Sales_item& operator=(const Sales_item&);
    Item_base& operator*();
    const Item_base& operator*() const;
    Item_base* operator->();
    const Item_base* operator->() const;
    ~Sales_item();
private:
    int count;
    Item_base* p;
};
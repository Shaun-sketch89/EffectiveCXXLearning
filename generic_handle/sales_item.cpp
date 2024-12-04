//
// Created by 姚轩 on 2024/1/29.
//
#include "sales_item.h"

Sales_item::Sales_item(): h(0) {}

Sales_item::Sales_item(const Item_base& i): h(i.clone()) {}

// 重要：
// 不需要拷贝控制成员：合成版本可用
// 本类是句柄类的用户，句柄类对指针进行了管理，用户就不需要再关心指针的管理

// forward work to handle
Item_base& Sales_item::operator*() {
    return *h;
}

const Item_base& Sales_item::operator*() const {
    return *h;
}

Item_base* Sales_item::operator->() {
    // note here we use the operator-> of handle
    return h.operator->();
}

const Item_base* Sales_item::operator->() const {
    return h.operator->();
}
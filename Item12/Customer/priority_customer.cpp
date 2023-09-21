//
// Created by 姚轩 on 2023/9/19.
//
#include "priority_customer.h"

PriorityCustomer::PriorityCustomer(const std::string &name, const Date &lastTransaction, int priority)
:Customer(name, lastTransaction), priority(priority)
{
    logCall("Priority customer constructor");
}

PriorityCustomer::PriorityCustomer(const PriorityCustomer& rhs)
:Customer(rhs), priority(rhs.priority)
{
    logCall("Priority customer copy constructor");
}

PriorityCustomer& PriorityCustomer::operator=(const PriorityCustomer& rhs){
    logCall("Priority customer copy assignment constructor");
    Customer::operator=(rhs);
    priority = rhs.priority;
    return *this;
}
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

int main(){
    PriorityCustomer customer("aa", Date("2023-9-16"), 1);
    PriorityCustomer customer1(customer);
    PriorityCustomer customer2("bb", Date("2023-09-17"), 2);
    customer2 = customer1;
    return 0;
}
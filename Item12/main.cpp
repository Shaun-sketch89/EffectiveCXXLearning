//
// Created by 姚轩 on 2023/9/21.
//
#include "priority_customer.h"

int main(){
    PriorityCustomer customer("aa", Date("2023-9-16"), 1);
    PriorityCustomer customer1(customer);
    PriorityCustomer customer2("bb", Date("2023-09-17"), 2);
    customer2 = customer1;
    return 0;
}
#include "customer.h"

Date::Date(std::string date)
:date(date)
{}

Customer::Customer(const std::string &name, const Date &lastTransaction)
:name(name), lastTransaction(lastTransaction)
{
    logCall("Customer constructor");
}

Customer::Customer(const Customer &rhs)
:name(rhs.name), lastTransaction(rhs.lastTransaction)
{
    logCall("Customer copy constructor");
}

Customer& Customer::operator=(const Customer &rhs) {
    logCall("Customer copy assignment operator");
    name = rhs.name;
    lastTransaction = rhs.lastTransaction;
    return *this;
}
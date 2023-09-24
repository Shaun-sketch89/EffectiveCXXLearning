#include <iostream>

void logCall(const std::string& funcName);

class Date{
public:
    Date(std::string date);
private:
    std::string date;
};

class Customer{
public:
    Customer(const std::string& name, const Date& lastTransaction);
    Customer(const Customer& rhs);
    Customer& operator=(const Customer& rhs);
private:
    std::string name;
    Date lastTransaction;
};
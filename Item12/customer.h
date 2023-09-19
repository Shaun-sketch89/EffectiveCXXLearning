#include <iostream>

void logCall(const std::string& funcName){
    std::cout << funcName << std::endl;
};

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
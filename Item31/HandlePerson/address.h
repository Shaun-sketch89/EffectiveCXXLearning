//
// Created by 姚轩 on 2023/12/19.
//
#include <string>

class Address{
public:
    Address(std::string address="");
    std::string address() const;
private:
    std::string theAddress;
};
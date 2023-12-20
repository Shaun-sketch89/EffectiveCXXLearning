//
// Created by 姚轩 on 2023/12/19.
//
#include <string>

class Date{
public:
    Date(std::string date="");
    std::string date() const;
private:
    std::string theDate;
};
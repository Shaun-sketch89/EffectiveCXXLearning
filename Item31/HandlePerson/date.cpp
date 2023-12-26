//
// Created by 姚轩 on 2023/12/19.
//
#include "date.h"

Date::Date(std::string date): theDate(date) {}

std::string Date::date() const {
    return theDate;
}
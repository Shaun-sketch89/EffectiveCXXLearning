//
// Created by 姚轩 on 2023/12/19.
//
#include "address.h"

Address::Address(std::string address): theAddress(address) {}

std::string Address::address() const {
    return theAddress;
}


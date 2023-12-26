//
// Created by 姚轩 on 2023/12/19.
//
#include "PersonImpl.h"

PersonImpl::PersonImpl(const std::string &name, const Date &birthday, const Address &addr):theName(name),
                                                                                           theBirthDay(birthday),
                                                                                           theAddress(addr) {}

std::string PersonImpl::name() const {
    return theName;
}

std::string PersonImpl::birthdate() const {
    return theBirthDay.date();
}

std::string PersonImpl::address() const {
    return theAddress.address();
}
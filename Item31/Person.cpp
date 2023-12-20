//
// Created by 姚轩 on 2023/12/19.
//
#include "Person.h"

Person::Person(const std::string &name, const Date &birthday, const Address &addr):pImpl(new PersonImpl(name, birthday, addr)) {}

std::string Person::name() const {
    return pImpl->name();
}

std::string Person::birthdate() const {
    return pImpl->birthDate;
}

std::string Person::address() const {
    return pImpl->address();
}
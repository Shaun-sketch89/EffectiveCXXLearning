//
// Created by 姚轩 on 2023/12/19.
//
#include "Person.h"
#include "PersonImpl.h"

Person::Person(const std::string &name, const Date &birthday, const Address &addr):pImpl(new PersonImpl(name, birthday, addr)) {}

std::string Person::name() const {
    return pImpl->name();
}

std::string Person::birthdate() const {
    return pImpl->birthdate();
}

std::string Person::address() const {
    return pImpl->address();
}
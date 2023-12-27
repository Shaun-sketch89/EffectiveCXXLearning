//
// Created by 姚轩 on 2023/12/26.
//
#include <iostream>
#include "AsiaPerson.h"

std::shared_ptr<Person> Person::create(PersonType type, const std::string &name, const Date &birthday, const Address &addr) {
    if (type == PersonType::yellowSkin){
        return std::shared_ptr<Person>(new AsiaPerson(name, birthday, addr));
    }else{
        std::cout << "Not implemented yet.";
    }
    return NULL;
}

Person::~Person(){}
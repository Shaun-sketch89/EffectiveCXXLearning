//
// Created by 姚轩 on 2023/12/19.
//
#include <iostream>
#include "date.h"
#include "address.h"
#include "Person.h"

int main(){
    Date d("1995-07-08");
    Address addr("Shanghai");
    // handle class
    //Person p("Maggie", d, addr);

    // interface class
    std::shared_ptr<Person> pp(Person::create(PersonType::yellowSkin, "Maggie", d, addr));
    std::cout << pp->name() << " was born on " << pp->birthDate() << " and now lives at " << pp->address() << std::endl;
}
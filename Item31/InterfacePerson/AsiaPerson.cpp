#include "AsiaPerson.h"

AsiaPerson::AsiaPerson(const std::string &name, const Date &birthday, const Address &addr)
: theName(name), theBirthDate(birthday), theAddress(addr)
{}

AsiaPerson::~AsiaPerson() {}

std::string AsiaPerson::name() const {
    return theName;
}

std::string AsiaPerson::birthDate() const {
    return theBirthDate.date();
}

std::string AsiaPerson::address() const {
    return theAddress.address();
}
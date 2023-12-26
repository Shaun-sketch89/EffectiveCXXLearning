#include <string>

/*
class PersonImpl;
class Date;
class Address;
*/
// provide two separate file including a declaration and a definition
#include "datefwd.h"
#include "addressfwd.h"
#include "PersonImplFwd.h"

class Person{
public:
    Person(const std::string& name, const Date& birthday, const Address& addr);
    std::string name() const;
    std::string birthdate() const;
    std::string address() const;
private:
    // note Person is a handle class("pimpl pointer": include a pointer to real implementation)
    // if we use pimpl, we can forward declare some user-defined types
    // this will truly separate interface from implementation which means clients of Person will recompile only if interface of Person has changed.
    std::shared_ptr<PersonImpl> pImpl;
};
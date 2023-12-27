#include <string>

#include "datefwd.h"
#include "addressfwd.h"

enum PersonType {
    yellowSkin = 0,
    blackSkin = 1,
    whiteSkin = 2
};

// interface class - specify an interface for derived class
// C++ allow data members and function implementation unlike JAVA
class Person{
public:
    static std::shared_ptr<Person> create(PersonType type, const std::string& name, const Date& birthday, const Address& addr);
    virtual ~Person();

    virtual std::string name() const = 0;
    virtual std::string birthDate() const = 0;
    virtual std::string address() const = 0;
};
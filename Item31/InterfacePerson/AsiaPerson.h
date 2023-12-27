#include "Person.h"
#include "date.h"
#include "address.h"

class AsiaPerson: public Person{
public:
    AsiaPerson(const std::string& name, const Date& birthday, const Address& addr);
    virtual ~AsiaPerson();

    std::string name() const;
    std::string birthDate() const;
    std::string address() const;
private:
    std::string theName;
    Date theBirthDate;
    Address theAddress;
};
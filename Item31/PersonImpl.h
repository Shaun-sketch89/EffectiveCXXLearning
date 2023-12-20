#include <string>
#include "date.h"
#include "address.h"

class PersonImpl{
public:
    PersonImpl(const std::string& name, const Date& birthday, const Address& addr);
    std::string name() const;
    std::string birthdate() const;
    std::string address() const;
private:
    std::string theName;
    Date theBirthDay;
    Address theAddress;
};
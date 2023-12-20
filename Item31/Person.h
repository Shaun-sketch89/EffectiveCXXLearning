#include <string>

class PersonImpl;
class Date;
class Address;

class Person{
public:
    Person(const std::string& name, const Date& birthday, const Address& addr);
    std::string name() const;
    std::string birthdate() const;
    std::string address() const;
private:
    std::shared_ptr<PersonImpl> pImpl;
};
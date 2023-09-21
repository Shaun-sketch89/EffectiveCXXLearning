#include "customer.h"

class PriorityCustomer: public Customer{
public:
    PriorityCustomer(const std::string &name, const Date &lastTransaction, int priority);
    PriorityCustomer(const PriorityCustomer& rhs);
    PriorityCustomer& operator=(const PriorityCustomer& rhs);
private:
    int priority;
};
#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>

class Customer
{
private:
    std::string name;
    std::string email;
    std::string phoneNumber;

public:
    Customer(const std::string &name, const std::string &email, const std::string &phoneNumber);
    void displayCustomerDetails() const;
};

#endif // CUSTOMER_H
#include "../include/Customer.h"
#include <iostream>

Customer::Customer(const std::string &name, const std::string &email, const std::string &phoneNumber)
    : name(name), email(email), phoneNumber(phoneNumber) {}

void Customer::displayCustomerDetails() const
{
    std::cout << "Customer Name: " << name << std::endl;
    std::cout << "Email: " << email << std::endl;
    std::cout << "Phone Number: " << phoneNumber << std::endl;
}
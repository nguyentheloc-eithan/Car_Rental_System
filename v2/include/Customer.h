#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
#include <vector>
#include "Service.h"

class Customer
{
private:
    std::string name;
    std::string email;
    std::string phoneNumber;
    std::vector<Service> serviceHistory; // Store service history

public:
    Customer(); // Default constructor
    Customer(const std::string &name, const std::string &email, const std::string &phoneNumber);
    void addService(const Service &service);
    void displayServiceHistory() const;
    std::string getPhoneNumber() const;
    void saveToFile() const;
    static Customer loadFromFile(const std::string &phoneNumber);
};

#endif // CUSTOMER_H
#include "../include/Customer.h"
#include <fstream>
#include <iostream>
#include "../include/json.hpp"

using json = nlohmann::json;

// Default constructor
Customer::Customer() : name(""), email(""), phoneNumber("") {}

Customer::Customer(const std::string &name, const std::string &email, const std::string &phoneNumber)
    : name(name), email(email), phoneNumber(phoneNumber) {}

void Customer::addService(const Service &service)
{
    serviceHistory.push_back(service);
}

void Customer::displayServiceHistory() const
{
    std::cout << "=== Service History for " << name << " ===\n";
    for (const auto &service : serviceHistory)
    {
        service.displayServiceDetails();
        std::cout << "-------------------\n";
    }
}

std::string Customer::getPhoneNumber() const
{
    return phoneNumber;
}

void Customer::saveToFile() const
{
    json customerData;
    customerData["name"] = name;
    customerData["email"] = email;
    customerData["phoneNumber"] = phoneNumber;

    json servicesData;
    for (const auto &service : serviceHistory)
    {
        json serviceData;
        serviceData["type"] = service.getServiceType();
        serviceData["date"] = service.getDate();
        serviceData["description"] = service.getDescription();
        servicesData.push_back(serviceData);
    }
    customerData["services"] = servicesData;

    std::ofstream file("data/customers/" + phoneNumber + ".json");
    file << customerData.dump(4); // Pretty print with 4 spaces
    file.close();
}

Customer Customer::loadFromFile(const std::string &phoneNumber)
{
    std::ifstream file("data/customers/" + phoneNumber + ".json");
    if (!file.is_open())
    {
        throw std::runtime_error("Customer not found.");
    }

    json customerData;
    file >> customerData;
    file.close();

    Customer customer(customerData["name"], customerData["email"], customerData["phoneNumber"]);

    for (const auto &serviceData : customerData["services"])
    {
        Service service(serviceData["type"], serviceData["date"], serviceData["description"]);
        customer.addService(service);
    }

    return customer;
}
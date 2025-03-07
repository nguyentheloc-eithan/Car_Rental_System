#include "../include/Service.h"
#include <iostream>

Service::Service(const std::string &serviceType, const std::string &date, const std::string &description)
    : serviceType(serviceType), date(date), description(description) {}

void Service::displayServiceDetails() const
{
    std::cout << "Service Type: " << serviceType << "\n";
    std::cout << "Date: " << date << "\n";
    std::cout << "Description: " << description << "\n";
}

std::string Service::getServiceType() const
{
    return serviceType;
}

std::string Service::getDate() const
{
    return date;
}

std::string Service::getDescription() const
{
    return description;
}
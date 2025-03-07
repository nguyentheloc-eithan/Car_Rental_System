#include "../include/Service.h"

Service::Service(const std::string &serviceType, const std::string &date, const std::string &description)
    : serviceType(serviceType), date(date), description(description) {}

void Service::displayServiceDetails() const
{
    std::cout << "Service Type: " << serviceType << std::endl;
    std::cout << "Date: " << date << std::endl;
    std::cout << "Description: " << description << std::endl;
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
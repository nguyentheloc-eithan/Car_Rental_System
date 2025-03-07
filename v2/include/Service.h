#ifndef SERVICE_H
#define SERVICE_H

#include <string>
#include <iostream>

class Service
{
private:
    std::string serviceType; // Type of service (e.g., Engine, Transmission, Tires)
    std::string date;        // Date of service
    std::string description; // Description of the service

public:
    Service(const std::string &serviceType, const std::string &date, const std::string &description);
    void displayServiceDetails() const;
    std::string getServiceType() const;
    std::string getDate() const;
    std::string getDescription() const;
};

#endif // SERVICE_H
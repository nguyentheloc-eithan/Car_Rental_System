#ifndef SERVICE_H
#define SERVICE_H

#include <string>

class Service
{
private:
    std::string serviceType;
    std::string date;
    std::string description;

public:
    Service(const std::string &serviceType, const std::string &date, const std::string &description);
    void displayServiceDetails() const;
    std::string getServiceType() const;
    std::string getDate() const;
    std::string getDescription() const;
};

#endif // SERVICE_H
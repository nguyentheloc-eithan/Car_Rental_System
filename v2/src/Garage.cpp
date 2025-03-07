#include "../include/Garage.h"
#include "../include/Vehicle.h"
#include <fstream>
#include <iostream>
#include "../include/json.hpp"

using json = nlohmann::json;

void Garage::addVehicle(Vehicle *vehicle)
{
    vehicles.push_back(vehicle);
}

void Garage::displayAllVehicles() const
{
    for (const auto &vehicle : vehicles)
    {
        vehicle->displayDetails();
    }
}

Vehicle *Garage::findVehicleByLicensePlate(const std::string &licensePlate)
{
    for (const auto &vehicle : vehicles)
    {
        if (vehicle->getLicensePlate() == licensePlate)
        {
            return vehicle->isAvailable() ? vehicle : nullptr;
        }
    }
    return nullptr; // Vehicle not found or unavailable
}

void Garage::saveToFile(const std::string &filename) const
{
    json garageData;
    for (const auto &vehicle : vehicles)
    {
        json carData;
        carData["make"] = vehicle->getMake();
        carData["model"] = vehicle->getModel();
        carData["year"] = vehicle->getYear();
        carData["licensePlate"] = vehicle->getLicensePlate();
        carData["hasRented"] = vehicle->isAvailable();
        garageData.push_back(carData);
    }

    std::ofstream file("data/garages/" + filename);
    file << garageData.dump(4); // Pretty print with 4 spaces
    file.close();
}

void Garage::loadFromFile(const std::string &filename)
{
    std::ifstream file("data/garages/" + filename);
    if (!file.is_open())
    {
        std::cerr << "Error: Could not open file " << filename << "\n";
        return;
    }

    json garageData;
    file >> garageData;
    file.close();

    for (const auto &carData : garageData)
    {
        std::string make = carData["make"];
        std::string model = carData["model"];
        int year = carData["year"];
        std::string licensePlate = carData["licensePlate"];
        bool isAvailable = carData["hasRented"];

        Vehicle *vehicle = new Vehicle(make, model, year, licensePlate);
        vehicle->setAvailable(isAvailable);
        vehicles.push_back(vehicle);
    }
}
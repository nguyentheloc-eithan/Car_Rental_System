#include "../include/CarRentalSystem.h"
#include "../include/SUV.h"
#include "../include/Sedan.h"
#include "../include/Van.h"
#include "../include/Customer.h"
#include "../include/Service.h"

int main()
{
    CarRentalSystem system;

    // Add vehicles to the garage
    SUV *suv = new SUV("Honda", "CRX", 2020, "ABC123");
    Sedan *sedan = new Sedan("Toyota", "Camry", 2019, "XYZ456");
    Van *van = new Van("Ford", "Transit", 2021, "DEF789");

    system.addVehicleToGarage(suv);
    system.addVehicleToGarage(sedan);
    system.addVehicleToGarage(van);

    // Create a customer
    Customer customer("Ethan N", "Ethan.n@example.com", "123-456-7890");

    // Rent a vehicle
    system.rentVehicle(customer, suv, "2025-10-01", "2025-10-07", 500.0);

    // Perform services on the rented vehicle
    Service engineService("Engine Check", "2025-10-02", "Oil change and engine inspection");
    Service transmissionService("Transmission Check", "2025-10-03", "Transmission fluid change");
    Service tireService("Tire Check", "2025-10-04", "Tire rotation and pressure check");

    suv->addService(engineService);
    suv->addService(transmissionService);
    suv->addService(tireService);

    // Display all contracts
    system.displayAllContracts();

    // Display service history for the rented vehicle
    std::cout << "\nService History for Rented Vehicle:" << std::endl;
    suv->displayServiceHistory();

    return 0;
}
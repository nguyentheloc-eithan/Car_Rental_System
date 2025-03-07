#include "../include/CarRentalSystem.h"
#include "../include/SUV.h"
#include "../include/Sedan.h"
#include "../include/Van.h"
#include "../include/Customer.h"
#include "../include/Service.h"
#include <iostream>
#include <limits>
#include <regex>
#include <filesystem>
#include "../include/json.hpp"

using json = nlohmann::json;
namespace fs = std::filesystem;

// Function to get a valid integer input
int getIntegerInput(const std::string &prompt)
{
    int value;
    while (true)
    {
        std::cout << prompt;
        std::cin >> value;
        if (std::cin.fail())
        {
            std::cin.clear();                                                   // Clear the error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
            std::cout << "Invalid input. Please enter a number.\n";
        }
        else
        {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard extra input
            return value;
        }
    }
}

// Function to get a string input
std::string getStringInput(const std::string &prompt)
{
    std::string input;
    std::cout << prompt;
    std::getline(std::cin, input);
    return input;
}

// Function to validate date format (YYYY-MM-DD)
bool isValidDate(const std::string &date)
{
    std::regex datePattern(R"(\d{4}-\d{2}-\d{2})");
    return std::regex_match(date, datePattern);
}

// Function to validate email format
bool isValidEmail(const std::string &email)
{
    std::regex emailPattern(R"([a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,})");
    return std::regex_match(email, emailPattern);
}

// Function to display a list of garages
std::vector<std::string> listGarages()
{
    std::vector<std::string> garages;
    std::cout << "=== Available Garages ===\n";
    int index = 1;
    for (const auto &entry : fs::directory_iterator("data/garages"))
    {
        std::string garageName = entry.path().stem().string();
        std::cout << index << ". " << garageName << "\n";
        garages.push_back(garageName);
        index++;
    }
    return garages;
}

// Function for garage owner to register cars
void garageOwnerService()
{
    std::string garageName = getStringInput("Enter garage name: ");
    Garage garage;

    while (true)
    {
        std::cout << "\nChoose vehicle type:\n";
        std::cout << "  1. SUV\n";
        std::cout << "  2. Sedan\n";
        std::cout << "  3. Van\n";
        std::cout << "  4. Finish adding vehicles\n";
        int choice = getIntegerInput("Enter your choice (1-4): ");

        if (choice == 4)
            break;

        std::string make = getStringInput("  Enter make (e.g., Honda): ");
        std::string model = getStringInput("  Enter model (e.g., CRX): ");
        int year = getIntegerInput("  Enter year (e.g., 2020): ");
        std::string licensePlate = getStringInput("  Enter license plate (e.g., ABC123): ");

        switch (choice)
        {
        case 1:
            garage.addVehicle(new SUV(make, model, year, licensePlate));
            std::cout << "  SUV added successfully!\n";
            break;
        case 2:
            garage.addVehicle(new Sedan(make, model, year, licensePlate));
            std::cout << "  Sedan added successfully!\n";
            break;
        case 3:
            garage.addVehicle(new Van(make, model, year, licensePlate));
            std::cout << "  Van added successfully!\n";
            break;
        default:
            std::cout << "  Invalid choice. Please try again.\n";
            break;
        }
    }

    garage.saveToFile(garageName + ".json");
    std::cout << "Garage data saved to " << garageName << ".json\n";
}

// Function for customer to rent cars and use services
void customerService()
{
    // List available garages
    std::vector<std::string> garages = listGarages();
    if (garages.empty())
    {
        std::cout << "No garages available.\n";
        return;
    }

    int garageChoice = getIntegerInput("Enter the number of the garage you want to visit: ");
    if (garageChoice < 1 || garageChoice > garages.size())
    {
        std::cout << "Invalid choice.\n";
        return;
    }

    std::string garageName = garages[garageChoice - 1];
    Garage garage;
    garage.loadFromFile(garageName + ".json");

    std::cout << "\n=== Available Cars in " << garageName << " ===\n";
    garage.displayAllVehicles();

    // Rent a vehicle or use services
    std::string licensePlate = getStringInput("Enter the license plate of the vehicle (e.g., ABC123): ");
    Vehicle *vehicle = garage.findVehicleByLicensePlate(licensePlate);
    if (!vehicle)
    {
        std::cout << "Vehicle not found.\n";
        return;
    }

    // Check if the customer is returning
    std::string phoneNumber = getStringInput("Enter your phone number: ");
    Customer customer;
    try
    {
        customer = Customer::loadFromFile(phoneNumber);
        std::cout << "Welcome back, " << customer.getPhoneNumber() << "!\n";
    }
    catch (const std::exception &e)
    {
        std::cout << "New customer detected.\n";
        std::string name = getStringInput("Enter your name: ");
        std::string email;
        while (true)
        {
            email = getStringInput("Enter your email: ");
            if (isValidEmail(email))
                break;
            std::cout << "Invalid email format. Please try again.\n";
        }
        customer = Customer(name, email, phoneNumber);
    }

    // Rent or service
    std::cout << "\nChoose an option:\n";
    std::cout << "1. Rent the vehicle\n";
    std::cout << "2. Use car care services\n";
    int choice = getIntegerInput("Enter your choice (1-2): ");

    if (choice == 1)
    {
        if (!vehicle->isAvailable())
        {
            std::cout << "Vehicle is not available for rent.\n";
            return;
        }

        std::string startDate, endDate;
        while (true)
        {
            startDate = getStringInput("Enter rental start date (YYYY-MM-DD): ");
            if (isValidDate(startDate))
                break;
            std::cout << "Invalid date format. Please use YYYY-MM-DD.\n";
        }

        while (true)
        {
            endDate = getStringInput("Enter rental end date (YYYY-MM-DD): ");
            if (isValidDate(endDate))
                break;
            std::cout << "Invalid date format. Please use YYYY-MM-DD.\n";
        }

        double totalCost = getIntegerInput("Enter total cost (e.g., 500): ");
        vehicle->setAvailable(false);
        garage.saveToFile(garageName + ".json");

        std::cout << "Vehicle rented successfully!\n";
    }
    else if (choice == 2)
    {
        std::cout << "\n=== Car Care Services ===\n";
        while (true)
        {
            std::cout << "\nChoose service type:\n";
            std::cout << "1. Engine Check\n";
            std::cout << "2. Transmission Check\n";
            std::cout << "3. Tire Check\n";
            std::cout << "4. Finish adding services\n";
            int serviceChoice = getIntegerInput("Enter your choice (1-4): ");

            if (serviceChoice == 4)
                break;

            std::string date, description;
            while (true)
            {
                date = getStringInput("Enter service date (YYYY-MM-DD): ");
                if (isValidDate(date))
                    break;
                std::cout << "Invalid date format. Please use YYYY-MM-DD.\n";
            }

            switch (serviceChoice)
            {
            case 1:
                description = getStringInput("Enter engine service description (e.g., Oil change and engine inspection): ");
                customer.addService(Service("Engine Check", date, description));
                break;
            case 2:
                description = getStringInput("Enter transmission service description (e.g., Transmission fluid change): ");
                customer.addService(Service("Transmission Check", date, description));
                break;
            case 3:
                description = getStringInput("Enter tire service description (e.g., Tire rotation and pressure check): ");
                customer.addService(Service("Tire Check", date, description));
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
                break;
            }
        }

        customer.saveToFile();
        std::cout << "Services added successfully!\n";
    }
    else
    {
        std::cout << "Invalid choice.\n";
    }
}

int main()
{
    std::cout << "=== Welcome to the Car Rental System ===\n";
    std::cout << "Are you a:\n";
    std::cout << "1. Garage Owner\n";
    std::cout << "2. Customer\n";
    int choice = getIntegerInput("Enter your choice (1-2): ");

    if (choice == 1)
    {
        garageOwnerService();
    }
    else if (choice == 2)
    {
        customerService();
    }
    else
    {
        std::cout << "Invalid choice. Exiting...\n";
    }

    return 0;
}
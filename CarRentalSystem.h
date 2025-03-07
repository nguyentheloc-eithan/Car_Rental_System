#ifndef CARRENTALSYSTEM_H
#define CARRENTALSYSTEM_H

#include <iostream>
#include <string>
#include <list>
#include <fstream>

using namespace std;

class Vehicle
{
public:
    int choice_e;
    int choice_trans;
    int choice_tires;

    bool whole_system = false;
    bool oil_change = false;
    bool clean = false;

    bool adjustment = false;
    bool replacement = false;

    bool overhaul = false;
    bool fluid_change = false;

    string history_e1;
    string history_e2;
    string history_e3;
    string date_e1;
    string date_e2;
    string date_e3;

    string history_trans1;
    string history_trans2;
    string date_trans1;
    string date_trans2;

    string history_tires1;
    string history_tires2;
    string date_tires1;
    string date_tires2;

    virtual void serviceEngine() = 0;
    virtual void serviceTransmission() = 0;
    virtual void serviceTires() = 0;
};

class welcome
{
private:
    string type;
    enum TYPE
    {
        SUV,
        Sedan,
        Van,
        pickup,
    };

    TYPE car_TYPE(string const &inString)
    {
        if (inString == "SUV")
            return SUV;
        if (inString == "Sedan")
            return Sedan;
        if (inString == "Van")
            return Van;
        if (inString == "pickup")
            return pickup;
    }

public:
    string getType()
    {
        return type;
    }
    void setType_vehicle(string type_car)
    {
        type = type_car;
        cout << "Enter car type (SUV / Sedan / Van): ";
        cout << "Select: ";
        cin >> type;
        cout << "You choose type: " << type << endl;
    }

    int welcom()
    {
        ifstream in("welcome.txt");

        if (!in)
        {
            cout << "Cannot open input file.\n";
        }
        char str[1000];
        while (in)
        {
            in.getline(str, 1000);
            if (in)
                cout << str << endl;
        }

        cout << '\n'
             << endl;
    }
};
void e()
{
    cout << endl;
}
void e2()
{
    cout << endl;
    cout << endl;
}

class SUV : public Vehicle
{
private:
    list<string> car_SUV = {"Honda CRX", "Kia Morning", "Ford Avo", "Chevrolet Ali"};
    list<string> history_SUV = {"Energy change"};
    string Name;

public:
    enum SUV_car
    {
        Honda_CRX,
        Kia_Morning,
        Ford_Avo,
        Chevrolet_Ali
    };
    SUV_car name_car(const string &name);
    string GetName();
    void SetName(string SUV_name);
    void serviceEngine() override;
    void serviceTransmission() override;
    void serviceTires() override;
    void show_service_history();
    void add_car(const string &s);
    void show_car_added();
};

class Sedan : public Vehicle
{
private:
    list<string> car_Sedan = {"Honda Civic", "Mazda 1", "Mazda 2", "Mazda 3", "Vios"};
    list<string> history_Sedan = {"..."};
    string Name;

public:
    enum Sedan_car
    {
        Honda_Civic,
        Mazda_1,
        Mazda_2,
        Mazda_3,
        Vios,
        Unknown
    };
    Sedan_car name_car(const std::string &name);
    string GetName();
    void SetName(string Sedan_name);
    void serviceEngine() override;
    void serviceTransmission() override;
    void serviceTires() override;
    void show_service_history();
    void add_car(const string &s);
    void show_car_added();
};

class Van : public Vehicle
{
private:
    list<string> car_Van = {"Huynhdai", "Thaco"};
    list<string> history_Van = {"..."};
    string Name;

public:
    enum Van_n
    {
        Huynhdai,
        Thaco
    };
    Van_n name_car(const string &name);
    string GetName();
    void SetName(string Van_name);
    void serviceEngine() override;
    void serviceTransmission() override;
    void serviceTires() override;
    void show_service_history();
    void add_car(const string &s);
    void show_car_added();
};

class CarRentalManagement
{
    friend class Rental_Contract;

private:
    bool rent;
    bool serviceFleet_ = false;
    int say;
    string fleet;
    string Driver_gender;
    string Driver_birth;
    string Driver_license;
    string Driver_postal;
    string Driver_email;
    string Driver_Name;
    string garage_location;
    string garage_NickName;
    string garage_Size;
    string garage_director;
    string rent_dayPick;
    string rent_dayReturn;
    int rent_totalPayment = 0;
    string rent_payMethod;
    string rent_garagePick;
    string rent_garageReturn;

public:
    void getInf_driver();
    void getInfo_garage();
    void getInfo_contract();
    void Manage_CarFleet();
    void Set_manage();
    int Get_manage();
    void add_car();
};

class Rental_Contract
{
    friend class Driver;

private:
    string rent_dayPick;
    string rent_dayReturn;
    int rent_totalPayment = 0;
    string rent_payMethod;
    string rent_garagePick;
    string rent_garageReturn;

public:
    class Driver;
    class Garage;
    class Contract;

    void showInfo_contract(CarRentalManagement *gp, CarRentalManagement *gr, CarRentalManagement *dp, CarRentalManagement *dr, CarRentalManagement *p);
};

class Rental_Contract::Driver
{
private:
    string Driver_gender;
    string Driver_birth;
    string Driver_license;
    string Driver_postal;
    string Driver_email;
    string Driver_Name;

public:
    void showInfo_driver(CarRentalManagement *N, CarRentalManagement *g, CarRentalManagement *b, CarRentalManagement *l, CarRentalManagement *p, CarRentalManagement *e);
};

class Rental_Contract::Garage
{
private:
    string garage_location;
    string garage_NickName;
    string garage_Size;
    string garage_director;

public:
    void showInfo_Garage(CarRentalManagement *N, CarRentalManagement *l, CarRentalManagement *d, CarRentalManagement *s);
};

class Welcome
{
private:
    string type;
    enum TYPE
    {
        SUV,
        Sedan,
        Van,
        pickup
    };
    TYPE car_TYPE(const string &inString);

public:
    string getType();
    void setType_vehicle(string type_car);
    int welcome();
};

#endif
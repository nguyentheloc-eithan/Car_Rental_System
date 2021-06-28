#include <iostream>
#include <string>
#include <list>
#include <fstream>

using namespace std;

class vehicle
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

class SUV : public vehicle
{
private:
    list<string> car_SUV = {"Honda CRX,", "Kia Morning,", "Ford Avo,", "Chevrolet Ali,"};
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
    SUV_car name_car(string const &name)
    {
        if (name == "Honda CRX")
            return Honda_CRX;
        if (name == "Kia a")
            return Kia_Morning;
        if (name == "Ford Avo")
            return Ford_Avo;
            if (name == "Chevrolet Ali")
            return Chevrolet_Ali;
    }

    string GetName()
    {
        return Name;
    }

    void SetName(string SUV_name)
    {
        Name = SUV_name;
        cout << "Choose the car you want: " << endl
             << " - Honda CRX " << endl
             << " - Kia a" << endl
             << " - Ford Avo" << endl
             << " - Chevrolet Ali" << endl;
        cout << "select: ";
        getline(cin >> ws, SUV_name);
        switch (name_car(SUV_name))
        {
        case Honda_CRX:
        {
            system("CLS");
            ifstream A("hondacrx.txt");
            char str[200];
            while (A)
            {
                A.getline(str, 200);
                if (A)
                    cout << str << endl;
            }
        }
        break;

        case Kia_Morning:
        {
            system("CLS");
            ifstream A("kia.txt");
            char str[200];
            while (A)
            {
                A.getline(str, 200);
                if (A)
                    cout << str << endl;
            }
        }
        break;

        case Ford_Avo:
        {
            system("CLS");
            ifstream A("ford.txt");
            char str[200];
            while (A)
            {
                A.getline(str, 200);
                if (A)
                    cout << str << endl;
            }
        }
        break;

        case Chevrolet_Ali:
        {
            system("CLS");
            ifstream A("chev.txt");
            char str[200];
            while (A)
            {
                A.getline(str, 200);
                if (A)
                    cout << str << endl;
            }
        }
        break;

        default:
            break;
        }
    }
    void serviceEngine()
    {
        // add a record to the vehicle history telling how the engine of the vehicle gets serviced (oil change, minor, major)
        cout << "We have some Engine Services, press: " << endl
             << "   1 . Elevate the whole Engine system " << endl
             << "   2 . Oil change " << endl
             << "   3 . CLean the engine" << endl;
        cin >> choice_e;
        switch (choice_e)
        {
        case 1:
        {
            whole_system = true;
            cout << "Enter the day you want to get service: ";
            getline(cin >> ws, date_e1);
            history_e1 = " Elevate the whole Engine system service ";
            break;
        }
        case 2:
        {
            oil_change = true;
            cout << "Enter the day you want to get service: ";
            getline(cin >> ws, date_e2);
            history_e2 = "Oil change service ";
            break;
        }
        case 3:
        {
            clean = true;
            cout << "Enter the day you want to get service: ";
            getline(cin >> ws, date_e3);
            history_e3 = "CLean the engine service ";
            break;
        }
        default:
            break;
        }
        if (whole_system == true)
            history_SUV.push_back(history_e1);
        else if (oil_change == true)
            history_SUV.push_back(history_e2);
        else if (clean == true)
            history_SUV.push_back(history_e3);
    }

    void serviceTransmission()
    {
        cout << "We have some Transmission Services, Press: " << endl
             << "   1 . Overhaul " << endl
             << "   2 . Fluid change " << endl;

        cin >> choice_trans;
        switch (choice_trans)
        {
        case 1:
        {
            overhaul = true;
            cout << "Enter the day you want to get service: ";
            getline(cin >> ws, date_trans1);
            history_trans1 = "The transmission overhaul service";
            break;
        }
        case 2:
        {
            fluid_change = true;
            cout << "Enter the day you want to get service: ";
            getline(cin >> ws, date_trans2);
            history_trans2 = "Fluid change service ";
            break;
        }
        default:
            break;
        }
        if (overhaul == true)
            history_SUV.push_back(history_trans1);
        else if (fluid_change == true)
            history_SUV.push_back(history_trans2);
    }
    void serviceTires()
    {
        // add a record to the vehicle history telling how the tires of the vehicle get serviced (adjustment, replacement)
        cout << "We have some Tires Services, Press: " << endl
             << "   1 . Replace to new tires " << endl
             << "   2 . Adjust the balance of tires " << endl;

        cin >> choice_tires;
        switch (choice_tires)
        {
        case 1:
        {
            replacement = true;
            cout << "Enter the day you want to get service: ";
            getline(cin >> ws, date_tires1);
            history_tires1 = "Replace to new tires service";
            break;
        }
        case 2:
        {
            adjustment = true;
            cout << "Enter the day you want to get service: ";
            getline(cin >> ws, date_tires2);
            history_tires2 = "Adjust the balance of tires service ";
            break;
        }
        default:
            break;
        }
        if (replacement == true)
            history_SUV.push_back(history_tires1);
        else if (adjustment == true)
            history_SUV.push_back(history_tires2);
    }
    void show_service_history()
    {
        for (auto it = history_SUV.begin(); it != history_SUV.end(); ++it)
            cout << *it << " ";
    }
    void add_car(string s)
    {
        car_SUV.push_back(s);
    }
    void show_car_added()
    {
        for (auto it = car_SUV.begin(); it != car_SUV.end(); ++it)
            cout << *it << " ";
    }
};
class Sedan : public vehicle
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
        Vios
    };
    Sedan_car name_car(string const &name)
    {
        if (name == "Honda Civic")
            return Honda_Civic;
        if (name == "Mazda 1")
            return Mazda_1;
        if (name == "Mazda 2")
            return Mazda_2;
        if (name == "Mazda 3")
            return Mazda_3;
        if (name == "Vios")
            return Vios;
    }
    string GetName()
    {
        return Name;
    }
    void SetName(string Sedan_name)
    {
        Name = Sedan_name;
        cout << "Choose the car you want: " << endl
             << " - Honda Civic " << endl
             << " - Mazda 1" << endl
             << " - Mazda 2" << endl
             << " - Mazda 3" << endl
             << " - Vios " << endl;
        cout << "Select: ";
        getline(cin >> ws, Sedan_name);
        switch (name_car(Sedan_name))
        {
        case Honda_Civic:
        {
            system("CLS");
            ifstream A("hondacivc.txt");
            char str[200];
            while (A)
            {
                A.getline(str, 200);
                if (A)
                    cout << str << endl;
            }
        };
        break;
        case Mazda_1:
        {
            system("CLS");
            ifstream A("mazda1.txt");
            char str[200];
            while (A)
            {
                A.getline(str, 200);
                if (A)
                    cout << str << endl;
            }
        }
        break;
        case Mazda_2:
        {
            system("CLS");
            ifstream A("mazda2.txt");
            char str[200];
            while (A)
            {
                A.getline(str, 200);
                if (A)
                    cout << str << endl;
            }
        }
        break;
        case Mazda_3:
        {
            system("CLS");
            ifstream A("mazda3.txt");
            char str[200];
            while (A)
            {
                A.getline(str, 200);
                if (A)
                    cout << str << endl;
            }
        }
        break;
        case Vios:
        {
            system("CLS");
            ifstream A("vios.txt");
            char str[200];
            while (A)
            {
                A.getline(str, 200);
                if (A)
                    cout << str << endl;
            }
            A.close();
        }
        break;
        default:
            break;
        }
    }
    void serviceEngine()
    {
        // add a record to the vehicle history telling how the engine of the vehicle gets serviced (oil change, minor, major)
        cout << "We have some Engine Services, press: " << endl
             << "   1 . Elevate the whole Engine system " << endl
             << "   2 . Oil change " << endl
             << "   3 . CLean the engine" << endl;
        cin >> choice_e;
        switch (choice_e)
        {
        case 1:
        {
            whole_system = true;
            cout << "Enter the day you want to get service: ";
            getline(cin >> ws, date_e1);
            history_e1 = " Elevate the whole Engine system service ";
            break;
        }
        case 2:
        {
            oil_change = true;
            cout << "Enter the day you want to get service: ";
            getline(cin >> ws, date_e2);
            history_e2 = "Oil change service ";
            break;
        }
        case 3:
        {
            clean = true;
            cout << "Enter the day you want to get service: ";
            getline(cin >> ws, date_e3);
            history_e3 = "CLean the engine service ";
            break;
        }
        default:
            break;
        }
        if (whole_system == true)
            history_Sedan.push_back(history_e1);
        else if (oil_change == true)
            history_Sedan.push_back(history_e2);
        else if (clean == true)
            history_Sedan.push_back(history_e3);
    }

    void serviceTransmission()
    {
        cout << "We have some Transmission Services, Press: " << endl
             << "   1 . Overhaul " << endl
             << "   2 . Fluid change " << endl;

        cin >> choice_trans;
        switch (choice_trans)
        {
        case 1:
        {
            overhaul = true;
            cout << "Enter the day you want to get service: ";
            getline(cin >> ws, date_trans1);
            history_trans1 = "The transmission overhaul service";
            break;
        }
        case 2:
        {
            fluid_change = true;
            cout << "Enter the day you want to get service: ";
            getline(cin >> ws, date_trans2);
            history_trans2 = "Fluid change service ";
            break;
        }
        default:
            break;
        }
        if (overhaul == true)
            history_Sedan.push_back(history_trans1);
        else if (fluid_change == true)
            history_Sedan.push_back(history_trans2);
    }
    void serviceTires()
    {
        // add a record to the vehicle history telling how the tires of the vehicle get serviced (adjustment, replacement)
        cout << "We have some Tires Services, Press: " << endl
             << "   1 . Replace to new tires " << endl
             << "   2 . Adjust the balance of tires " << endl;

        cin >> choice_tires;
        switch (choice_tires)
        {
        case 1:
        {
            replacement = true;
            cout << "Enter the day you want to get service: ";
            getline(cin >> ws, date_tires1);
            history_tires1 = "Replace to new tires service";
            break;
        }
        case 2:
        {
            adjustment = true;
            cout << "Enter the day you want to get service: ";
            getline(cin >> ws, date_tires2);
            history_tires2 = "Adjust the balance of tires service ";
            break;
        }
        default:
            break;
        }
        if (replacement == true)
            history_Sedan.push_back(history_tires1);
        else if (adjustment == true)
            history_Sedan.push_back(history_tires2);
    }
    void show_service_history()
    {
        for (auto it = history_Sedan.begin(); it != history_Sedan.end(); ++it)
            cout << *it << " ";
    }
    void add_car(string s)
    {
        car_Sedan.push_back(s);
    }
    void show_car_added()
    {
        for (auto it = car_Sedan.begin(); it != car_Sedan.end(); ++it)
            cout << *it << " ";
    }
};
class Van : public vehicle
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
    Van_n name_car(string const &name)
    {
        if (name == "Huynhdai")
            return Huynhdai;
        if (name == "Thaco")
            return Thaco;
    }
    string GetName()
    {
        return Name;
    }
    void SetName(string Van_name)
    {
        Name = Van_name;
        cout << "Choose the car you want: " << endl
             << " - Thaco " << endl
             << " - Huynhdai" << endl;
        cout << "Select: ";
        getline(cin >> ws, Van_name);
        switch (name_car(Van_name))
        {
        case Huynhdai:
        {
            system("CLS");
            ifstream A("huynhdai.txt"); //displaying details of model A
            char str[200];
            while (A)
            {
                A.getline(str, 200);
                if (A)
                    cout << str << endl;
            }
        }
        break;
        case Thaco:
        {
            system("CLS");
            ifstream A("thaco.txt"); //displaying details of model A
            char str[200];
            while (A)
            {
                A.getline(str, 200);
                if (A)
                    cout << str << endl;
            }
            A.close();
        }
        break;
        default:
            break;
        }
    }

    void serviceEngine()
    {
        // add a record to the vehicle history telling how the engine of the vehicle gets serviced (oil change, minor, major)
        cout << "We have some Engine Services, press: " << endl
             << "   1 . Elevate the whole Engine system " << endl
             << "   2 . Oil change " << endl
             << "   3 . CLean the engine" << endl;
        cin >> choice_e;
        switch (choice_e)
        {
        case 1:
        {
            whole_system = true;
            cout << "Enter the day you want to get service: ";
            getline(cin >> ws, date_e1);
            history_e1 = " Elevate the whole Engine system service ";
            break;
        }
        case 2:
        {
            oil_change = true;
            cout << "Enter the day you want to get service: ";
            getline(cin >> ws, date_e2);
            history_e2 = "Oil change service ";
            break;
        }
        case 3:
        {
            clean = true;
            cout << "Enter the day you want to get service: ";
            getline(cin >> ws, date_e3);
            history_e3 = "CLean the engine service ";
            break;
        }
        default:
            break;
        }
        if (whole_system == true)
            history_Van.push_back(history_e1);
        else if (oil_change == true)
            history_Van.push_back(history_e2);
        else if (clean == true)
            history_Van.push_back(history_e3);
    }

    void serviceTransmission()
    {
        cout << "We have some Transmission Services, Press: " << endl
             << "   1 . Overhaul " << endl
             << "   2 . Fluid change " << endl;

        cin >> choice_trans;
        switch (choice_trans)
        {
        case 1:
        {
            overhaul = true;
            cout << "Enter the day you want to get service: ";
            getline(cin >> ws, date_trans1);
            history_trans1 = "The transmission overhaul service";
            break;
        }
        case 2:
        {
            fluid_change = true;
            cout << "Enter the day you want to get service: ";
            getline(cin >> ws, date_trans2);
            history_trans2 = "Fluid change service ";
            break;
        }
        default:
            break;
        }
        if (overhaul == true)
            history_Van.push_back(history_trans1);
        else if (fluid_change == true)
            history_Van.push_back(history_trans2);
    }
    void serviceTires()
    {
        // add a record to the vehicle history telling how the tires of the vehicle get serviced (adjustment, replacement)
        cout << "We have some Tires Services, Press: " << endl
             << "   1 . Replace to new tires " << endl
             << "   2 . Adjust the balance of tires " << endl;

        cin >> choice_tires;
        switch (choice_tires)
        {
        case 1:
        {
            replacement = true;
            cout << "Enter the day you want to get service: ";
            getline(cin >> ws, date_tires1);
            history_tires1 = "Replace to new tires service";
            break;
        }
        case 2:
        {
            adjustment = true;
            cout << "Enter the day you want to get service: ";
            getline(cin >> ws, date_tires2);
            history_tires2 = "Adjust the balance of tires service ";
            break;
        }
        default:
            break;
        }
        if (replacement == true)
            history_Van.push_back(history_tires1);
        else if (adjustment == true)
            history_Van.push_back(history_tires2);
    }
    void show_service_history()
    {
        for (auto it = history_Van.begin(); it != history_Van.end(); ++it)
            cout << *it << " ";
    }

    void add_car(string s)
    {
        car_Van.push_back(s);
    }
    void show_car_added()
    {
        for (auto it = car_Van.begin(); it != car_Van.end(); ++it)
            cout << *it << " ";
    }
};

class CarRentalManagement
{
    friend class Rental_Contract;

private:
    bool rent;
    bool serviceFleet_ = false;
    int say;
    string fleet;
    //driver
    string Driver_gender;
    string Driver_birth;
    string Driver_license;
    string Driver_postal;
    string Driver_email;
    string Driver_Name;
    // garage
    string garage_location;
    string garage_NickName;
    string garage_Size;
    string garage_director;

    //contract
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

    void showInfo_contract(CarRentalManagement *gp, CarRentalManagement *gr, CarRentalManagement *dp, CarRentalManagement *dr, CarRentalManagement *p)
    {
        cout << "Pick vehicle from : " << (gp->rent_garagePick) << " "
             << "and return to"
             << " " << (gr->rent_garageReturn) << endl;
        cout << "day pick:  " << (dp->rent_dayPick) << " "
             << "to " << (dr->rent_dayReturn) << endl;
        cout << "Payment method: " << (p->rent_payMethod) << endl;
    }
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
    void showInfo_driver(CarRentalManagement *N, CarRentalManagement *g, CarRentalManagement *b, CarRentalManagement *l, CarRentalManagement *p, CarRentalManagement *e)
    {
        cout << "Customer Name:                 " << (N->Driver_Name) << endl;
        cout << "Customer gender:               " << (g->Driver_gender) << endl;
        cout << "Customer Date of Birth:        " << (b->Driver_birth) << endl;
        cout << "Customer license issued when:  " << (l->Driver_license) << endl;
        cout << "Customer Email:                " << (e->Driver_email) << endl;
        cout << "Customer Postal Address        " << (p->Driver_postal) << endl;
    }
};
class Rental_Contract::Garage
{
private:
    string garage_location;
    string garage_NickName;
    string garage_Size;
    string garage_director;

public:
    void showInfo_Garage(CarRentalManagement *N, CarRentalManagement *l, CarRentalManagement *d, CarRentalManagement *s)
    {
        cout << " The name of Garage:              " << (N->garage_NickName) << endl;
        cout << " The address of Garage:           " << (l->garage_location) << endl;
        cout << " The name of director of Garage:  " << (d->garage_director) << endl;
        cout << " The Size of Garage:              " << (s->garage_Size) << endl;
    }
};
void CarRentalManagement::getInf_driver()
{
    cout << "      Driver Information" << endl;
    cout << "Enter Name: ";
    getline(cin >> ws, Driver_Name);
    this->Driver_Name;

    cout << "Enter gender: ";
    getline(cin >> ws, Driver_gender);
    this->Driver_gender;

    cout << "Enter date of birth: ";
    getline(cin >> ws, Driver_birth);
    this->Driver_birth;

    cout << "Enter email: ";
    getline(cin >> ws, Driver_license);
    this->Driver_license;

    cout << "Enter date license available: ";
    getline(cin >> ws, Driver_email);
    this->Driver_email;

    cout << "Enter Postal Address: ";
    getline(cin >> ws, Driver_postal);
    this->Driver_postal;

    Rental_Contract::Driver D;
    cout << endl;
    cout << endl;
    cout << "INFORMATION OF DRIVER" << endl;
    D.showInfo_driver(this, this, this, this, this, this);
}

void CarRentalManagement::getInfo_garage()
{
    cout << "Enter name of garage: ";
    getline(cin >> ws, garage_NickName);
    this->garage_NickName;

    cout << "Enter address of garage: ";
    getline(cin >> ws, garage_location);
    this->garage_location;

    cout << "Enter Name of Director: ";
    getline(cin >> ws, garage_director);
    this->garage_director;

    cout << "Enter size (large, medium or small) : ";
    getline(cin >> ws, garage_Size);
    this->Driver_postal;

    cout << endl;
    cout << endl;
    cout << "INFORMATION OF GARAGE" << endl;
    Rental_Contract::Garage G;
    G.showInfo_Garage(this, this, this, this);
}
void CarRentalManagement::getInfo_contract()
{
    int idx0, idx1;
    cout << "Enter day pick: ";
    getline(cin >> ws, rent_dayPick);

    cout << "Enter day you'll return: ";
    getline(cin >> ws, rent_dayReturn);

    cout << "Enter name of garage you picked: " << endl;
    cout << " 1 . Hosta Garage" << endl
         << " 2 . Sharkfin Garage" << endl
         << " 3 . Golden Garage" << endl;
    cout << "Your choice:  ";
    cin >> idx0;
    if (idx0 == 1)
    {
        rent_garagePick = "Hosta Garage ";
        this->rent_garagePick;
    }
    else if (idx0 == 2)
    {
        rent_garagePick = "Sharkfin Garage";
        this->rent_garagePick;
    }
    else if (idx0 == 3)
    {
        rent_garagePick = "Golden Garage";
        this->rent_garagePick;
    }
    cout << "Enter name  of garage you will return: " << endl;
    cout << " 1 . Sharkfin Garage" << endl
         << " 2 . Golden Garage" << endl;
    cout << "Your choice:  ";
    cin >> idx1;
    if (idx1 == 1)
    {
        rent_garageReturn = "Sharkfin Garage";
        this->rent_dayReturn;
    }
    else if (idx1 == 2)
    {
        rent_garageReturn = "Golden Garage";
        this->rent_dayReturn;
    }

    cout << "Enter what method (cash, credit card, etc.. ): " << endl;
    cout << "Your choice:  ";
    getline(cin >> ws, rent_payMethod);
    this->rent_payMethod;

    cout << endl;
    cout << endl;
    cout << "HERE IS THE CONTRACT" << endl;
    Rental_Contract RC;
    RC.showInfo_contract(this, this, this, this, this);
}

void CarRentalManagement::Set_manage()
{
    cout << "Do you want to book(rent) or add a car with some services? ( 0 to Book/Rent, 1 to add car ): ";
    cin >> say;
    if (say == 0)
    {
        cout << "you choose to book/rent a car" << endl;
    }
    else
    {
        cout << endl;
        cout << "Your choice:  add a car" << endl;
    }
}
int CarRentalManagement::Get_manage()
{
    return say;
}
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

int main()
{
    string tmp;
    string car_type;
    string SUV_name;
    string Sedan_name;
    string Van_name;
    string b;

    SUV SUV1;
    Sedan Sedan1;
    Van Van1;

    welcome t;
    welcome type;
    t.welcom();
    cout << "----------------------------------------------------------------------" << endl;

    CarRentalManagement manage;
    manage.Set_manage();
    int a = manage.Get_manage();
    e();

    if (a == 0)
    {
        e();
        type.setType_vehicle(tmp);
        car_type = type.getType();

        if (car_type == "SUV" || car_type == "Suv" || car_type == "suv")
        {
            SUV1.SetName(tmp);
            SUV_name = SUV1.GetName();
        }
        else if (car_type == "Sedan" || car_type == "SEDAN" || car_type == "sedan")
        {
            Sedan1.SetName(tmp);
            Sedan_name = Sedan1.GetName();
        }
        else if (car_type == "Van" || car_type == "van" || car_type == "VAN")
        {
            Van1.SetName(tmp);
            Van_name = Van1.GetName();
        }
        e2();
        cout << "...................................................................." << endl;
        cout << "Do you Want to make a contract for rent the car: (yes/no) ";
        string q;
        cin >> q;

        CarRentalManagement Driver1;
        CarRentalManagement Garage1;
        CarRentalManagement Contract1;
        if (q == "yes" || q == "YES" || q == "Yes")
        {
            ///////////////////////////make contract
            Driver1.getInf_driver();
            e2();
            Garage1.getInfo_garage();
            e2();
            Contract1.getInfo_contract();
            //////////////////////////////////////////////////////////////////////////////// make contract
            e2();
            cout << "Do you want to add any Service for your car (yes/no): ";
            string ser;
            getline(cin >> ws, ser);
            if (ser == "yes" || ser == "YES" || ser == "Yes")
            {
                int i;
                cout << "There 3 services that we have: " << endl
                     << " 1 . Engine service " << endl
                     << " 2 . Transmission service " << endl
                     << " 3 . Tires service "
                     << "(Press 1, 2 or 3)" << endl;
                cin >> i;
                switch (i)
                {
                case 1:
                {
                    if (car_type == "SUV" || car_type == "Suv" || car_type == "suv")
                    {
                        SUV1.serviceEngine();
                        SUV1.show_service_history();
                    }
                    else if (car_type == "Sedan" || car_type == "SEDAN" || car_type == "sedan")
                    {
                        Sedan1.serviceEngine();
                        Sedan1.show_service_history();
                    }
                    else if (car_type == "Van" || car_type == "van" || car_type == "VAN")
                    {
                        Van1.serviceEngine();
                        Van1.show_service_history();
                    }
                    break;
                }
                case 2:
                {
                    if (car_type == "SUV" || car_type == "Suv" || car_type == "suv")
                    {
                        SUV1.serviceTransmission();
                        SUV1.show_service_history();
                    }
                    else if (car_type == "Sedan" || car_type == "SEDAN" || car_type == "sedan")
                    {
                        Sedan1.serviceTransmission();
                        Sedan1.show_service_history();
                    }
                    else if (car_type == "Van" || car_type == "van" || car_type == "VAN")
                    {
                        Van1.serviceTransmission();
                        Van1.show_service_history();
                    }
                    break;
                }
                case 3:
                {
                    if (car_type == "SUV" || car_type == "Suv" || car_type == "suv")
                    {
                        SUV1.serviceTires();
                        SUV1.show_service_history();
                    }
                    else if (car_type == "Sedan" || car_type == "SEDAN" || car_type == "sedan")
                    {
                        Sedan1.serviceTires();
                        Sedan1.show_service_history();
                    }
                    else if (car_type == "Van" || car_type == "van" || car_type == "VAN")
                    {
                        Van1.serviceEngine();
                        Van1.show_service_history();
                    }
                    break;
                }
                default:
                    break;
                }
            }
        }
        else
        {
            cout << "Thank you";
            return 0;
        }
    } //if  say = 0
    else
    {
        e2();
        type.setType_vehicle(tmp);
        car_type = type.getType();

        string name_add;

        if (car_type == "SUV" || car_type == "Suv" || car_type == "suv")
        {
            string suv_add;
            cout << "Enter the car you want to add: ";
            getline(cin >> ws, suv_add);
            SUV1.add_car(suv_add);
            name_add = suv_add;
        }
        else if (car_type == "Sedan" || car_type == "SEDAN" || car_type == "sedan")
        {
            string sedan_add;
            cout << "Enter the car you want to add: ";
            getline(cin >> ws, sedan_add);
            Sedan1.add_car(sedan_add);
            name_add = sedan_add;
        }
        else if (car_type == "Van" || car_type == "van" || car_type == "VAN")
        {
            string van_add;
            cout << "Enter the car you want to add: ";
            getline(cin >> ws, van_add);
            Van1.add_car(van_add);
            name_add = van_add;
        }
        e2();
        cout << "...................................................................." << endl;
        e();
        CarRentalManagement Driver1;
        Driver1.getInf_driver();
        e2();
        e2();
        cout << "Do you want to add any Service for your car (yes/no): ";
        string ser;
        getline(cin >> ws, ser);
        if (ser == "yes" || ser == "YES" || ser == "Yes")
        {
            int i;
            cout << "There 3 services that we have: " << endl
                 << " 1 . Engine service " << endl
                 << " 2 . Transmission service " << endl
                 << " 3 . Tires service "
                 << "(Press 1, 2 or 3)" << endl;
            cin >> i;
            switch (i)
            {
            case 1:
            {
                if (car_type == "SUV" || car_type == "Suv" || car_type == "suv")
                {
                    SUV1.serviceEngine();
                }
                else if (car_type == "Sedan" || car_type == "SEDAN" || car_type == "sedan")
                {
                    Sedan1.serviceEngine();
                }
                else if (car_type == "Van" || car_type == "van" || car_type == "VAN")
                {
                    Van1.serviceEngine();
                }
                break;
            }
            case 2:
            {
                if (car_type == "SUV" || car_type == "Suv" || car_type == "suv")
                {
                    SUV1.serviceTransmission();
                }
                else if (car_type == "Sedan" || car_type == "SEDAN" || car_type == "sedan")
                {
                    Sedan1.serviceTransmission();
                }
                else if (car_type == "Van" || car_type == "van" || car_type == "VAN")
                {
                    Van1.serviceTransmission();
                }
                break;
            }
            case 3:
            {
                if (car_type == "SUV" || car_type == "Suv" || car_type == "suv")
                {
                    SUV1.serviceTires();
                }
                else if (car_type == "Sedan" || car_type == "SEDAN" || car_type == "sedan")
                {
                    Sedan1.serviceTires();
                }
                else if (car_type == "Van" || car_type == "van" || car_type == "VAN")
                {
                    Van1.serviceEngine();
                }
                break;
            }
            default:
                break;
            }
        }
        if (car_type == "SUV" || car_type == "Suv" || car_type == "suv")
        {
            e();
            cout << "The list of cars SUV after added: " << endl;
            SUV1.show_car_added();
            e();
            cout << "History of car services(SUV): " << endl;
            SUV1.show_service_history();
        }
        else if (car_type == "Sedan" || car_type == "SEDAN" || car_type == "sedan")
        {
            e();
            cout << "The list of cars (Sedan) after added: " << endl;
            Sedan1.show_car_added();
            e();
            cout << "History of car services(Sedan): " << endl;
            Sedan1.show_service_history();
        }
        else if (car_type == "Van" || car_type == "van" || car_type == "VAN")
        {
            e();
            cout << "The list of cars (Van) after added: " << endl;
            Van1.show_car_added();
            e();
            cout << "History of car services(VAN): " << endl;
            Van1.show_service_history();
        }
    } //else // manage add
    system("pause>0");
    return 0;
}
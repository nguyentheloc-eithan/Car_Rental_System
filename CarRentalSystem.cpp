#include "CarRentalSystem.h"

SUV::SUV_car SUV::name_car(const string &name)
{
    if (name == "Honda CRX")
        return Honda_CRX;
    if (name == "Kia Morning")
        return Kia_Morning;
    if (name == "Ford Avo")
        return Ford_Avo;
    if (name == "Chevrolet Ali")
        return Chevrolet_Ali;
    throw invalid_argument("Invalid car name");
}

string SUV::GetName()
{
    return Name;
}

void SUV::SetName(string SUV_name)
{
    Name = SUV_name;
    cout << "Choose the car you want: " << endl
         << " - Honda CRX " << endl
         << " - Kia Morning" << endl
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
        break;
    }
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
        break;
    }
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
        break;
    }
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
        break;
    }
    default:
        break;
    }
}

void SUV::serviceEngine()
{
    cout << "We have some Engine Services, press: " << endl
         << "   1 . Elevate the whole Engine system " << endl
         << "   2 . Oil change " << endl
         << "   3 . Clean the engine" << endl;
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
        history_e3 = "Clean the engine service ";
        break;
    }
    default:
        break;
    }
    if (whole_system)
        history_SUV.push_back(history_e1);
    else if (oil_change)
        history_SUV.push_back(history_e2);
    else if (clean)
        history_SUV.push_back(history_e3);
}

void SUV::serviceTransmission()
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
    if (overhaul)
        history_SUV.push_back(history_trans1);
    else if (fluid_change)
        history_SUV.push_back(history_trans2);
}

void SUV::serviceTires()
{
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
    if (replacement)
        history_SUV.push_back(history_tires1);
    else if (adjustment)
        history_SUV.push_back(history_tires2);
}

void SUV::show_service_history()
{
    for (const auto &it : history_SUV)
        cout << it << " ";
}

void SUV::add_car(const string &s)
{
    car_SUV.push_back(s);
}

void SUV::show_car_added()
{
    for (const auto &it : car_SUV)
        cout << it << " ";
}

// Implementations for Sedan and Van classes
Sedan::Sedan_car Sedan::name_car(const string &name)
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

    return Unknown; // Handle unknown input
}
string
Sedan::GetName()
{
    {
        return this->Name;
    }
}

void Sedan::SetName(string Sedan_name)
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

void Sedan::serviceEngine()
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

void Sedan::serviceTransmission()
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

void Sedan::serviceTires()
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
void Sedan::show_service_history()
{
    for (auto it = history_Sedan.begin(); it != history_Sedan.end(); ++it)
        cout << *it << " ";
}

void Sedan::add_car(const string &s)
{
    car_Sedan.push_back(s);
}

void Sedan::show_car_added()
{
    for (auto it = car_Sedan.begin(); it != car_Sedan.end(); ++it)
        cout << *it << " ";
}
// Implementations for CarRentalManagement, Rental_Contract, and Welcome classes...

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
    } // if  say = 0
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
    } // else // manage add
    system("pause>0");
    return 0;
}
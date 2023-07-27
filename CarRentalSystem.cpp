   #include <iostream>
#include <conio.h>
#include <stdlib.h>

using namespace std;

struct Cars
{
    string Company[200] = {"Maruti", "Honda", "Tata", "Hyundai", "Toyota", "Ford", "Skoda", "Volkswagen", "Renault", "Mahindra"};
    string Model[200] = {"Swift", "City", "Tiago", "Verna", "Innova", "Ecosport", "Rapid", "Polo", "Kwid", "XUV"};
    string Color[200] = {"White", "Black", "Red", "Blue", "White", "Silver", "Black", "Grey", "Brown", "Orange"};
    string MaxSpeed[200] = {"180", "200", "150", "180", "210", "190", "210", "220", "190", "170"};
    string FuelType[200] = {
        "Petrol",
        "Diesel",
        "Petrol",
        "Petrol",
        "Diesel",
        "Diesel",
        "Petrol",
        "Diesel",
        "Petrol",
        "Diesel",
    };
    string Manufacturer[200] = {
        "India",
        "Japan",
        "India",
        "Japan",
        "India",
        "India",
        "Germany",
        "Germany",
        "Japan",
        "India",
    };
    int Price[200] = {
        700000,
        900000,
        500000,
        700000,
        800000,
        700000,
        1000000,
        1100000,
        900000,
        600000,
    };
} car;

struct lease_info
{
    string First_Name[100];
    string Last_Name[100];
    string Proof_ID[100];
    string Phone_Number[100];
    int Payment[100];
} lease;
void Menu()
{
    int num = 1;
    for (int i = 0; i < 8; i++)
    {
        cout << "\t\t" << num << ". " << car.Company[i] << endl;
        num++;
    }
}

void Details(int Choice)
{
    cout << "\t\t ---------------------------" << endl;
    cout << "\t\t Company: " << car.Company[Choice - 1] << endl;
    cout << "\t\t ---------------------------" << endl;
    cout << "\t\t Model: " << car.Model[Choice - 1] << endl;
    cout << "\t\t Color: " << car.Color[Choice - 1] << endl;
    cout << "\t\t Max Speed: " << car.MaxSpeed[Choice - 1] << endl;
    cout << "\t\t Fuel Type: " << car.FuelType[Choice - 1] << endl;
    cout << "\t\t Manufacturer: " << car.Manufacturer[Choice - 1] << endl;
    cout << endl;
    cout << "\t\t Price: " << car.Price[Choice - 1] << endl;
}

void check_lease(int j)
{
    if (lease.Payment[j] >= car.Price[j])
    {
        cout << "\t\t\t Payment Successful" << endl;
        cout << "\t\t\t Thank you for using our Service" << endl;
    }
    else
    {
        cout << "\t\t\t Payment Unsuccessful" << endl;
        cout << "\t\t\t Try Again!" << endl;
    }
}

void user_input(int Choice)
{
    system("cls");
    int i;
    int j = Choice - 1;
    cout << "\t\t ---------------------------" << endl;
    cout << "\t\t\t\t Please provide your details: ";
    cout << "\t\t ---------------------------" << endl;
    cout << "\t\t NOTE: Please provide your first name" << endl;
    cout << "\t\t NOTE: PAYMENT WON'T BE PROCEED IF THE AMOUNT IS LESS THAN THE RATE OF THE CAR" << endl;
    cout << "\t\t ---------------------------" << endl;
    cout << "\t\t\t\t First Name: ";
    cin >> lease.First_Name[j];
    cout << "\t\t\t\t Last Name : ";
    cin >> lease.Last_Name[j];
    cout << "\t\t\t\t Enter your Proof ID: ";
    cin >> lease.Proof_ID[j];
    cout << "\t\t\t\t Enter your Phone Number :";
    cin >> lease.Phone_Number[j];
    cout << "\t\t ---------------------------" << endl;
    cout << "\t\t\t\t Enter the amount: ";
    cin >> lease.Payment[j]; 

    check_lease(j);
}
int login()
{
    string pass = "";
    char ch;
    cout << "\t\t Car Rental System Login" << endl;
    cout << "\t\t Enter Password: ";
    ch = _getch();
    while (ch != 8)
    {
        pass.push_back(ch);
        cout << '*';
        ch = _getch();
    }
    if (pass == "pass")
    {
        cout << "\t Password Matched" << endl;
        cout << "\t Loading..." << endl;
        system("PAUSE");
        cout << "Welcome to our system" << endl;
        system("cls");
    }
    else
    {
        cout << "\t Sorry! Password Not Matched" << endl;
        cout << "\t Try Again" << endl;
        system("PAUSE");
        system("cls");
        login();
    }
    return 0;
}
int main()
{
    login();
    string decide = "yes";
    cout << "\t\t ---------------------------" << endl;
    cout << "\t\t Welcome to Car Rental System" << endl;
    cout << "\t\t ---------------------------" << endl;
    cout << endl;
    cout << "\t\t Choose your Car" << endl;
    cout << "\t\t ---------------------------" << endl;

    while (decide != "Exit")
    {
        Menu();
        cout << "\t\t ---------------------------" << endl;
        cout << "\t\t Your Choice: " << endl;
        int choice;
        cin >> choice;
        Details(choice); // Details

        cout << "\t\t Are you sure you want to rent this car (Yes/No/Exit)" << endl;
        cin >> decide;
        if (decide == "yes" || decide == "Yes")
        {
            user_input(choice);
            cout << "\t\t Car Rented sucessfully" << endl;
            cout << "\t\t ---------------------------" << endl;
            cout << "\t\t Comapny: " << car.Company[choice] << endl;
            cout << "\t\t Model: " << car.Model[choice] << endl;
            cout << "\t\t Color: " << car.Color[choice] << endl;
            cout << "\t\t Max Speed: " << car.MaxSpeed[choice] << endl;
            cout << "\t\t Fuel Type: " << car.FuelType[choice] << endl;
            cout << "\t\t Manufacturer: " << car.Manufacturer[choice] << endl;
            cout << "\t\t Price: " << car.Price[choice] << endl;
            cout << "\t\t ---------------------------" << endl;
            cout << "\t\t Thank you for using our system" << endl;
            cout << "\t\t ---------------------------" << endl;
            system("PAUSE");
            system("cls");
        }
        else if (decide == "no" || decide == "No")
        {
            cout << "\t\t Choose your option" << endl;
            cout << "\t\t ---------------------------" << endl;
        }
        else if (decide == "Exit")
        {
            cout << "\t\t Thank you for using our system" << endl;
            cout << "\t\t ---------------------------" << endl;
            system("PAUSE");
            system("cls");
        }
        else
        {
            cout << "\t\t Invalid Input" << endl;
            cout << "\t\t ---------------------------" << endl;
            system("PAUSE");
            system("cls");
        }
    }
    return 0;
}
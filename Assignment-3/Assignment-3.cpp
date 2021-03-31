// Assignment-3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <algorithm> 



using namespace std;
//usa
const double ShipCostUsa1 = 6;
const double ShipCostUsa2 = 9;
const double ShipCostUsa3 = 12;
//can
const double ShipCostCan1 = 8;
const double ShipCostCan2 = 12;
const double ShipCostCan3 = 15;
//aus
const double ShipCostAus1 = 10;
const double ShipCostAus2 = 14;
const double ShipCostAus3 = 17;
//global veriable
double ShipCost = 0;
double Order = 0;
string fragile;
string Item;
string Location;
double TotalCost;

int main()
{

    cout << "................................................." << endl;
    cout << "ITCS 2530 - Programming Assigment week #3        " << endl;
    cout << "................................................." << endl;
    cout << "\n" << endl;

    cout << "Please Enter the Item name (no space )....................:";
    cin >> Item;

    do
    {
        cout << "is the Item fragile? (y=yes/n=no).........................:";
        cin >> fragile;

        transform(fragile.begin(), fragile.end(), fragile.begin(), std::toupper);

        if (fragile == "Y")
        {
            ShipCost += 2;
            break;
        }
        else if (fragile == "N")
        {
            ShipCost += 0;
            break;
        }
        else
        {
            cout << "\n" << endl;
            cout << "Invalid entry, please try again..." << endl;

        }

    } while (true);


    cout << "please enter your Order total.............................:";
    cin >> Order;

    cout << "please enter your destenation. (usa/can/aus)..............:";
    cin >> Location;

    cout << "\n" << endl;

    transform(Location.begin(), Location.end(), Location.begin(), std::toupper);
    if (Location == "USA")
    {
        if (Order < 50.00)
            ShipCost += ShipCostUsa1;
        else if (Order >= 50.01 && Order <= 100.00)
            ShipCost += ShipCostUsa2;
        else if (Order >= 100.01 && Order <= 150.00)
            ShipCost += ShipCostUsa3;
        else
            ShipCost += 0;
    }
    else if (Location == "CAN")
    {
        if (Order < 50.00)
            ShipCost += ShipCostCan1;
        else if (Order >= 50.01 && Order <= 100.00)
            ShipCost += ShipCostCan2;
        else if (Order >= 100.01 && Order <= 150.00)
            ShipCost += ShipCostCan3;
        else
            ShipCost += 0;
    }
    else if (Location == "AUS")
    {
        if (Order < 50.00)
            ShipCost += ShipCostAus1;
        else if (Order >= 50.01 && Order <= 100.00)
            ShipCost += ShipCostAus2;
        else if (Order >= 100.01 && Order <= 150.00)
            ShipCost += ShipCostAus3;
        else
            ShipCost += 0;
    }

    TotalCost = ShipCost + Order;

    cout << "your Item is...................: " << Item << endl;
    cout << "your shiping cost is...........: " << "$" << ShipCost << endl;
    cout << "your are shiping to............: " << Location << endl;
    cout << "your total shipping cost are...: " << "$" << TotalCost << endl;
    cout << "\n" << endl;

    cout << "_______________________________thank you" << endl;


    ofstream file;
    file.open("Order.txt");

    if (!file)
    {
        cout << "error opening file" << endl;
        system("pause");
        return 1;
    }

    file << "your item is...................: " << Item << endl;
    file << "your shipping cost is...........: " << "$" << ShipCost << endl;
    file << "your are shipping to............: " << Location << endl;
    file << "your total shipping costs are...: " << "$" << TotalCost << endl;
    file << "\n" << endl;

    file << "---------------------------------Thank You!" << endl;

    file.close();

    system("pause");
    return 0;
}

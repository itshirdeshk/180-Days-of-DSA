#include <iostream>
using namespace std;

// Q1. Bank Customer Class:
class Customer
{
    string name;
    int accNumber;
    bool accBal;
    bool isActve;

    void deposit(int amount)
    {
        accBal += amount;
    }

    void withdraw(int amount)
    {
        if (accBal >= amount)
        {
            accBal -= amount;
        }
        else
        {
            cout << "Insufficient Balance\n";
        }
    }

    void transfer(int amount, Customer targetAccount)
    {
        if (accBal >= amount)
        {
            targetAccount.accBal += amount;
            accBal -= amount;
        }
        else
        {
            cout << "Insufficient Balance\n";
        }
    }

    void printDetails()
    {
        cout << "Customer Name : " << name << endl;
        cout << "Account Number : " << accNumber << endl;
        cout << "Account Balance : " << accBal << endl;
    }
};

// Q2. Car Class:
class Car
{
    string model;
    int year;
    double fuelLevel;
    int speed;
    bool isRunning = false;

    void startEngine()
    {
        isRunning = true;
        cout << "Engine Starts \n";
    }

    void stopEngine()
    {
        isRunning = false;
        cout << "Engine Stops \n";
    }

    void accelerate(int amount)
    {
        speed += amount;
    }

    void brake(int amount)
    {
        if (amount <= speed)
        {
            speed -= amount;
        }
    }

    void refuel(int amount)
    {
        if (amount + fuelLevel < 20)
        {
            fuelLevel += amount;
        }
    }

    void printStatus()
    {
        cout << "Car Model : " << model << endl;
        cout << "Speed : " << speed << endl;
        cout << "Fuel Level : " << fuelLevel << endl;
        cout << "Running : " << isRunning << endl;
    }
};

class Laptop
{
    string brand;
    double screenize;
    string processor;
    int ram;
    int storage;
    double batteryLevel;
    bool isOn = false;

    void powerOn()
    {
        isOn = true;
        cout << "Window is Starting up \n";
    }

    void powerOff()
    {
        isOn = false;
        cout << "Window is Shutting Down \n";
    }

    void openApps(int numApps)
    {
        for (int i = 1; i <= numApps; i++)
            cout << "Opening Application " << i << endl;
        batteryLevel -= numApps;
    }

    void closeApps(int numApps)
    {
        for (int i = 1; i <= numApps; i++)
            cout << "Closing Application " << i << endl;
        batteryLevel += numApps;
    }

    void charge(int amount)
    {
        if (amount + batteryLevel >= 100)
        {
            batteryLevel = 100;
        }
        else
        {
            batteryLevel += amount;
        }
    }

    void printSpecs()
    {
        cout << "Brand : " << brand << endl;
        cout << "Screen Size : " << screenize << endl;
        cout << "Processor : " << processor << endl;
        cout << "Ram : " << ram << endl;
        cout << "Storage : " << storage << endl;
        cout << "Battery Level : " << batteryLevel << endl;
    }
};

int main() {}
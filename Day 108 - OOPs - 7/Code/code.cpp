#include <iostream>
using namespace std;

// class exception
// {
// protected:
//     string msg;

// public:
//     exception(string msg)
//     {
//         this->msg = msg;
//     }

//     string what(){
//         return msg;
//     }
// };

class invalidAmountError : public runtime_error
{
public:
    invalidAmountError(const string &msg) : runtime_error(msg) {}
};

class Customer
{
    string name;
    int balance, account_number;

public:
    Customer(string name, int balance, int account_number)
    {
        this->name = name;
        this->balance = balance;
        this->account_number = account_number;
    }

    // Deposit
    void deposit(int amount)
    {
        if (amount > 0)
        {
            balance += amount;
            cout << amount << " is credited successfully\n";
        }
        else
        {
            throw runtime_error("Amount should be greater than zero");
        }
    }

    // Withdraw
    void withdraw(int amount)
    {
        if (amount > 0 && amount <= balance)
        {
            balance -= amount;
            cout << amount << " is debited successfully";
        }
        else if (amount < 0)
        {
            throw invalidAmountError("Amount should be greater than zero");
        }
        else
        {
            throw runtime_error("Your balance is low");
        }
    }
};

int main()
{
    Customer C1("Hirdesh", 5000, 10);
    try
    {
        C1.deposit(100);
        C1.withdraw(6000);
    }
    catch (const runtime_error &e)
    {
        cout << "Exception Occured: " << e.what() << endl;
    }
    catch (const bad_alloc &e)
    {
        cout << "Exception Occured: " << e.what() << endl;
    }
    catch (const invalidAmountError &e)
    {
        cout << "Exception Occured: " << e.what() << endl;
    }
    // Default catch block
    catch (...)
    {
        cout << "Exception Occured";
    }

    // Another Example

    // int a, b;
    // cin >> a >> b;

    // try
    // {
    //     if (b == 0)
    //         throw "Divide by Zero is not possible";
    //     int c = a / b;
    //     cout << c << endl;
    // }
    // catch (const char *e)
    // {
    //     cout << "Exception Occured: " << e << endl;
    // }

    // Another Example - 2
    // try
    // {
    //     int *p = new int[1000000000000000];
    //     cout << "Memory allocation is successfull";
    //     delete[] p;
    // }
    // catch (const bad_alloc &e)
    // {
    //     cout << "Exception occured: " << e.what() << endl;
    // }
}
#include <iostream>
using namespace std;

class Customer
{
    string name;
    int acc_num, balance;
    static int total_customer;
    static int total_balance;

public:
    Customer(string name, int acc_num, int balance)
    {
        this->name = name;
        this->acc_num = acc_num;
        this->balance = balance;
        total_customer++;
        total_balance += balance;
    }

    // This funtion is the member of class and also this function can access only static variable like total_customer.
    static void accessStatic(){
        cout<<total_customer<<endl;
        cout<<total_balance<<endl;
    }

    void deposit(int amount){
        if(amount > 0){
            balance += amount;
            total_balance += amount;
        }
    }

    void withdraw(int amount){
        if(amount <= balance && amount > 0){
            balance -= amount;
            total_balance -= amount;
        }
    }

    void display()
    {
        cout << name << " " << acc_num << " " << balance << " " << total_customer << endl;
    }
};

int Customer ::total_customer = 0;
int Customer ::total_balance = 0;

int main()
{
    Customer C1("Hirdesh", 1, 1000);
    Customer C2("Rohit", 2, 1000);
    Customer::accessStatic();

}
#include <iostream>
using namespace std;

class Customer
{
    string name;
    int acc_no;
    int balance;
    int *roi;

public:
    // Default Constructor
    Customer()
    {
        cout << "Hello Constructor\n";
        name = "Hirdesh";
        acc_no = 25662;
        balance = 50000;
        roi = new int[100];
    }

    // Parameterized Constructor
    Customer(string name, int acc_no, int balance)
    {
        this->name = name;
        this->acc_no = acc_no;
        this->balance = balance;
    }

    // Constructor Overloading
    Customer(string a, int b)
    {
        name = a;
        acc_no = b;
    }

    // Inline Constructor
    inline Customer(string a, int b, int c) : name(a), acc_no(b), balance(c) {}

    // Copy Constructor
    Customer(Customer &B){
        name = B.name;
        acc_no = B.acc_no;
        balance = B.balance;
    }

    void display()
    {
        cout << name << " " << acc_no << " " << balance << endl;
    }

    ~Customer(){
        delete roi;
        cout<<"Destructor Called"<<endl;
    }
};

int main()
{
    Customer C1;
    C1.display();
    Customer C2("Rohit", 25663, 50000);
    C2.display();
    Customer C3("Mohit", 25664);
    C3.display();
    Customer C4;
    C4 = C1;
    C4.display();

}
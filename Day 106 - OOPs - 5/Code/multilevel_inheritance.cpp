#include<iostream>
using namespace std;

class Person{
    protected:
    string name;
};

class Employee:public Person{
    protected:
    int salary;
};

class Manager: public Employee{
    public:
    string department;

    Manager(string name, int salary, string department){
        this->name = name;
        this->salary = salary;
        this->department = department;
    }
};

int main() {
    
}
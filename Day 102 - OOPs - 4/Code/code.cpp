#include <iostream>
using namespace std;

class Human
{
    // private:
    // int a;
    // protected:
    // int b;
    // public:
    // int c;

    // void fun(){
    //     a = 10;
    //     b = 20;
    //     c = 30;
    // }
    string religion, color;

protected:
    string name;
    int age;
    int weight;
};

// class Student: public Human{
//     int roll_no, fees;
// };

// class Student : protected Human
// {
//     int roll_no, fees;

// public:
//     // void fun(string a, int b, int c)
//     // {
//     //     name = a;
//     //     age = b;
//     //     weight = c;
//     // }
// };

class Student : private Human
{
    int roll_no, fees;

public:
    Student(string name, int age, int weight, int roll_no, int fees)
    {
        this->name = name;
        this->age = age;
        this->weight = weight;
        this->roll_no = roll_no;
        this->fees = fees;
    }

    void display()
    {
        cout << name << " " << age << " " << weight << " " << roll_no << " " << fees << endl;
    }
};

int main()
{
    // Human Hirdesh;
    // Hirdesh.c = 10;

    // Hirdesh.fun();

    Student S("Hirdesh", 20, 50, 28, 1000);
    S.display();

}
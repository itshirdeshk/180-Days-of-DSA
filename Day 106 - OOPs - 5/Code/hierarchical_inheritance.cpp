#include <iostream>
using namespace std;

class Human
{
    protected:
    string name;
    int age;
};

class Student : public Human
{
};

class Teacher : public Human
{
};

class Staff : public Human
{
};

int main()
{
}
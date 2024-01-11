#include <iostream>
using namespace std;

class Human
{
public:
    string name;
};

class Engineer : public virtual Human
{
public:
    string specilization;
};

class Youtuber : public virtual Human
{
public:
    int subs;
};

class CodeTeacher : public Engineer, public Youtuber
{
public:
    int salary;

    CodeTeacher(string specilization, int subs, string name, int salary)
    {
        this->name = name;
        this->specilization = specilization;
        this->subs = subs;
    }
};

int main()
{
}
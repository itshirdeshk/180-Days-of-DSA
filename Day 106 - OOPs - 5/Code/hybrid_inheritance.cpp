#include<iostream>
using namespace std;

class Student{
    protected:
    string name;
    int age;
};

class Male{
    protected:
    int height;
};

class Female{
    protected:
    int height;
};

class Boy: public Student, public Male{

};

class Girl: public Student, public Female{

};

int main() {
    
}
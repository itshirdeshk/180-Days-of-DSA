#include<iostream>
using namespace std;

class Engineer{
    public:
    string specilization;
};

class Youtuber{
    public:
    int subs;
};

class CodeTeacher: public Engineer, public Youtuber{
    public:
    string name;

    CodeTeacher(string specilization, int subs, string name){
        this->name = name;
        this->specilization = specilization;
        this->subs = subs;
    }
};

int main() {
    
}
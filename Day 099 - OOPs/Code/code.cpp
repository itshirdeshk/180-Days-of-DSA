#include <iostream>
using namespace std;

class Student
{
public:
    string name;
    int age, roll_no;
    string grade;

    // Functions: Getter and Setter
public:
    // Setter Functions
    void setName(string n)
    {
        if (n.size() == 0)
        {
            cout << "Invalid Name" << endl;
            return;
        }
        name = n;
    }
    void setAge(int a)
    {
        age = a;
    }

    // Getter Functions
    void getName()
    {
        cout << name << endl;
    }
};

class a
{
    char c;
    char a;
    int b;
    double e;
};

int main()
{
    Student s1;
    s1.name = "Hirdesh";
    s1.age = 20;
    s1.roll_no = 28;
    s1.grade = "A+";

    Student s2;
    s2.setName("Rohit");
    s2.setAge(20);
    s2.getName();

    a ob1;
    cout << sizeof(ob1);

    Student *s = new Student;
    (*s).name = "Hirdesh";
    s->age = 20;

    cout << s->name << endl;
    cout << s->age << endl;
}
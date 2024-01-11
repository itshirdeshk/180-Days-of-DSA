#include <iostream>
#include<vector>
using namespace std;

class Area
{
public:
    // Function Overloading
    int calcArea(int r)
    {
        // Circle
        return 3.14 * r * r;
    }

    int calcArea(int l, int b)
    {
        // Rectangle
        return l * b;
    }
};

class Complex
{
    int real, img;

public:
    Complex(){};

    Complex(int real, int img)
    {
        this->real = real;
        this->img = img;
    }

    void display()
    {
        cout << real << " + i" << img << endl;
    }

    Complex operator+(Complex &C)
    {
        Complex ans;
        ans.real = real + C.real;
        ans.img = img + C.img;

        return ans;
    }
};

class Animal{
    public:
    // virtual void speak(){
    //     cout<<"HuHu\n";
    // }

    // Pure Virtual Function
    virtual void speak() = 0; // Abstract Class
};

class Dog : public Animal{
    public:
    void speak(){
        cout<<"Bark\n";
    }
};

class Cat : public Animal{
    public:
    void speak(){
        cout<<"Meow\n";
    }
};

int main()
{
    // Area A1;
    // cout<<A1.calcArea(3)<<endl;

    // Complex C1(2, 4);
    // Complex C2(4, 6);

    // Complex C3 = C1 + C2;
    // C3.display();

    // Animal *p;
    // p = new Dog();
    // p->speak();

    Animal *p;
    vector<Animal *> animals;
    animals.push_back(new Dog());
    animals.push_back(new Cat());
    animals.push_back(new Dog());
    animals.push_back(new Cat());

    for(int i = 0; i < animals.size(); i++){
        p = animals[i];
        p->speak();
    }
}
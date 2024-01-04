#include<iostream>
using namespace std;

// Q1. Create a Customer class and Use Const in it.
class Customer{
    string name;
    const string bank_name = "Bank of Baroda";

    public:

    Customer(string name){
        this->name = name;
    }

    // As we can see, we are getting an error because bank_name is a const variable.
    // We can't change the value of bank_name.
    // Const variable are used when we want that the value of any variable should not be changed.
    void change(string a){
        // bank_name = a;
    }
};

// Q2. What is the difference between Encapsulation and Abstraction?

// Encapsulation is defined as the wrapping up of data under a single unit. It is the mechanism that binds together code and the data it manipulates. Another way to think about encapsulation is, that it is a protective shield that prevents the data from being accessed by the code outside this shield. Technically in encapsulation, the variables or data of a class is hidden from any other class and can be accessed only through any member function of its own class in which they are declared. As in encapsulation, the data in a class is hidden from other classes, so it is also known as data-hiding. Encapsulation can be achieved by Declaring all the variables in the class as private and writing public methods in the class to set and get the values of variables. 

// Data Abstraction is the property by virtue of which only the essential details are displayed to the user. The trivial or the non-essential units are not displayed to the user. Ex: A car is viewed as a car rather than its individual components. Data Abstraction may also be defined as the process of identifying only the required characteristics of an object ignoring the irrelevant details. The properties and behaviors of an object differentiate it from other objects of similar type and also help in classifying/grouping the objects. 

int main () {}
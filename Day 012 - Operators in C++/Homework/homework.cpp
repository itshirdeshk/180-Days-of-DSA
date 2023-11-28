#include<iostream>
using namespace std;

int main(){
    // Q1: Temperature Range: Write a program that checks if a given temperature is suitable for swimming. If the temperature is between 70 and 90 (Excluded) degrees Fahrenheit print yes, else NO. 

    int temp;
    cout<<"Enter the temperature : ";
    cin>>temp;

    if(temp >= 70 && temp < 90){
        cout<<"Yes";
    }
    else
        cout<<"No";

    // Q2: Even and Positive Number: Write a program that prints “YES” if a given number is both even and positive, otherwise it will print “NO”.

    int num;
    cout<<"Enter the Number : ";
    cin>>num;

    if(num % 2 == 0 && num > 0) {
        cout<<"YES";
    }
    else {
        cout<<"NO";
    }

    // Q3: Age Check: Implement a program that checks if a person is a teenager. A teenager is someone whose age is between 13 and 19 (inclusive).
    int age;
    cout<<"Enter the Age : ";
    cin>>age;

    if(age >= 13 && age <= 19) 
        cout<<"You are a teenager";
    else
        cout<<"No you are not a teenager";

    // Q4. Take three numbers a,b,c from the user, print yes if a is either greater than b or c. Otherwise print NO.
    int a, b, c;
    cout<<"Enter three numbers : ";
    cin>>a, b ,c;

    if(a > b && a > c) {
        cout<<"Yes";
    }
    else {
        cout<<"No";
    }
} 
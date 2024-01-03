#include<iostream>
using namespace std;

// Q1. What is shallow copy and Deep Copy?

// Shallow Copy:

// A shallow copy of an object is a copy of the object where the member variables are copied directly from the source object to the destination object.
// If the object contains pointers, a shallow copy will copy the memory addresses of the pointed data, not the actual data. As a result, both the original object and the copied object will point to the same memory locations.
// Shallow copying can lead to issues because changes made to the data through one object will affect the other object as well.

// Deep Copy:

// A deep copy of an object involves creating a new object and copying the values of the member variables from the source object to the destination object.
// If the object contains pointers, a deep copy will allocate new memory for the pointed data and copy the content to the new memory location. As a result, changes made to the data through one object do not affect the other object.
// Deep copying ensures that each object has its own independent copy of the data.



// Q2. Why the Destructor of Objects is executed in reverse order?
// In C++, when objects are created within a block or function, their destructors are called when they go out of scope or when the program exits. The order in which destructors are executed is the reverse of the order in which the corresponding constructors were called. This behavior ensures that resources are released in the opposite order of their acquisition, following the principle of "last in, first out" (LIFO).

// The rationale behind this order is to provide a predictable and deterministic way of managing resources.

int main () {}
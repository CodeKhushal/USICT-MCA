#include <iostream>
using namespace std;

// Base class
class Animal
{
public:
    Animal()
    {
        cout << "Animal constructor called." << endl;
    }
    void eat()
    {
        cout << "Animal is eating." << endl;
    }
};

// Derived class from Animal
class Mammal : public Animal
{
public:
    Mammal()
    {
        cout << "Mammal constructor called." << endl;
    }
    void walk()
    {
        cout << "Mammal is walking." << endl;
    }
};

// Further derived class from Mammal
class Dog : public Mammal
{
public:
    Dog()
    {
        cout << "Dog constructor called." << endl;
    }
    void bark()
    {
        cout << "Dog is barking." << endl;
    }
};

int main()
{
    // Create an object of the derived class Dog
    Dog d;

    // Calling functions from different levels of inheritance
    d.eat();  // Inherited from Animal
    d.walk(); // Inherited from Mammal
    d.bark(); // Defined in Dog

    return 0;
}

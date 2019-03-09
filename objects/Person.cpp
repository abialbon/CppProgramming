#include <iostream>
#include "Person.h"

// Constructor functions have the same name as the class.
// The do not have a return type not should have any return statements
Person::Person(int a, std::string first, std::string last)
: age(a), firstname(first), lastname(last) // Member initilization list
{
	// Common to have the constructor empty
}

void Person::describe_person()
{
	std::cout << "My name is " << firstname + " " + lastname << std::endl;
	std::cout << "I am " << age << " years old." << std::endl;
}

// Destructor gets called when the object is removed from stack memory
Person::~Person() 
{
	std::cout << firstname << " has been deleted." << std::endl;
}
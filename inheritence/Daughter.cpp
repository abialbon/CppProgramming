#include <string>
#include <iostream>
#include "Mother.h"
#include "Daughter.h"

Daughter::Daughter(std::string firstname, std::string lastname, int age, std::string education)
: Mother(firstname, lastname, age), education(education)
// The first three arguments gets passed on the the Mother constructor function
{
    std::cout << "construction daughter " << std::endl;
}

void Daughter::describe(void)
{
    // Though Daughter does not have a getname() function
    // It is inherited from the mother through inheritence
    std::cout << "My name is " << getname() << std::endl;
    std::cout << "I have studied " << education << std::endl;
}

Daughter::~Daughter()
{
    std::cout << "destructing daugher " << std::endl;
}
#include "Mother.h"
#include <iostream>
#include <string>

Mother::Mother(string firstname, string lastname, int age)
: firstname(firstname), lastname(lastname), age(age)
// Member initializer list
{
    std::cout << "constructing mother " << std::endl;
}

std::string Mother::getname(void)
{
    return firstname + " " + lastname;
}

Mother::~Mother()
{
    std::cout << "destructing mother " << std::endl;
}
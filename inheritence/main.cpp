#include <iostream>
#include <string>

#include "Mother.h"
#include "Daughter.h"

int main()
{
    Mother m1("Reba", "Lone", 32);
    std::string name = m1.getname();
    std::cout << "Mother's name is " << name << std::endl;

    Daughter d1("Tilda", "Tone", 24, "Computer Science");
    d1.describe();

    {
        Daughter d2("Moni", "Madeline", 22, "Journalling");
        d2.describe();
    }

    return 0;
}
#pragma once
// This pre-processor directive makes sure this file gets included only once
// and avoids compiler errors
// Use them on on header files

#include <string>
using std::string;

class Mother
{
    private:
    int age;
    string firstname;
    string lastname;

    public:
    Mother(string firstname, string lastname, int age);
    std::string getname(void);
    ~Mother();

}; // Semicolon is importnat
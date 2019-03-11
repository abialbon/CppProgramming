/*
* This example demonstrates template classes
* and using template specialization
*/

#include <iostream>
#include <string>
#include "Person.h"

using std::string;
template <class T>
class Accum
{
    private:
    T total;

    public:
    Accum(T start) : total(start) {};
    T get_total() const { return total; };
    T operator += (T const& t)
    {
        return total += t;
    }
};

// Template specialization
// Tells how to use the template when a Person is passed
template <>
class Accum<Person>
{
    private:
    int total;

    public:
    Accum(int start) : total(start) {};
    int get_total() const { return total; };
    int operator += (Person const& t)
    {
        total = total + t.get_age();
        return total;
    }
};

int main() 
{
    Person p1(28);
    Person p2(26);

    Accum<int> i_accum(0);
    i_accum += 12;
    i_accum += 7;

    Accum<string> s_accum(string(""));
    s_accum += "hello";
    s_accum += " world";

    Accum<Person> p_accum(0);
    p_accum += p1;
    p_accum += p2;

    std::cout << "The accumulated total of i_accum: " << i_accum.get_total() << std::endl;
    std::cout << "The accumulated total of s_accum: " << s_accum.get_total() << std::endl;
    std::cout << "The accumulated total of p_accum: " << p_accum.get_total() << std::endl;
}
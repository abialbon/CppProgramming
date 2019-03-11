#pragma once

class Person
{
    private:
    int age;

    public:
    Person(int a) : age(a) {};
    int get_age() const { return age; };
};
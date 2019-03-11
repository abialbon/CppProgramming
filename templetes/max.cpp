#include <iostream>

class Person{
    private:
    int age;

    public:
    Person(int a) : age(a) {}
    int get_age() const { return age; }
    // The template uses this operator when the arguments are of type Person
    bool operator> (Person p)
    {
        return age > p.get_age() ? 1 : 0;
    }
};

template <class T>
T max(T t1, T t2)
{
    return t2 > t1 ? t2 : t1;
}

int main()
{
    // Instantiating two objects of instance Person
    Person p1(20);
    Person p2(21);

    std::cout << max(32, 22) << std::endl;
    std::cout << max(3.1, 22.32) << std::endl;
    std::cout << max(true, false) << std::endl;
    // The return from max is the same type of its arguments
    Person max_aged_person =  max(p1,p2);
    std::cout << max_aged_person.get_age() << std::endl;
}

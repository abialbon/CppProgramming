#include <iostream>
#include "Student.h"

int main() {
    Student s1("Peter", "Pen", "local", 6700, 2000, "p.pan@gmail.com");
    std::cout << s1.print_email();
    s1.pay_fee(4800);
    std::cout << s1.print_email();
    return 0;
}
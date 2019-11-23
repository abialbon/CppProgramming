#include "Student.h"
#include <string>

Student::Student(std::string first, std::string last, std::string type, int fee, int paid, std::string email) 
    : firstName(first), lastName(last), type(type), fee(fee), paid(paid), email(email)
    {}

std::string Student::getName()
{
    return firstName + " " + lastName;
}

int Student::find_balance()
{
    return fee - paid;
}

void Student::pay_fee(int amt)
{
    paid += amt;
}

std::string Student::print_email() {
    if ((fee - paid) <= 0) return "Nothing left to pay, Bye\n";
    std::string msg;
    msg += "To: " + email + ",\n";
    msg += "Dear " + getName() + "\n";
    msg += "Kindly pay us the " + std::to_string(find_balance()) + "\n";
    msg += "as soon as possible\n";
    return msg;
}
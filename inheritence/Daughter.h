#pragma once

#include <string>
#include "Mother.h"

class Daughter:public Mother {
    private:
    std::string education;

    public:
    Daughter(std::string firstname, std::string lastname, int age, std::string education);
    void describe(void);
    ~Daughter();
}; // This semicolon is important
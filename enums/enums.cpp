#include <iostream>

int main()
{
    enum class Status {
        Exit, // Use commas and not semicolons
        Pending,
        OK // Nothing to be at the end
    };

    Status s1 = Status::OK;   
    s1 = Status::Exit;
}
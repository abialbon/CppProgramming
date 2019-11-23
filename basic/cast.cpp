#include <iostream>

using namespace std;

int main()
{
    // Do not use round bracket casts
    // If you use a cast the compiler warning will go
    double d = 32.5563;
    int i = static_cast<int>(d);
    
    cout << d << endl;
    cout << i << endl;
    return 0;
}

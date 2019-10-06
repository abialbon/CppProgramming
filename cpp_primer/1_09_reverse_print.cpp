#include <iostream>
using namespace std;

int main()
{
    cout << "Enter the starting no: " << endl;
    int N = 0;
    cin >> N;
    cout << "Starting reverse print:" << endl;
    while (N >=0) 
    {
        cout << N << endl;
        --N;
    }
    return 0;
}
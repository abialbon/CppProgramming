#include<iostream>

using namespace std;

int main() {
    cout << "Enter the percision needed: " << ends;
    int n = 3;
    cin >> n;

    double sum = 1;
    double sign = -1;
    for(int i=1; i<n; i++) {
        sum += (sign/(2*i + 1));
        sign *= -1;
    }
    double pi = 4*sum;
    cout << pi <<endl;
}
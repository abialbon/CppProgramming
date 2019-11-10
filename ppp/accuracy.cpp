#include <iostream>
#include <math.h>
using namespace std;
int main() {
    int N = 2000000000;
    int no_digits = 1;
    int temp = N;
    while (temp >= 10) {
        temp /= 10;
        ++no_digits;
    }
    
    double sum[no_digits];
    if (no_digits > 1) {
        for(int i = 0; i < no_digits - 1; ++i) {
            for(long j = pow(10, i); j < pow(10, i + 1); ++j) {
                sum[i] += 1 / (double) (j * j);
            }
        }
    }
    cout << no_digits << endl;
    for (long j = pow(10, no_digits - 1); j <= N; ++j) {
        sum[no_digits - 1] += 1 / (double) (j * j);
    }
    double val = 0.0d;
    for (int i = 0; i < no_digits; ++i) {
        val += sum[i];
    }
    cout.precision(17);
    cout << "1.6449340663482264" << endl;
    cout << val << endl;
}
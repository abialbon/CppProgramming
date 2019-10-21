#include <iostream>
#include "Chrono.h"
#define N 10'000
#define N_THREADS 4

using namespace std;

int main() {
    int n = 0;
    Chrono c;
    for (int i = 0; i < N * N_THREADS; i++) {
        n++;
    }
    c.get_elapsed_time();
    cout << "The value of n : " << n << endl;
    cout << "The value of n must be :" << N_THREADS * N << endl;
    return 0;
}
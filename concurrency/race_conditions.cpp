#include <iostream>
#include <thread>
#include "Chrono.h"
#define N 1'000
#define N_THREADS 4

using namespace std;

void increment(int& n) {
    for (int i = 0; i < N; i++) {
        n++;
    }
}

int main() {
    int n = 0;
    Chrono c;
    thread ts[N_THREADS];
    for (int i = 0; i < N_THREADS; i++) {
        ts[i] = thread(increment, ref(n));
    }
    for (int i = 0; i < N_THREADS; i++) {
        ts[i].join();
    }
    c.get_elapsed_time();
    cout << "The value of n : " << n << endl;
    cout << "The value of n must be :" << N_THREADS * N << endl;
    return 0;
}
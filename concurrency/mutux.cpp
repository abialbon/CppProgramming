#include <iostream>
#include <thread>
#include "Chrono.h"
#include <mutex>
#define N 10'000
#define N_THREADS 4

using namespace std;

void increment(int& n, mutex& m) {
    for (int i = 0; i < N; i++) {
        m.lock();
        n++;
        m.unlock();
    }
}

int main() {
    mutex inc_mutex;
    int n = 0;
    Chrono c;
    thread ts[N_THREADS];
    for (int i = 0; i < N_THREADS; i++) {
        ts[i] = thread(increment, ref(n), ref(inc_mutex));
    }
    for (int i = 0; i < N_THREADS; i++) {
        ts[i].join();
    }
    c.get_elapsed_time();
    cout << "The value of n : " << n << endl;
    cout << "The value of n must be :" << N_THREADS * N << endl;
    return 0;
}
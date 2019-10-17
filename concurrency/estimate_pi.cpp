#include<iostream>
#include<thread>
#include<vector>
#include<math.h>
#include<chrono>

#define N_T 8
#define N 1'000'000


using namespace std;

void t_func(int i, int s, int e, vector<double> &t) {
    double sum = 0.0;
    double div = 0.0 + 2*s;
    for (int i = s; i < e; i = i+2) {
        sum = sum + 1/ (div + 1) - 1 / (div + 3);
        div += 4.0;
    }
    t[i] = sum;
}

void pi_estimate() {
    std::chrono::time_point<std::chrono::system_clock> start, end; 
    start = std::chrono::system_clock::now(); 
    vector<double> t_vals (N_T);
    vector<thread> t_arr (N_T);
    double pi;
    int no_per_thread = N/N_T;
    for (int i = 0; i < N_T; i++) {
        t_arr[i] = (thread(t_func, i, i*no_per_thread, i*no_per_thread + no_per_thread, ref(t_vals)));
    } 

    for (int i = 0; i < N_T; i++) {
        t_arr[i].join();
    }
    for (int i = 0; i < N_T; i++) {
        pi += t_vals[i];
    }
    end = std::chrono::system_clock::now(); 
    cout << "From main: " << pi*4 << endl;
    std::chrono::duration<double> elapsed_seconds = end - start; 
    
  
    std::cout << "elapsed time: " << elapsed_seconds.count() * 1000 << "s\n"; 
}

int main() {
    pi_estimate();
    return 0;
}
#include<iostream>
#include<thread>
#include<vector>
#include<math.h>

using namespace std;

void t_func(int s, long n, int count, vector<double> &t) {
    double sum = 0;
    for (long i = s; i < n; i = i+count) {
        sum += (double) pow(-1, i)/(2*i + 1);
    }
    t[s] = sum;
}

int main() {
    int thread_no = 8;
    vector<double> t_vals (thread_no);
    vector<thread> t_arr (thread_no);
    double pi;
    for (int i = 0; i < thread_no; i++) {
        t_arr[i] = (thread(t_func, i, 1000000000, thread_no, ref(t_vals)));
    } 

    for (int i = 0; i < thread_no; i++) {
        t_arr[i].join();
    }
    for (int i = 0; i < thread_no; i++) {
        pi += t_vals[i];
    }
    cout << "From main: " << 4*pi << endl;
    return 0;
}
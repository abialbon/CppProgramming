#include <iostream>
#include <immintrin.h>
#include "/home/abialbon/Documents/MyProjects/learning_cpp/concurrency/Chrono.h"

#define N 100'000
#define float8 __m256
#define set8(x) _mm256_set1_ps(x)
#define add8(a, b) _mm256_add_ps(a, b)
#define seti(a, b, c, d, e, f, g, h) _mm256_set_ps(a, b, c, d, e, f, g, h)
#define reci8(x) _mm256_rcp_ps(x)
#define store8(a, b) _mm256_store_ps(a, b)

using namespace std;

void estimate_pi_sequentially() {
    double val = 0.;
    double increment = 1.;
    for (int i = 0; i < N/2; ++i) {
        val += 1/increment;
        val -= 1/(increment + 2);
        increment += 4;
    }
    cout << "PI Estimation Sequentially: " << val * 4 << endl;
}

void estimate_pi_simple_simd() {
    float8 results = set8(0.0);
    float8 base = seti(1.0, -3.0, 5.0, -7.0, 9.0, -11.0, 13.0, -15.0);
    float8 increment = seti(16.0, -16.0, 16.0, -16.0, 16.0, -16.0, 16.0, -16.0);
    
    for(int i = 0; i < N/8; ++i) {
        if (i != 0) {

            base = add8(base, increment);
        }
        float8 terms = base;
        terms = reci8(terms);
        results = add8(terms, results);
    }

    float *vals = new float[8];
    float val = 0.;
    store8(vals, results);
    for (int j = 0; j < 8; j++) {
        val += vals[j];
    }
    cout << "Pi Estimation by Simple SIMD: " << val * 4 << endl;
    delete vals;
}

int main() {
    Chrono a;
    estimate_pi_sequentially();
    a.get_elapsed_time();
    Chrono b;
    estimate_pi_simple_simd();
    b.get_elapsed_time();
    return 0;
}
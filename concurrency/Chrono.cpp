#include <chrono>
#include <iostream>
#include "Chrono.h"

Chrono::Chrono() {
    start = std::chrono::high_resolution_clock::now();
}

void Chrono::get_elapsed_time() {
    std::chrono::time_point<std::chrono::high_resolution_clock> end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::micro> elapsed = end - start;
    std::cout << "Time for this operation (microsec) " << elapsed.count() << std::endl;
}
#include <chrono>

class Chrono {
    private:
        std::chrono::time_point<std::chrono::high_resolution_clock> start;
    public:
        Chrono();
        void get_elapsed_time();
};
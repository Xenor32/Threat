#include <iostream>
#include <thread>
#include <chrono>

void some_function(int id, int delay) {
    for (int i = 0; i < 5; i++) {
        std::cout << std::this_thread::get_id() << ' ' << "\tsome_func_" << id << "\t" << i << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(delay));
    }
}

int main() {
    std::thread th_0(some_func, 0, 300);
    std::thread th_1(some_func, 1, 300);

    th_0.join();
    th_1.join();

    std::thread th_2(some_func, 2, 200);

    th_2.join();

    return 0;
}

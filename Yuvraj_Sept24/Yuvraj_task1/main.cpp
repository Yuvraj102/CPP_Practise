#include <iostream>
#include "Time.h"

int main() {
    Time t1(12, 59, 58);  // testing minute rollover
    std::cout << "Testing increment into next minute:\n";
    for (int i = 0; i < 5; i++) {
        t1.printStandard();
        std::cout << std::endl;
        t1.tick();
    }

    std::cout << "\nTesting increment into next hour:\n";
    Time t2(1, 59, 58);
    for (int i = 0; i < 5; i++) {
        t2.printStandard();
        std::cout << std::endl;
        t2.tick();
    }

    std::cout << "\nTesting increment into next day:\n";
    Time t3(23, 59, 58);
    for (int i = 0; i < 5; i++) {
        t3.printStandard();
        std::cout << std::endl;
        t3.tick();
    }

    return 0;
}


//g++ -std=c++11 -o time_program Time.cpp main.cpp
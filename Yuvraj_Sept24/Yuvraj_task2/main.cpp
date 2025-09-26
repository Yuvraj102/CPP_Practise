#include <iostream>
#include "Date.h"

int main() {
    std::cout << "Test: Increment into next month\n";
    Date d1(1, 30, 2025); // Jan 30, 2025
    for (int i = 0; i < 5; i++) {
        d1.print();
        std::cout << std::endl;
        d1.nextDay();
    }

    std::cout << "\nTest: Increment into next year\n";
    Date d2(12, 30, 2025); // Dec 30, 2025
    for (int i = 0; i < 5; i++) {
        d2.print();
        std::cout << std::endl;
        d2.nextDay();
    }

    std::cout << "\nTest: Leap year (Feb 28 -> Feb 29 -> Mar 1)\n";
    Date d3(2, 27, 2024); // Leap year
    for (int i = 0; i < 4; i++) {
        d3.print();
        std::cout << std::endl;
        d3.nextDay();
    }

    return 0;
}

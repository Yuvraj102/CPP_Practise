/*
Combining Class Time and Class Date) Combine the modified Time class of Exercise 9.7 and the modified Date class of Exercise 9.8 into one class called DateAndTime. (In Chapter 12, we’ll discuss inheritance, which will enable us to accomplish this task quickly without modifying the ex- isting class definitions.) Modify the tick function to call the nextDay function if the time incre- ments into the next day. Modify functions printStandard and printUniversal to output the date and time. Write a program to test the new class DateAndTime. Specifically, test incrementing the time into the next day.

*/

#include <iostream>
#include "DateAndTime.h"

int main() {
    std::cout << "Test increment into next day:\n";
    DateAndTime dt(12, 31, 2025, 23, 59, 58); // Dec 31, 2025 11:59:58 PM

    for (int i = 0; i < 5; i++) {
        dt.printStandard();
        std::cout << "  |  ";
        dt.printUniversal();
        std::cout << std::endl;
        dt.tick();
    }

    return 0;
}

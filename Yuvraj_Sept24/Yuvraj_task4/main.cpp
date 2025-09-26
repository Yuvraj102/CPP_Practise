/*
(Returning Error Indicators from Class Time’s set Functions) Modify the set functions in the Time class of Figs. 9.8–9.9 to return appropriate error values if an attempt is made to set a data mem- ber of an object of class Time to an invalid value. Write a program that tests your new version of class Time. Display error messages when set functions return error values.
*/

#include <iostream>
#include "Time.h"

int main() {
    Time t1;

    std::cout << "Testing valid setTime:\n";
    if (!t1.setTime(13, 27, 45)) {
        std::cout << "Error setting time!\n";
    }
    t1.printStandard(); std::cout << "  |  "; t1.printUniversal(); std::cout << "\n";

    std::cout << "\nTesting invalid hour:\n";
    if (!t1.setHour(25)) {
        std::cout << "Error: invalid hour\n";
    }

    std::cout << "\nTesting invalid minute:\n";
    if (!t1.setMinute(61)) {
        std::cout << "Error: invalid minute\n";
    }

    std::cout << "\nTesting invalid second:\n";
    if (!t1.setSecond(-5)) {
        std::cout << "Error: invalid second\n";
    }

    std::cout << "\nCurrent time still valid: ";
    t1.printStandard(); std::cout << "  |  "; t1.printUniversal(); std::cout << "\n";

    return 0;
}

#include <iostream>
#include "Date.h"

// constructor
Date::Date(int m, int d, int y) {
    setDate(m, d, y);
}

void Date::setDate(int m, int d, int y) {
    // validate month
    if (m < 1 || m > 12) m = 1;

    // validate year (basic: allow >= 1)
    if (y < 1) y = 2000;

    // validate day
    int maxDay = daysInMonth(m, y);
    if (d < 1 || d > maxDay) d = 1;

    month = m;
    day = d;
    year = y;
}

bool Date::isLeapYear(int y) {
    return (y % 400 == 0) || (y % 4 == 0 && y % 100 != 0);
}

int Date::daysInMonth(int m, int y) {
    static const int daysPerMonth[12] = 
        {31,28,31,30,31,30,31,31,30,31,30,31};
    if (m == 2 && isLeapYear(y)) return 29;
    return daysPerMonth[m-1];
}

void Date::nextDay() {
    day++;
    if (day > daysInMonth(month, year)) {
        day = 1;
        month++;
        if (month > 12) {
            month = 1;
            year++;
        }
    }
}

void Date::print() {
    std::cout << month << '/' << day << '/' << year;
}

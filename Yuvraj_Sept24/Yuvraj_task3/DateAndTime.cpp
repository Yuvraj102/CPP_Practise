#include <iostream>
#include <iomanip>
#include "DateAndTime.h"

DateAndTime::DateAndTime(int m, int d, int y, int h, int min, int s) {
    setDate(m, d, y);
    setTime(h, min, s);
}

// date
void DateAndTime::setDate(int m, int d, int y) {
    if (m < 1 || m > 12) m = 1;
    if (y < 1) y = 2000;

    int maxDay = daysInMonth(m, y);
    if (d < 1 || d > maxDay) d = 1;

    month = m;
    day = d;
    year = y;
}

// time
void DateAndTime::setTime(int h, int m, int s) {
    hour = (h >= 0 && h < 24) ? h : 0;
    minute = (m >= 0 && m < 60) ? m : 0;
    second = (s >= 0 && s < 60) ? s : 0;
}

bool DateAndTime::isLeapYear(int y) {
    return (y % 400 == 0) || (y % 4 == 0 && y % 100 != 0);
}

int DateAndTime::daysInMonth(int m, int y) {
    static const int daysPerMonth[12] =
        {31,28,31,30,31,30,31,31,30,31,30,31};
    if (m == 2 && isLeapYear(y)) return 29;
    return daysPerMonth[m-1];
}

void DateAndTime::tick() {
    second++;
    if (second == 60) {
        second = 0;
        minute++;
        if (minute == 60) {
            minute = 0;
            hour++;
            if (hour == 24) {
                hour = 0;
                nextDay();
            }
        }
    }
}

void DateAndTime::nextDay() {
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

void DateAndTime::printUniversal() {
    std::cout << year << "/"
              << std::setw(2) << std::setfill('0') << month << "/"
              << std::setw(2) << day << " "
              << std::setw(2) << hour << ":"
              << std::setw(2) << minute << ":"
              << std::setw(2) << second;
}

void DateAndTime::printStandard() {
    std::cout << std::setw(2) << std::setfill('0') << month << "/"
              << std::setw(2) << day << "/"
              << year << " "
              << ((hour == 0 || hour == 12) ? 12 : hour % 12) << ":"
              << std::setw(2) << minute << ":"
              << std::setw(2) << second
              << (hour < 12 ? " AM" : " PM");
}

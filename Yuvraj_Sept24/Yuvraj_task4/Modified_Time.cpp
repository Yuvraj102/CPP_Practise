#include <iostream>
#include <iomanip>
#include "Time.h"

// constructor
Time::Time(int h, int m, int s) {
    if (!setTime(h, m, s)) {
        // if invalid input, default to 00:00:00
        hour = minute = second = 0;
    }
}

bool Time::setTime(int h, int m, int s) {
    bool okH = setHour(h);
    bool okM = setMinute(m);
    bool okS = setSecond(s);
    return okH && okM && okS;
}

bool Time::setHour(int h) {
    if (h >= 0 && h < 24) {
        hour = h;
        return true;
    }
    return false;
}

bool Time::setMinute(int m) {
    if (m >= 0 && m < 60) {
        minute = m;
        return true;
    }
    return false;
}

bool Time::setSecond(int s) {
    if (s >= 0 && s < 60) {
        second = s;
        return true;
    }
    return false;
}

int Time::getHour() { return hour; }
int Time::getMinute() { return minute; }
int Time::getSecond() { return second; }

void Time::printUniversal() {
    std::cout << std::setfill('0') << std::setw(2) << getHour() << ":"
              << std::setw(2) << getMinute() << ":"
              << std::setw(2) << getSecond();
}

void Time::printStandard() {
    std::cout << ((getHour() == 0 || getHour() == 12) ? 12 : getHour() % 12)
              << ":" << std::setfill('0') << std::setw(2) << getMinute()
              << ":" << std::setw(2) << getSecond()
              << (hour < 12 ? " AM" : " PM");
}

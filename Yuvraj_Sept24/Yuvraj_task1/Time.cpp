#include <iostream>
#include <iomanip>
#include "Time.h"

// constructor
Time::Time(int hr, int min, int sec) {
    setTime(hr, min, sec);
}

// set new time
void Time::setTime(int h, int m, int s) {
    setHour(h);
    setMinute(m);
    setSecond(s);
}

void Time::setHour(int h) {
    hour = (h >= 0 && h < 24) ? h : 0;
}

void Time::setMinute(int m) {
    minute = (m >= 0 && m < 60) ? m : 0;
}

void Time::setSecond(int s) {
    second = (s >= 0 && s < 60) ? s : 0;
}

int Time::getHour() { return hour; }
int Time::getMinute() { return minute; }
int Time::getSecond() { return second; }

// tick: increment by 1 second
void Time::tick() {
    second++;
    if (second == 60) {
        second = 0;
        minute++;
        if (minute == 60) {
            minute = 0;
            hour++;
            if (hour == 24) {
                hour = 0; // new day
            }
        }
    }
}

void Time::printUniversal() {
    std::cout << std::setfill('0') << std::setw(2) << getHour() << ":"
              << std::setw(2) << getMinute() << ":" << std::setw(2) << getSecond();
}

void Time::printStandard() {
    std::cout << ((getHour() == 0 || getHour() == 12) ? 12 : getHour() % 12)
              << ":" << std::setfill('0') << std::setw(2) << getMinute()
              << ":" << std::setw(2) << getSecond()
              << (hour < 12 ? " AM" : " PM");
}

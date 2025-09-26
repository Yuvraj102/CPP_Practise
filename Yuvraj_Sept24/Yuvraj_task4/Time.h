#ifndef TIME_H
#define TIME_H

class Time {
public:
    Time(int = 0, int = 0, int = 0); // default constructor

    // set functions (return true if valid, false if invalid)
    bool setTime(int, int, int);
    bool setHour(int);
    bool setMinute(int);
    bool setSecond(int);

    // get functions
    int getHour();
    int getMinute();
    int getSecond();

    void printUniversal(); // HH:MM:SS
    void printStandard();  // HH:MM:SS AM/PM

private:
    int hour;   // 0 - 23
    int minute; // 0 - 59
    int second; // 0 - 59
};

#endif

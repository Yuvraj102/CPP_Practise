/*
(Enhancing Class Time) Modify the Time class of Figs. 9.8–9.9 to include a tick member function that increments the time stored in a Time object by one second. The Time object should always remain in a consistent state. Write a program that tests the tick member function in a loop that prints the time in standard format during each iteration of the loop to illustrate that the tick member function works correctly. Be sure to test the following cases:
a) Incrementing into the next minute.
b) Incrementingintothenexthour.
c) Incrementing into the next day (i.e., 11:59:59 PM to 12:00:00 AM).

*/

#ifndef TIME_H
#define TIME_H

// Time abstract data type definition
class Time {
public:
    Time(int = 0, int = 0, int = 0); // default constructor

    // set functions
    void setTime(int, int, int);
    void setHour(int);
    void setMinute(int);
    void setSecond(int);

    // get functions
    int getHour();
    int getMinute();
    int getSecond();

    void printUniversal(); // HH:MM:SS
    void printStandard();  // HH:MM:SS AM/PM

    void tick(); // NEW: increment time by one second

private:
    int hour;   // 0 - 23
    int minute; // 0 - 59
    int second; // 0 - 59
};

#endif

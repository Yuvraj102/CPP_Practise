#ifndef DATEANDTIME_H
#define DATEANDTIME_H

class DateAndTime {
public:
    DateAndTime(int m = 1, int d = 1, int y = 2000,
                int h = 0, int min = 0, int s = 0);

    // setters
    void setDate(int, int, int);
    void setTime(int, int, int);

    // tick / nextDay
    void tick();     // increment by 1 second
    void nextDay();  // increment by 1 day

    // printing
    void printUniversal(); // yyyy/mm/dd HH:MM:SS
    void printStandard();  // mm/dd/yyyy HH:MM:SS AM/PM

private:
    int month, day, year;
    int hour, minute, second;

    bool isLeapYear(int y);
    int daysInMonth(int m, int y);
};

#endif

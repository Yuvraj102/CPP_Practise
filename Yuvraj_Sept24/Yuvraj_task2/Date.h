// Fig. 9.17 modified: Date.h
#ifndef DATE_H
#define DATE_H

class Date {
public:
    Date(int = 1, int = 1, int = 2000); // default constructor

    void setDate(int, int, int); // set date with validation
    void print();                // print mm/dd/yyyy
    void nextDay();              // increment by one day

private:
    int month;
    int day;
    int year;

    bool isLeapYear(int y);  // check leap year
    int daysInMonth(int m, int y); // days in given month/year
};

#endif

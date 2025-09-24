/*
(Date Class) Create a class called Date that includes three pieces of information as data members—a month (type int), a day (type int) and a year (type int). Your class should have a con- structor with three parameters that uses the parameters to initialize the three data members. For the purpose of this exercise, assume that the values provided for the year and day are correct, but ensure that the month value is in the range 1–12; if it isn’t, set the month to 1. Provide a set and a get func- tion for each data member. Provide a member function displayDate that displays the month, day and year separated by forward slashes (/). Write a test program that demonstrates class Date’s capa- bilities.
*/

#include <iostream>
using namespace std;

class Date {
private:
    int month;
    int day;
    int year;

public:
    // constructor with validation
    Date(int m, int d, int y) {
        if (m >= 1 && m <= 12) {
            month = m;
        } else {
            month = 1;  // default if invalid
        }
        day = d;
        year = y;
    }

    // setters
    void setMonth(int m) {
        if (m >= 1 && m <= 12) {
            month = m;
        } else {
            month = 1;
        }
    }

    void setDay(int d) { day = d; }
    void setYear(int y) { year = y; }

    // getters
    int getMonth() const { return month; }
    int getDay() const { return day; }
    int getYear() const { return year; }

    // display date
    void displayDate() const {
        cout << month << "/" << day << "/" << year << endl;
    }
};

int main() {
    // create Date object with valid month
    Date date1(5, 15, 2024);
    cout << "Date 1: ";
    date1.displayDate();

    // create Date object with invalid month
    Date date2(14, 20, 2025); // month invalid, should default to 1
    cout << "Date 2: ";
    date2.displayDate();

    // update values
    date2.setMonth(10);
    date2.setDay(1);
    date2.setYear(2030);

    cout << "Updated Date 2: ";
    date2.displayDate();

    return 0;
}

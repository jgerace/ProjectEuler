#include <iostream>

/*
You are given the following information, but you may prefer to do some research for yourself.

    1 Jan 1900 was a Monday.
    Thirty days has September,
    April, June and November.
    All the rest have thirty-one,
    Saving February alone,
    Which has twenty-eight, rain or shine.
    And on leap years, twenty-nine.
    A leap year occurs on any year evenly divisible by 4, but not on a century unless it is divisible by 400.

How many Sundays fell on the first of the month during the twentieth century (1 Jan 1901 to 31 Dec 2000)?
*/

using namespace std;

int getDaysInMonth(int month, int year);

int p19_main(int argc, char **argv)
{
    int count = 0;
    int day = 2; // jan 1, 1901 is a tuesday
    for(int ii = 1901; ii < 2001; ii++) {
        for(int jj = 0; jj < 12; jj++) {
            day += getDaysInMonth(jj, ii) % 7;
            day = day%7;
            if(day == 0) {
                count++;
            }
        }
    }

    cout << count << endl;

    return 0;
}

int getDaysInMonth(int month, int year)
{
    int daysInMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if(month == 1) {
        if(year%400 == 0 || (year%4 == 0 && year%100 != 0)) {
            return 29;
        }
    }
    return daysInMonth[month];
}

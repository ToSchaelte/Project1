#include <iostream>
#include "utils.h"

using namespace std;

bool isLeapYear(int year)
{
    return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
}

int getDayCountOfMonth(int month, int year)
{
    if (month == 2) return isLeapYear(year) ? 29 : 28;
    else if (month <= 7) return month % 2 == 0 ? 30 : 31;
    else if (month <= 12) return month % 2 == 0 ? 31 : 30;
}

bool isYearValid(int day, int month, int year)
{
    if (month > 12 || month < 1) return false;
    if (day < 0) return false;
    if (month == 2) return isLeapYear(year) ? day <= 29 : day <= 28;
    else if (month <= 7) return month % 2 == 0 ? day <= 30 : day <= 31;
    else if (month <= 12) return month % 2 == 0 ? day <= 31 : day <= 30;

    return true;
}
#include<iomanip>
#include<sstream>
#include<vector>
#include<string>

#include"CommonUtils.h"

using namespace std;

string vectorToString(vector<int> values, int width)
{
    stringstream sstream;
    for (int i = 0; i < values.size(); ++i)
        sstream << setw(width) << values[i] << " ";
    return sstream.str();
}

bool isLeapYear(int year)
{
	return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
}

int getDayCountOfMonth(int month, int year)
{
	if (month == 2) return isLeapYear(year) ? 29 : 28;
	else if (month <= 7) return month % 2 == 0 ? 30 : 31;
	else if (month <= 12) return month % 2 == 0 ? 31 : 30;
	return NULL;
}

bool isDateValid(int day, int month, int year)
{
	if (month > 12 || month < 1) return false;
	if (day < 0) return false;
	if (month == 2) return isLeapYear(year) ? day <= 29 : day <= 28;
	else if (month <= 7) return month % 2 == 0 ? day <= 30 : day <= 31;
	else if (month <= 12) return month % 2 == 0 ? day <= 31 : day <= 30;
	return false;
}

string getDayAsString(int dayIndex)
{
	string days[7] = { "Monday",	"Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday" };
	return days[dayIndex];
}
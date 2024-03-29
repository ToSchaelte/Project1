#include <iostream>
#include "DatumWochentag.h"
#include "utils.h"

using namespace std;

int main()
{
	int day = 0;
	int month = 0;
	int year = 0;

	for (int i = 0; i < 100; ++i)
	{
		cout << "insert a date (dd mm yyyy): ";
		cin >> day >> month >> year;

		if (day == 0 && month == 0 && year == 0) break;

		if (year < YEAR_OF_MONDAY)
		{
			cout << "Year is too low to calculate" << endl;
			continue;
		}

		if (!isDateValid(day, month, year))
		{
			cout << "Date is not valid" << endl;
			continue;
		}

		cout << "That is a " + getDay(day, month, year) << endl;
	}

	return 1;
}

string getDay(int day, int month, int year)
{
	int dayDifference = 0;
	for (int i = YEAR_OF_MONDAY; i < year; ++i)
		if (isLeapYear(i)) dayDifference += 366;
		else dayDifference += 365;

	for (int i = MONTH_OF_MONDAY; i < month; ++i)
		dayDifference += getDayCountOfMonth(i, year);

	dayDifference += day - DAY_OF_MONDAY;

	return getDayAsString(dayDifference % 7);
}
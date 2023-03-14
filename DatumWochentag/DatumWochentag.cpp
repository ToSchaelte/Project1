#include <iostream>

#include "DatumWochentag.h"
#include "utils.h"

using namespace std;

int main()
{
	while (true)
	{
		int day = 0;
		int month = 0;
		int year = 0;

		cout << "insert a date (dd mm yyyy): ";
		cin >> day >> month >> year;

		if (day == 0 && month == 0 && year == 0) break;

		if (!isYearValid(day, month, year))
		{
			cout << "Year is not valid" << endl;
			continue;
		}

		cout << "That is a " + getDay(day, month, year) << endl;
	}

	return 1;
}

string getDay(int day, int month, int year)
{
	int dayOfMonday = 1;
	int monthOfMonday = 1;
	int yearOfMonday = 1900;

	int dayDifference = 0;
	for (int i = yearOfMonday; i < year; ++i)
		if (isLeapYear(i)) dayDifference += 366;
		else dayDifference += 365;

	for (int i = monthOfMonday; i < month; ++i)
		dayDifference += getDayCountOfMonth(i, year);

	dayDifference += day - dayOfMonday;

	return getDayOfWeek(dayDifference % 7);
}

string getDayOfWeek(int dayIndex)
{
	switch (dayIndex)
	{
	case 0:
		return "Monday";
		break;
	case 1:
		return "Tuesday";
		break;
	case 2:
		return "Wednesday";
		break;
	case 3:
		return "Thursday";
		break;
	case 4:
		return "Friday";
		break;
	case 5:
		return "Saturday";
		break;
	case 6:
		return "Sunday";
		break;
	default:
		break;
	}
}
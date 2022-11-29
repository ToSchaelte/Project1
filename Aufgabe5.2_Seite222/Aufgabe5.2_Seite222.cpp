#include <iostream>
using namespace std;

bool istSchaltjahr(int year)
{
    return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
}

int main()
{
    int day = -1;
    int month = -1;
    int year = -1;

    cout << "please insert a date in this format: dd mm yyyy" << endl;
    cin >> day;
    cin >> month;
    cin >> year;

    if ((month == 2 && ((
            (istSchaltjahr(year) && day <= 29)
            || day <= 28)
            && day >= 1
            )
        )
        || ((day >= 1 && ((month >= 1 && month <= 7)
            && ((month % 2 == 0 && day <= 30)
                || (month % 2 != 0 && day <= 31)))
            || ((month >= 8 && month <= 12)
                && ((month % 2 != 0 && day <= 30)
                    || (month % 2 == 0 && day <= 31))
            )) && month != 2))
    {
        cout << "real date" << endl;
    }
    else
    {
        cout << "no real date" << endl;
    }
}
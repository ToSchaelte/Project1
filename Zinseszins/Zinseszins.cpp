#include <iostream>

using namespace std;

int main()
{
    double kapital = -1;
    double zinssatz = -1;
    double laufzeit = - 1;

    cout << "Bitte geben Sie ihr Kapital(EURO), Ihren Zinssatz(PROZENT) und die Laufzeit(JAHRE) ein: ";

    cin >> kapital >> zinssatz >> laufzeit;

    double zinssatzAsDecimal = zinssatz / 100;

    for (int year = 1; year <= laufzeit; ++year)
    {
        kapital += kapital * zinssatzAsDecimal;
    }

    cout << "Ihr kapital am Ende der Laufzeit beträgt: " << kapital << endl;

    return NULL;
}
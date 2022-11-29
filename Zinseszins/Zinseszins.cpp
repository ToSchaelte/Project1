#include <iostream>

using namespace std;

int main()
{
    double kapital = -1;
    double zinssatz = -1;
    double laufzeit = - 1;

    cout << "Bitte geben Sie ihr Kapital(EURO), Ihren Zinssatz(PROZENT) und die Laufzeit(JAHRE) ein: ";

    cin >> kapital >> zinssatz >> laufzeit;

    for (int i = 0; i < laufzeit; ++i)
    {
        kapital += kapital * zinssatz / 100;
    }

    cout << "Ihr kapital am Ende der Laufzeit beträgt: " << kapital << endl;

    return NULL;
}
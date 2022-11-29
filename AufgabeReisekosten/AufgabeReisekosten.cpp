#include <iostream>
#include <iomanip>
#include <map>

using namespace std;

map<string, float> kilometersaetze = {
    {"pkw", 0.27},
    {"motorrad", 0.12},
    {"moped",0.07},
    {"fahrrad", 0.04}
};

string toLowerCase(string s)
{
    for (int i = 0; i < s.size(); i++)
    {
        s[i] = tolower(s[i]);
    }
    return s;
}

void runBeautiful()
{
    float monatlichesKilometergeld = -1;
    int personalnummer = -1;
    char nachname[25];
    char fahrzeug[25];

    float gefahreneKilometer = -1;

    cout << "Personalnummer: ";
    cin >> personalnummer;

    cout << "Nachname: ";
    cin >> nachname;

    cout << "Fahrzeug: ";
    cin >> fahrzeug;

    cout << "Kilometer: ";
    cin >> gefahreneKilometer;

    monatlichesKilometergeld = gefahreneKilometer * kilometersaetze[toLowerCase(fahrzeug)];

    cout << " Personalnummer|       Nachname|       Fahrzeug| monatl. Kilometergeld" << endl
        << setw(15) << personalnummer << "|" << setw(15) << nachname << "|" << setw(15) << fahrzeug << "|" << setw(17) << monatlichesKilometergeld << " EURO" << endl;
}


void runNotBeautiful()
{
    float monatlichesKilometergeld = -1;
    int personalnummer = -1;
    char nachname[25];
    int fahrzeug;

    float gefahreneKilometer = -1;

    cout << "Personalnummer: ";
    cin >> personalnummer;

    cout << "Nachname: ";
    cin >> nachname;

    cout << "Fahrzeugschluessel (PKW = 1, Motorrad = 2, Moped = 3, Fahrrad = 4): ";
    cin >> fahrzeug;

    cout << "Kilometer: ";
    cin >> gefahreneKilometer;

    switch (fahrzeug)
    {
    case 1:
        monatlichesKilometergeld = gefahreneKilometer * 0.27;
        break;
    case 2:
        monatlichesKilometergeld = gefahreneKilometer * 0.12;
        break;
    case 3:
        monatlichesKilometergeld = gefahreneKilometer * 0.07;
        break;
    case 4:
        monatlichesKilometergeld = gefahreneKilometer * 0.04;
        break;
    }

    cout << " Personalnummer|       Nachname|       Fahrzeug| monatl. Kilometergeld" << endl
        << setw(15) << personalnummer << "|" << setw(15) << nachname << "|" << setw(15) << fahrzeug << "|" << setw(17) << monatlichesKilometergeld << " EURO" << endl;
}


int main()
{
    cout << "beautiful solution:" << endl;
    runBeautiful();
    cout << "not beautiful solution:" << endl;
    runNotBeautiful();
}
#include <iostream>
#include <iomanip>
#include "FRACHT.h"
using namespace std;

int main()
{
    map<key, double> angaben;
    const int produkteProKarton = 12;
    const double preisProkarton = 7.85;
    const double frachtPro100Km = 0.06;

    while (true)
    {
        cout << "Programm: Frachtberechnung" << endl
            << "==========================" << endl << endl << endl;

        print("Anzahl Kartons", "", false);
        cin >> angaben[ANZAHL_KARTONS];
        if (angaben[ANZAHL_KARTONS] <= 0) break;
        print("Anzahl Kilometer", "", false);
        cin >> angaben[ANZAHL_KILOMETER];

        angaben[GEWICHT] = angaben[ANZAHL_KARTONS] * 24;
        angaben[BERECHNETES_GEWICHT] = calculateBerechnetesGewicht(angaben[GEWICHT]);
        angaben[FRACHTKOSTEN] = angaben[ANZAHL_KILOMETER] * (angaben[BERECHNETES_GEWICHT]/100) * frachtPro100Km;
        angaben[NETTOUMSATZ] = angaben[ANZAHL_KARTONS] * produkteProKarton * preisProkarton;
        angaben[GESAMTUMSATZ] = angaben[FRACHTKOSTEN] + angaben[NETTOUMSATZ];
        angaben[RABATT] = calculateRabatt(angaben[NETTOUMSATZ]);
        angaben[ZIELPREIS] = angaben[GESAMTUMSATZ] - angaben[RABATT];

        printAll(angaben);
    }
}

int calculateBerechnetesGewicht(int gewicht)
{
    if ((int)gewicht % 100 != 0) gewicht += 100 - ((int)gewicht % 100);
    return gewicht;
}

double calculateRabatt(double nettoumsatz)
{
    if (nettoumsatz <= 10000) return nettoumsatz * 0.03;
    else if (nettoumsatz <= 50000) return nettoumsatz * 0.05;
    else return nettoumsatz * 0.07;
}

void print(string key, string value, bool endline)
{
    cout << setw(20) << key << " : " << setw(15) << value;
    if (endline) cout << endl;
}

void printAll(map<key, double>& angaben)
{
    cout << endl;
    print("Anzahl Kartons", to_string(angaben[ANZAHL_KARTONS]));
    print("Anzahl Kilometer", to_string(angaben[ANZAHL_KILOMETER]));
    print("Gewicht", to_string(angaben[GEWICHT]));
    print("Berechnetes Gewicht", to_string(angaben[BERECHNETES_GEWICHT]));
    cout << endl;
    print("Fracht", to_string(angaben[FRACHTKOSTEN]));
    print("Nettoumsatz", to_string(angaben[NETTOUMSATZ]));
    print("Gesamtumsatz", to_string(angaben[GESAMTUMSATZ]));
    print("Rabatt", to_string(angaben[RABATT]));
    print("Zielpreis", to_string(angaben[ZIELPREIS]));
    cout << endl << endl;
}
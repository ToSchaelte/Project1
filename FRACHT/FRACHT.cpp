#include <iostream>
#include <iomanip>
#include "FRACHT.h"
using namespace std;

int main()
{
    map<string, double> angaben;
    const int produkteProKarton = 12;
    const double preisProkarton = 7.85;
    const double frachtPro100Km = 0.06;

    while (true)
    {
        cout << "Programm: Frachtberechnung" << endl
            << "==========================" << endl << endl << endl;

        cout << "Kartons: ";
        cin >> angaben["kartons"];
        if (angaben["kartons"] <= 0) break;
        cout << "Kilometer: ";
        cin >> angaben["kilometer"];

        angaben["gewicht"] = angaben["kartons"] * 24;
        angaben["berechnetesGewicht"] = calculateBerechnetesGewicht(angaben["gewicht"]);
        angaben["fracht"] = angaben["kilometer"] * (angaben["berechnetesGewicht"]/100) * frachtPro100Km;
        angaben["nettoumsatz"] = angaben["kartons"] * produkteProKarton * preisProkarton;
        angaben["gesamtumsatz"] = angaben["fracht"] + angaben["nettoumsatz"];
        angaben["rabatt"] = calculateRabatt(angaben["nettoumsatz"]);
        angaben["zielpreis"] = angaben["gesamtumsatz"] - angaben["rabatt"];

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

void print(string key, double value)
{
    cout << setw(20) << key << " : " << setw(15) << value << endl;
}

void printAll(map<string, double>& angaben)
{
    cout << endl;
    print("Anzahl Kartons", angaben["kartons"]);
    print("Anzahl Kilometer", angaben["kilometer"]);
    print("Gewicht", angaben["gewicht"]);
    print("Berechnetes Gewicht", angaben["berechnetesGewicht"]);
    cout << endl;
    print("Fracht", angaben["fracht"]);
    print("Nettoumsatz", angaben["nettoumsatz"]);
    print("gesamtumsatz", angaben["gesamtumsatz"]);
    print("Rabatt", angaben["rabatt"]);
    print("Zielpreis", angaben["zielpreis"]);
    cout << endl << endl;
}
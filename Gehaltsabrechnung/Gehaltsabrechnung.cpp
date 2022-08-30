#include <iostream>
#include <iomanip>
using namespace std;

const int length = 50;
const char filler = ' ';
const int doublePrecision = 2;
const int maxDoubleLength = 10;
const  string unit = " EUR";


void printLabelValuePair(string leftString, double rightDouble)
{
    cout << setw(length) << setfill(filler) << left << leftString << setw(maxDoubleLength)
        << setfill(filler) << right << setprecision(doublePrecision) << fixed << rightDouble << unit << endl;
}

void printPrompt(string text)
{
    cout << setw(length) << setfill(filler) << left << text;
}

double readValue(string text)
{
    double input = 0;
    do
    {
        if (cin.fail())
        {
            cin.clear();
            cin.ignore();
        }
        printPrompt(text);
        cin >> input;
    } while (cin.fail());
    return input;
}

int main(){

    double bruttogehalt_monatl                  = readValue("Monatliches Bruttogehalt:");
    double abgabesatz_kv                        = readValue("Abgabesatz der Krankenversicherung (%):");
    double abgabesatz_pv                        = readValue("Abgabesatz der Pflegeversicherung (%):");
    double abgabesatz_rv                        = readValue("Abgabesatz der Rentenversicherung (%):");
    double abgabesatz_av                        = readValue("Abgabesatz der Arbeitslosenversicherung (%):");

    double lohnsteuer                           = bruttogehalt_monatl * 0.25;
    double kirchensteuer                        = bruttogehalt_monatl * 0.09;
    double steuerrechtlicheAbzuege              = lohnsteuer + kirchensteuer;

    double krankenversicherung                  = bruttogehalt_monatl * abgabesatz_kv / 100 / 2;
    double pflegeversicherung                   = bruttogehalt_monatl * abgabesatz_pv / 100 / 2;
    double rentenversicherung                   = bruttogehalt_monatl * abgabesatz_rv / 100 / 2;
    double arbeitslosenversicherung             = bruttogehalt_monatl * abgabesatz_av / 100 / 2;
    double sozialversicherungsrechtlicheAbzuege = krankenversicherung + pflegeversicherung + rentenversicherung + arbeitslosenversicherung;

    double nettogehalt_monatl                   = bruttogehalt_monatl - steuerrechtlicheAbzuege - sozialversicherungsrechtlicheAbzuege;


    cout << endl << "Entsprechend den oben gemachten Eingaben ergibt sich die Gehaltsabrechnung wie folgt:" << endl << endl;

    printLabelValuePair("Gesamtgehalt Brutto:", bruttogehalt_monatl);

    cout << endl << "Steuerrechtliche Abzuege:" << endl;
    printLabelValuePair("Lohnsteuer:", lohnsteuer);
    printLabelValuePair("Kirchensteuer:", kirchensteuer);
    printLabelValuePair("Steuerrechtliche Abzuege (gesamt):", steuerrechtlicheAbzuege);

    cout << endl << "Sozialversicherungsrechtliche Abzuege:" << endl;
    printLabelValuePair("Krankenversicherung:", krankenversicherung);
    printLabelValuePair("Pflegeversicherung:", pflegeversicherung);
    printLabelValuePair("Rentenversicherung:", rentenversicherung);
    printLabelValuePair("Arbeitslosenversicherung:", arbeitslosenversicherung);
    printLabelValuePair("Sozialversicherungsrechtliche Abzuege (gesamt):", sozialversicherungsrechtlicheAbzuege);

    printLabelValuePair("Netto Verdienst:", nettogehalt_monatl);
}
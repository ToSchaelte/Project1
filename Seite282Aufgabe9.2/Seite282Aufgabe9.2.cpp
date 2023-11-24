#include <iostream>
#include <iomanip>

using namespace std;

const enum Faecher
{
    Mathematik = 0,
    Deutsch,
    Englisch,
    Count
};

struct TSchueler
{
    char Name[20 + 1];
    char Klasse[5 + 1];
    int Noten[3];
};

double CalcAverage(int *numbers, int length)
{
    auto ret = 0.0;
    for (auto i = 0; i < length; ++i)
        ret += numbers[i];
    return ret/length;
}

int main()
{
    const int schuelerCount = 3;
    TSchueler schueler[schuelerCount];
    for (auto i = 0; i < schuelerCount; ++i)
    {
        schueler[i] = TSchueler();
        cout << "Name: ";
        cin >> schueler[i].Name;
        cout << "Klasse: ";
        cin >> schueler[i].Klasse;
        cout << "Note Mathematik: ";
        cin >> schueler[i].Noten[Faecher::Mathematik];
        cout << "Note Deutsch: ";
        cin >> schueler[i].Noten[Faecher::Deutsch];
        cout << "Note Englisch: ";
        cin >> schueler[i].Noten[Faecher::Englisch];
        cout << endl;
    }

    cout << setw(20) << "Name:" << setw(10) << "Klasse:" << setw(4) << "M" << setw(4) << "D" << setw(4) << "E" << setw(10) << "Schnitt" << endl;
    for (auto i = 0; i < schuelerCount; ++i)
        cout << setw(20) << schueler[i].Name << setw(10) << schueler[i].Klasse << setw(4) << schueler[i].Noten[Faecher::Mathematik] << setw(4) << schueler[i].Noten[Faecher::Deutsch] << setw(4) << schueler[i].Noten[Faecher::Englisch] << setw(10) << CalcAverage(schueler[i].Noten, Faecher::Count) << endl;
}
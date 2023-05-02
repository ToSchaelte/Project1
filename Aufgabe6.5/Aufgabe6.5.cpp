#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

const unsigned geldscheine[] = {
	500, 200, 100, 50, 20, 10, 5
};
const int MAX_BETRAG = 10000;

void printGeldscheine(unsigned anzahlGeldscheine[7])
{
	for (int i = 0; i < 7; ++i) 
		cout << "Anzahl der " << setw(3) << geldscheine[i] << " Euro-Scheine :" << setw(5) << anzahlGeldscheine[i] << endl;
	cout << endl;
}

void getAnzahlGeldscheine(unsigned gewolltesGeld, unsigned geldscheinIndex, unsigned anzahlGeldscheine[7])
{
	if (geldscheinIndex >= 7) return;
	if (gewolltesGeld < geldscheine[geldscheinIndex])
		return getAnzahlGeldscheine(gewolltesGeld, geldscheinIndex+1, anzahlGeldscheine);
	++anzahlGeldscheine[geldscheinIndex];
	return getAnzahlGeldscheine(gewolltesGeld - geldscheine[geldscheinIndex], geldscheinIndex, anzahlGeldscheine);
}

void getAnzahlGeldscheine(unsigned gewolltesGeld, unsigned anzahlGeldscheine[7])
{
	return getAnzahlGeldscheine(gewolltesGeld, 0, anzahlGeldscheine);
}

int main()
{
	while (true)
	{
		long long gewolltesGeld = 0;
		cout << "Wie viel Geld moechten Sie abheben? ";
		cin >> gewolltesGeld;
		if (gewolltesGeld > MAX_BETRAG)
		{
			cout << "sorry, hab nicht so viel Geld" << endl << endl;
			continue;
		}
		if (gewolltesGeld <= 0)
		{
			cout << "*exit program*" << endl;
			break;
		}
		if (gewolltesGeld % 5 != 0)
		{
			cout << "sorry, hab kein Muenzgeld" << endl << endl;
			continue;
		}

		unsigned anzahlGeldscheine[7] = { 0,0,0,0,0,0,0 };
		getAnzahlGeldscheine(gewolltesGeld, anzahlGeldscheine);
		printGeldscheine(anzahlGeldscheine);
	}
}
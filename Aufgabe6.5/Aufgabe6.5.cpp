#include <iostream>
using namespace std;

const unsigned geldscheine[] = {
	500, 200, 100, 50, 20, 10, 5
};
const int MAX_BETRAG = 10000;

void printGeldscheine(unsigned gewolltesGeld, unsigned geldscheinIndex)
{
	if (geldscheinIndex >= sizeof(geldscheine)/sizeof(unsigned)) return;
	if (gewolltesGeld >= geldscheine[geldscheinIndex])
	{
		gewolltesGeld -= geldscheine[geldscheinIndex];
		cout << geldscheine[geldscheinIndex] << endl;
	}
	printGeldscheine(gewolltesGeld, geldscheinIndex + (gewolltesGeld < geldscheine[geldscheinIndex]));
}

int main()
{
	while (true)
	{
		long gewolltesGeld = 0;
		cout << "Wie viel Geld willst du? ";
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

		printGeldscheine(gewolltesGeld, 0);
	}
}
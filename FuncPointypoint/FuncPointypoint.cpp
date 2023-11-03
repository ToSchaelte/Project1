#include <iostream>
#include <iomanip>

using namespace std;

void hexadezimal(int zahl)
{
	cout << hex << zahl;
}

void dezimal(int zahl)
{
	cout << dec << zahl;
}

void oktal(int zahl)
{
	cout << oct << zahl;
}

int main()
{
	int eingabe, zahl;
	void (*pfunk[3]) (int) = { hexadezimal,dezimal,oktal };
	cout << "Bitte die Zahl eingeben: ";
	cin >> zahl;
	do
	{
		cout << endl << "Welche umwandlung? (0:end, 1:hex, 2:dez, 3:okt): ";
		cin >> eingabe;
		if (eingabe > 0 && eingabe < 4) pfunk[eingabe - 1](zahl);
		else if (eingabe != 0) cout << endl << "Ungueltige Eingabe" << endl;
		else cout << endl << "bye bye \\(^_^)/" << endl;
	} while (eingabe);
	return 0;
}
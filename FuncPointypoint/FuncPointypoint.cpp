#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	int eingabe, zahl;
	void (*pfunk[3]) (int) = {
		[](int zahl) { cout << hex << zahl; },
		[](int zahl) { cout << dec << zahl; },
		[](int zahl) { cout << oct << zahl; }
	};
	cout << "Please insert a number: ";
	cin >> zahl;
	do
	{
		cout << endl << "Which conversion? (0:end, 1:hex, 2:dec, 3:oct): ";
		cin >> eingabe;
		if (eingabe > 0 && eingabe < 4) pfunk[eingabe - 1](zahl);
		else if (eingabe != 0) cout << endl << "invalid input" << endl;
		else cout << endl << "bye bye \\(^_^)/" << endl;
	} while (eingabe);
	return 0;
}
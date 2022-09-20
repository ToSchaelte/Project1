#include <iostream>
#include <iomanip>
#include <vector>
#include <limits>
using namespace std;



int width = 40;

/*
vector<float> werte(3);

int main()
{
	float groesste = numeric_limits<float>::min();
	float kleinste = numeric_limits<float>::max();

	for (int i = 0; i < werte.size(); i++)
	{
		cout << setw(width) << left << "Bitte geben Sie einen Wert ein:";
		cin >> werte.at(i);
		if (werte.at(i) > groesste)
		{
			groesste = werte.at(i);
		}
		if (werte.at(i) < kleinste)
		{
			kleinste = werte.at(i);
		}
	}

	cout << "Maximum: " << groesste << endl;
	cout << "Minimum: " << kleinste << endl;
}
*/


int main()
{
	float wert1 = -1;
	float wert2 = -1;
	float wert3 = -1;

	cout << setw(width) << left << "Bitte geben Sie einen Wert ein:";
	cin >> wert1;
	cout << setw(width) << left << "Bitte geben Sie einen Wert ein:";
	cin >> wert2;
	cout << setw(width) << left << "Bitte geben Sie einen Wert ein:";
	cin >> wert3;

	if (wert1 > wert2)
	{
		float tmp = wert2;
		wert2 = wert1;
		wert1 = tmp;
	}
	if (wert1 > wert3)
	{
		float tmp = wert3;
		wert3 = wert1;
		wert1 = tmp;
	}
	if (wert2 > wert3)
	{
		float tmp = wert2;
		wert2 = wert3;
		wert3 = tmp;
	}

	cout << "Minimum: " << wert1 << endl;
	cout << "Maximum: " << wert3 << endl;
}
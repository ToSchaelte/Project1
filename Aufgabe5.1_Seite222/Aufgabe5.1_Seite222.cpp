#include <iostream>
#include <iomanip>
#include <vector>
#include <limits>
using namespace std;


int width = 40;
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
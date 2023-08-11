#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

#pragma region user interface

void getInput(int& month, int& balloonCount, float pressure[12][20])
{
	do
	{
		cout << "Eingabe von Luftdruckwerten in Bar." << endl
			<< "Letzter Beobachtungsmonat (1..12): ";
		cin >> month;
		if (month > 12 || month < 1) cout << "invalid input" << endl;
	} while (month > 12 || month < 1);
	do
	{
		cout << "Anzahl der Messbalons:             ";
		cin >> balloonCount;
		if (balloonCount > 20 || balloonCount < 1) cout << "invalid input" << endl;
	} while (balloonCount > 20 || balloonCount < 1);
	cout << endl;
	for (int i = 0; i < month; ++i)
	{
		cout << i + 1 << ". Monat:" << endl;
		for (int j = 0; j < balloonCount; ++j)
		{
			cout << "Druck bei Ballon Nr. " << j + 1 << "? ";
			cin >> pressure[i][j];
		}
	}
}

void printOutput(float pressure[12][20], float averageMonth[13], float averageBalloon[20])
{
	cout << endl << "Druckmessungen:" << endl
		<< "Feld links oben:         Gesamtdurchschnitt aller gemessenen Drücke."
		<< "Oberste Zeile (Monat 0): Durchschnittsdruecke aller Monate bei jedem Ballon."
		<< "Linke Spalte (Ballon 0): Durchschnittsdruecke aller Ballons in jedem Monat."
		<< endl << "                        Ballon Nr." << endl;

	cout << "   " << "\t\t";
	for (int i = 0; i < 21; ++i)
	{
		cout << setw(7) << i;
		if (averageBalloon[i] < 0) break;
	}
	cout << endl << "Monat" << setw(3) << 0 << ":\t" << setprecision(3) << setw(7) << averageMonth[0];
	for (int i = 0; i < 20; ++i)
	{
		if (averageBalloon[i] < 0) break;
		cout << setprecision(3) << setw(7) << averageBalloon[i];
	}
	cout << endl;

	for (int i = 0; i < 12; ++i)
	{
		if (averageMonth[i+1] < 0) break;
		cout << "Monat" << setw(3) << i+1 << ":\t" << setprecision(3) << setw(7) << averageMonth[i];
		for (int j = 0; j < 20; ++j)
		{
			if (pressure[i][j] < 0) break;
			cout << setprecision(3) << setw(7) << pressure[i][j];
		}
		cout << endl;
	}
}

#pragma endregion

#pragma region logic

void calcAverage(float pressure[12][20], float averageMonth[13], float averageBalloon[20])
{
	for (int i = 0; i < 20; ++i)
	{
		int j = 0;
		if (pressure[j][i] < 0) break;
		float tmp = 0;
		for (; j < 12; ++j)
		{
			if (pressure[j][i] < 0) break;
			tmp += pressure[j][i];
		}
		averageBalloon[i] = tmp / j;
	}

	int i = 0;
	float tmp = 0;
	for (; i < 20; i++)
	{
		if (averageBalloon[i] < 0) break;
		tmp += averageBalloon[i];
	}
	averageMonth[0] = tmp / i;


	for (int i = 1; i < 12; ++i)
	{
		int j = 0;
		if (pressure[i][j] < 0) break;
		float tmp = 0;
		for (; j < 20; ++j)
		{
			if (pressure[i][j] < 0) break;
			tmp += pressure[i][j];
		}
		averageMonth[i] = tmp / j;
	}
}

#pragma endregion

int main()
{
	int month;
	int balloonCount;
	float pressure[12][20];
	getInput(month, balloonCount, pressure);
	float averageMonth[13];
	float averageBalloon[20];
	calcAverage(pressure, averageMonth, averageBalloon);
	printOutput(pressure, averageMonth, averageBalloon);
}
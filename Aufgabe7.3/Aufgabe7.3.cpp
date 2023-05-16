#include <iostream>
#include <ctime>
#include <algorithm>
#include <iomanip>
using namespace std;

#define SIZE_OF_VALUES 100

enum {
	VALUE = 0,
	COUNT
};

int getMinIndex(int values[SIZE_OF_VALUES])
{
	int min = 0;
	for (int i = 0; i < SIZE_OF_VALUES; i++)
		if (values[i] < values[min]) min = i;
	return min;
}

int getMaxIndex(int values[SIZE_OF_VALUES])
{
	int max = 0;
	for (int i = 0; i < SIZE_OF_VALUES; i++)
		if (values[i] > values[max]) max = i;
	return max;
}

float getMedian(int values[SIZE_OF_VALUES])
{
	sort(values, values + SIZE_OF_VALUES);
	int mid = SIZE_OF_VALUES / 2;
	if (SIZE_OF_VALUES % 2 != 0) return values[mid];
	return ((float)values[mid] + (float)values[mid-1]) / 2.0;
}

int getSpan(int values[])
{
	return values[getMaxIndex(values)] - values[getMinIndex(values)];
}

int getStandardDeviasion(int values[SIZE_OF_VALUES])
{
	int med = getMedian(values);
	float sum = 0;
	for (int i = 0; i < SIZE_OF_VALUES; i++)
		if (values[i] >= med) sum += values[i] - med;
		else if (values[i] < med) sum -= values[i] - med;
	return sum / SIZE_OF_VALUES;
}

void getMostAppearingValues(int values[SIZE_OF_VALUES], int mostAppearingValues[5][2])
{
	sort(values, values + SIZE_OF_VALUES);
	int countOfAppearances[SIZE_OF_VALUES];
	for (int i = 0; i < SIZE_OF_VALUES; ++i)
	{
		countOfAppearances[i] = 1;
		for (int j = i+1; j < SIZE_OF_VALUES-i; ++j)
		{
			if (values[j] == values[i])
			{
				countOfAppearances[j] = 0;
				countOfAppearances[i]++;
				continue;
			}
			i = j - 1;
			break;
		}
	}

	for (int i = 0; i < 5; ++i)
	{
		int indexOfMax = getMaxIndex(countOfAppearances);
		mostAppearingValues[i][VALUE] = values[indexOfMax];
		mostAppearingValues[i][COUNT] = countOfAppearances[indexOfMax];
		countOfAppearances[indexOfMax] = INT_MIN;
	}
}

int main()
{
	srand(time(NULL));
	int values[SIZE_OF_VALUES];
	for (int i = 0; i < SIZE_OF_VALUES; ++i)
		cout << (values[i] = rand() / 100) << " ";

	while(true)
	{
		int choice = -1;
		cout << "Choose your action:" << endl
			<< "Min:  0" << endl
			<< "Max:  1" << endl
			<< "Med:  2" << endl
			<< "Spa:  3" << endl
			<< "Dev:  4" << endl
			<< "Most: 5" << endl
			<< "New:  6" << endl;
		cin >> choice;

		switch (choice)
		{
		case 0:
			cout << "Min:  " << values[getMinIndex(values)] << endl;
			break;
		case 1:
			cout << "Max:  " << values[getMaxIndex(values)] << endl;
			break;
		case 2:
			cout << "Med:  " << getMedian(values) << endl;
			break;
		case 3:
			cout << "Spa:  " << getSpan(values) << endl;
			break;
		case 4:
			cout << "Dev:  " << getStandardDeviasion(values) << endl;
			break;
		case 5:
			cout << "Most: " << endl;
			int mostAppearingValues[5][2];
			getMostAppearingValues(values, mostAppearingValues);
			for (int i = 0; i < 5; ++i)
				cout << setw(4) << mostAppearingValues[i][VALUE] << ": " << mostAppearingValues[i][COUNT] << "x" << endl;
			break;
		case 6:
			cout << "New: " << endl;
			for (int i = 0; i < SIZE_OF_VALUES; ++i)
				cout << (values[i] = rand() / 100) << " ";
			break;
		default:
			cout << "EXIT" << endl;
			return 0;
		}
		cout << endl << endl;
	}
	return 0;
}
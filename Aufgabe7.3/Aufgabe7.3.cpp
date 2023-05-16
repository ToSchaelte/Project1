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
		cout << (values[i] = rand()/100) << " ";
	cout << endl
		<< "Min: " << values[getMinIndex(values)] << endl
		<< "Max: " << values[getMaxIndex(values)] << endl
		<< "Med: " << getMedian(values) << endl
		<< "Spa: " << getSpan(values) << endl
		<< "Dev: " << getStandardDeviasion(values) << endl
		<< "Most:" << endl;
	int mostAppearingValues[5][2];
	getMostAppearingValues(values, mostAppearingValues);
	for (int i = 0; i < 5; ++i)
		cout << setw(4) << mostAppearingValues[i][VALUE] << ": " << mostAppearingValues[i][COUNT] << "x" << endl;
}
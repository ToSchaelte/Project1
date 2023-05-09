#include <iostream>
#include <ctime>
#include <algorithm>
using namespace std;

const int SIZE_OF_VALUES = 10;

int getMinIndex(int values[])
{
	int min = 0;
	for (int i = 0; i < SIZE_OF_VALUES; i++)
		if (values[i] < values[min]) min = i;
	return min;
}

int getMaxIndex(int values[])
{
	int max = 0;
	for (int i = 0; i < SIZE_OF_VALUES; i++)
		if (values[i] > values[max]) max = i;
	return max;
}

float getMedian(int sortedValues[])
{
	int mid = SIZE_OF_VALUES / 2;
	if (SIZE_OF_VALUES % 2 != 0) return sortedValues[mid];
	return ((float)sortedValues[mid] + (float)sortedValues[mid-1]) / 2.0;
}

int getSpan(int values[])
{
	return values[getMaxIndex(values)] - values[getMinIndex(values)];
}

int getStandardDeviasion(int values[])
{
	int med = getMedian(values);
	float sum = 0;
	for (int i = 0; i < SIZE_OF_VALUES; i++)
		if (values[i] >= med) sum += values[i] - med;
		else if (values[i] < med) sum -= values[i] - med;
	return sum / SIZE_OF_VALUES;
}

void getMostAppearingValues(int sortedValues[SIZE_OF_VALUES], int mostAppearingValues[5])
{
	
}

int main()
{
	srand(time(NULL));
	int values[SIZE_OF_VALUES];
	for (int i = 0; i < SIZE_OF_VALUES; ++i)
		cout << (values[i] = rand()/1000) << " ";
	sort(begin(values), end(values));
	cout << endl << "sorted: ";
	for (int i = 0; i < SIZE_OF_VALUES; ++i)
		cout << values[i] << " ";
	cout << endl
		<< "Min: " << values[getMinIndex(values)] << endl
		<< "Max: " << values[getMaxIndex(values)] << endl
		<< "Med: " << getMedian(values) << endl
		<< "Spa: " << getSpan(values) << endl
		<< "Dev: " << getStandardDeviasion(values) << endl
		<< "Most:" << endl;
	int mostAppearingValues[5];
	getMostAppearingValues(values, mostAppearingValues);
	for (int i = 0; i < 5; ++i)
		cout << mostAppearingValues[i] << endl;
}
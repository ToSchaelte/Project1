#include<iostream>

#include "CommonSortingUtils.h"

using namespace std;

bool CommonSortingUtils::isSorted(int a[], int arraySize)
{
	for (int i = 0; i < arraySize - 1; ++i)
		if (a[i] > a[i + 1]) return false;
	return true;
}

void CommonSortingUtils::print(int a[], int arraySize)
{
	for (int i = 0; i < arraySize; ++i)
		cout << a[i] << " ";
}
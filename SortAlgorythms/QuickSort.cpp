#include <iostream>
#include <ctime>
#include <iomanip>

#include "QuickSort.h"
#include "CommonSortingUtils.h"

using namespace std;

typedef CommonSortingUtils Utils;

static int _counter;
static int _arraySize;

void QuickSort::printRun(int a[])
{
    cout << endl << "Run " << _counter++ << ":  ";
    Utils::print(a, _arraySize);
}

void QuickSort::sort(int a[], int left, int right)
{
    if (left >= right - 1) return;
    int i = left;
    for (int j = left; j < right; ++j)
        if (a[j] < a[right]) swap(a[i++], a[j]);
    swap(a[i], a[right]);
    //printRun(a);
    sort(a, left, i - 1);
    sort(a, i + 1, right);
}

void QuickSort::sort(int a[], int arraySize)
{
    _arraySize = arraySize;
    _counter = 1;
    sort(a, 0, arraySize-1);
}
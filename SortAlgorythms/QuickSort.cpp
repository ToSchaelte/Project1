#include <iostream>
#include <ctime>
#include <iomanip>

#include "QuickSort.h"
#include "CommonSortingUtils.h"

using namespace std;

typedef CommonSortingUtils Utils;

static int _counter;
static int _arraySize;

void QuickSort::printRun(int a[], int run, int arraySize)
{
    cout << endl << "Run " << run << ":  ";
    Utils::print(a, arraySize);
}

void QuickSort::sort(int a[], int left, int right)
{
    if (left >= right-1) return;
    int pivot = a[right];
    int i = (left - 1);
    for (int j = left; j < right; ++j)
    {
        if (a[j] >= pivot) continue;
        swap(a[++i], a[j]);
    }
    swap(a[i + 1], a[right]);
    printRun(a, _counter++, _arraySize);
    sort(a, left, i);
    sort(a, i + 2, right);
}

void QuickSort::sort(int a[], int arraySize)
{
    _arraySize = arraySize;
    _counter = 1;
    sort(a, 0, arraySize-1);
}
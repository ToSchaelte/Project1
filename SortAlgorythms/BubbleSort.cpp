#include <iostream>
#include <ctime>
#include <iomanip>

#include "BubbleSort.h"
#include "CommonSortingUtils.h"

using namespace std;

typedef CommonSortingUtils Utils;

void BubbleSort::printRun(int a[], int run, int arraySize)
{
    cout << endl << "Run " << run << ":  ";
    Utils::print(a, arraySize);
}

void BubbleSort::sort(int a[], int arraySize)
{
    for (int i = arraySize - 1; i > 0; --i)
    {
        for (int j = 0; j < i; ++j)
            if (a[j] > a[j + 1])
                swap(a[j], a[j + 1]);
        //printRun(a, arraySize - i, arraySize);
        if (Utils::isSorted(a, arraySize))
            return;
    }
}
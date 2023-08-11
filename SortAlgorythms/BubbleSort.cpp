#include <iostream>
#include <ctime>
#include <iomanip>

#include "BubbleSort.h"

using namespace std;

void BubbleSort::printRun(int a[], int run, int arraySize)
{
    cout << endl << "Run " << run << ":  ";
    for (int i = 0; i < arraySize; ++i)
        cout << a[i] << " ";
}

void BubbleSort::sort(int a[], int arraySize)
{
    for (int i = arraySize - 1; i > 0; i -= 1)
    {
        for (int j = 0; j < i; j++)
            if (a[j] > a[j + 1])
                swap(a[j], a[j + 1]);
        printRun(a, arraySize - i, arraySize);
    }
}

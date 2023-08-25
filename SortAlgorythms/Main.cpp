#include <iostream>
#include <ctime>
#include <iomanip>

#include "BubbleSort.h"
#include "QuickSort.h"
#include "CommonSortingUtils.h"

using namespace std;

typedef CommonSortingUtils Utils;

constexpr int array_size = 10;

int main(int argc, char* argv[])
{
    cout << "How do you want to sort your array? (0=BubbleSort, 1=Quicksort) ";
    int sortMechanism = -1;
    cin >> sortMechanism;
    srand(time(NULL));
    int numbers[array_size];
    for (int i = 0; i < array_size; ++i)
        numbers[i] = rand() / 100;
    cout << "Before: ";
    Utils::print(numbers, array_size);
    switch (sortMechanism)
    {
    case 0:
        BubbleSort::sort(numbers, array_size);
        break;
    case 1:
        QuickSort::sort(numbers, array_size);
        break;
    default:
        cout << "Invalid input" << endl;
        return 0;
    }
    cout << endl << "After:  ";
    Utils::print(numbers, array_size);
    return 1;
}
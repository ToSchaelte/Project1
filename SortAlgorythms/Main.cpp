#include <iostream>
#include <ctime>
#include <iomanip>

#include "BubbleSort.h"
#include "CommonSortingUtils.h"

using namespace std;

typedef CommonSortingUtils Utils;

constexpr int array_size = 10;

int main(int argc, char* argv[])
{
    srand(time(NULL));
    int numbers[array_size];
    for (int i = 0; i < array_size; ++i)
        numbers[i] = rand() / 100;
    cout << "Before: ";
    Utils::print(numbers, array_size);
    BubbleSort::sort(numbers, array_size);
    cout << endl << "After:  ";
    Utils::print(numbers, array_size);
    return 0;
}
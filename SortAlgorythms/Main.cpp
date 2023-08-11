#include <iostream>
#include <ctime>
#include <iomanip>

#include "BubbleSort.h"

using namespace std;

constexpr int array_size = 10;

int main(int argc, char* argv[])
{
    srand(time(NULL));
    int numbers[array_size];
    cout << "Before: ";
    for (int i = 0; i < array_size; ++i)
    {
        numbers[i] = rand() / 100;
        cout << numbers[i] << " ";
    }
    BubbleSort::sort(numbers, array_size);
    cout << endl << "After:  ";
    for (int i = 0; i < array_size; ++i)
        cout << numbers[i] << " ";
    return 0;
}
#include <iostream>
#include <ctime>
#include <iomanip>
#include <time.h>

#include "BubbleSort.h"
#include "QuickSort.h"
#include "CommonSortingUtils.h"

using namespace std;

typedef CommonSortingUtils Utils;

constexpr int array_size = 10;

int main(int argc, char* argv[])
{
    srand(time(NULL));
    int numbers1[array_size];
    int numbers2[array_size];
    for (int i = 0; i < array_size; ++i)
    {
        numbers1[i] = rand() / 10;
        numbers2[i] = numbers1[i];
    }
    cout << "Before: ";
    Utils::print(numbers1, array_size);
    const clock_t beforBubble = clock();
    cout << endl << endl << "Bubble sort: ";
    BubbleSort::sort(numbers1, array_size);
    const clock_t afterBubble = clock();
    cout << endl << endl << "Quick sort: ";
    QuickSort::sort(numbers2, array_size);
    const clock_t afterQuick = clock();
    cout << endl << endl << "After:  ";
    Utils::print(numbers1, array_size);
    cout << endl << "Bubble sort: " << (afterBubble - beforBubble) / (double)CLOCKS_PER_SEC << endl
        << "Quick sort: " << (afterQuick - afterBubble) / (double)CLOCKS_PER_SEC << endl;
    return 1;
}
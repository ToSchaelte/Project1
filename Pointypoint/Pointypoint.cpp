#include <iostream>

using namespace std;

int* generateArray(int size)
{
    srand(time(NULL));
    int* numbers = new int[size];
    for (int i = 0; i < size; ++i)
        numbers[i] = rand() / 10;
    return numbers;
}

int main()
{
    cout << "Laenge:   ";
    int arraySize;
    cin >> arraySize;
    int* numbers = generateArray(arraySize);
    cout << "Array:    ";
    for (int i = 0; i < arraySize; ++i)
        cout << numbers[i] << " ";
    cout << endl;
    int uLen = 0;
    int gLen = 0;
    for (int i = 0; i < arraySize; ++i)
        if (numbers[i] % 2 == 0) ++gLen;
        else ++uLen;
    int* ungerade = new int[uLen];
    int* gerade = new int[gLen];
    int ui = 0;
    int gi = 0;
    for (int i = 0; i < arraySize; ++i)
        if (numbers[i] % 2 == 0) gerade[gi++] = numbers[i];
        else ungerade[ui++] = numbers[i];
    cout << "Gerade:   ";
    for (int i = 0; i < gLen; ++i)
        cout << gerade[i] << " ";
    cout << endl<< "Ungerade: ";
    for (int i = 0; i < uLen; ++i)
        cout << ungerade[i] << " ";
    cout << endl;
    delete[] ungerade;
    delete[] gerade;
}
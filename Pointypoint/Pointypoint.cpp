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
    cout << "Length: ";
    int arraySize;
    cin >> arraySize;
    int* numbers = generateArray(arraySize);
    cout << "Array:  ";
    for (int i = 0; i < arraySize; ++i)
        cout << numbers[i] << " ";
    cout << endl;
    int oLen = 0;
    for (int i = 0; i < arraySize; ++i) oLen += numbers[i] % 2;
    int eLen = arraySize - oLen;
    int* odd = new int[oLen];
    int* even = new int[eLen];
    int oi = 0;
    int ei = 0;
    for (int i = 0; i < arraySize; ++i)
        if (numbers[i] % 2 == 0) even[ei++] = numbers[i];
        else odd[oi++] = numbers[i];
    cout << "Even:   ";
    for (int i = 0; i < eLen; ++i)
        cout << even[i] << " ";
    cout << endl<< "Odd:    ";
    for (int i = 0; i < oLen; ++i)
        cout << odd[i] << " ";
    cout << endl;
    delete[] odd;
    delete[] even;
}
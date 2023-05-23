#include <iostream>
#include <vector>

#include "Matrix.h"

using namespace std;

int main()
{
    Matrix matrixA({
        { 1, 3, 4 },
        { 2, 6, 8 },
        { 3, 9, 12 }
    });
    Matrix matrixB({
        { 4, 2, 69 },
        { 3, 5, 73 },
        { 2, 8, 77 }
    });
    cout << (matrixA * matrixB).toString();
}
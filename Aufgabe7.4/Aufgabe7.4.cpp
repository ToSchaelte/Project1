#include <iostream>
using namespace std;

//  a b         a1 * a2 + b1 * c2   a1 * b2 + b1 * d2
//  c d         c1 * a2 + d1 * c2   c1 * b2 + d1 * d2

struct Matrix
{
    int a = 0, b = 0, c = 0, d = 0;

    Matrix(int a, int b, int c, int d)
    {
        this->a = a;
        this->b = b;
        this->c = c;
        this->d = d;
    }

    Matrix operator*(Matrix m)
    {
        return Matrix(a * m.a + b * m.c, a * m.b + b * m.d,
            c * m.a + d * m.c, c * m.b + d * m.d);
    }
};

int main()
{
    Matrix m1(1, 3, 2, 6);
    Matrix m2(4, 2, 3, 5);
    Matrix m3 = m1 * m2;
    cout << m3.a << " " << m3.b << endl
        << m3.c << " " << m3.d << endl;
}
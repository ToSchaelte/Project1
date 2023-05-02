#include <iostream>

void printFibunacci(int counter, int number1 = 0, int number2 = 1)
{
    std::cout << number2 << " ";
    if (counter <= 1) return;
    printFibunacci(counter - 1, number2, number1 + number2);
}

unsigned long long getFakultaet(unsigned long long number)
{
    if (number <= 0) return 1;
    return number*getFakultaet(number-1);
}

unsigned long long getQuersumme(unsigned long long number)
{
    if (number <= 0) return 0;
    return number % 10 + getQuersumme(number / 10);
}

int main()
{
    std::cout << "Fibonacci: " << std::endl;
    printFibunacci(20);
    std::cout << std::endl << "Fakultaet (5): " << std::endl
        << getFakultaet(5);
    std::cout << std::endl << "Quersumme (6969): " << std::endl
        << getQuersumme(6969);
}
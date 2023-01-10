#include <iostream>

void task1()
{
    double kontostand = 1000000;
    double prozentsatz = 0.04;
    double jaehrlicheRente = 60000;

    int laufzeit = 0;

    while (kontostand > 60000)
    {
        kontostand -= jaehrlicheRente;
        kontostand += kontostand * prozentsatz;
        ++laufzeit;
    }

    std::cout << "Die Rente kann ungefaehr " << laufzeit << " Jahr gezahlt werden." << std::endl;
}

int million(double kapital, double prozent)
{
    const int MILLION = 1000000;
    double prozentAlsDezimal = prozent / 100;

    int laufzeit = 0;

    while (kapital < MILLION)
    {
        kapital += kapital * prozentAlsDezimal;
        ++laufzeit;
    }

    return laufzeit;
}

void task2()
{
    double startkapital = -1;
    int zinssatz = -1;

    std::cout << "Geben Sie Ihr Startkapital ein: ";
    std::cin >> startkapital;
    std::cout << "Geben Sie Ihren Zinssatz ein: ";
    std::cin >> zinssatz;

    std::cout << "Sie muessen " << million(startkapital, zinssatz) << " Jahre sparen." << std::endl;
}

int main()
{
    task1();
    task2();
}
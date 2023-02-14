#include <iostream>
#include "Aufgabe6.2.h"

int main()
{
	std::cout << "Aufgabe 1: " << eingabe(69) << std::endl;
	system("pause");
	system("cls");
	std::cout << "Aufgabe 2: ";
	zahlenausgabe(69);
	system("pause");
	system("cls");
	std::cout << "Aufgabe 3: " << fakultaet(15) << std::endl;
}

int eingabe(int zahl)
{
    return zahl <= 1000 && zahl >= 0;
}

void zahlenausgabe(int zahl)
{
	for (int i = 1; i < zahl; ++i) std::cout << i << ", ";
	std::cout << zahl << std::endl;
}

unsigned long long fakultaet(int zahl)
{
	unsigned long long fak = 1;
	for (int i = 1; i <= zahl; ++i) fak *= i;
	return fak;
}
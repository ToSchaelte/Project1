#include <iostream>


void task1()
{
	double versicherungssumme = 0;
	double vertreterprovision = 0;
	double provisionProAbschluss = 50;

	do
	{
		std::cout << "Versicherungssumme: ";
		std::cin >> versicherungssumme;
		if (versicherungssumme == 0)
		{
			break;
		}
		vertreterprovision += provisionProAbschluss + versicherungssumme / 100;
	} while (versicherungssumme != 0);

	std::cout << "Deine Provision: " << vertreterprovision << std::endl;
}

void task2()
{
	double umsatz = 500000;
	double verdoppelterUmsatz = umsatz * 2;
	double wachstumInProzent = 8;
	double wachstumInDezimal = wachstumInProzent/100;
	double dauer = 0;

	std::cout << "Momentaner Umsatz: ";
	std::cin >> umsatz;
	std::cout << "Umsatzwachstum pro Jahr (in %): ";
	std::cin >> wachstumInProzent;

	verdoppelterUmsatz = umsatz * 2;
	wachstumInDezimal = wachstumInProzent / 100;

	do
	{
		umsatz += umsatz * wachstumInDezimal;
		++dauer;
	} while (umsatz < verdoppelterUmsatz);
	std::cout << "Es dauert " << dauer << " Jahre bis der Umsatz verdoppelt wurde." << std::endl;
}

int main()
{
    task1();
	std::cout << std::endl << std::endl;
	task2();
}
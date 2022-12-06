#include <iostream>

int main()
{

	// 1
	int maxValue = -1;

	std::cout << "please insert a max value: ";
	std::cin >> maxValue;

	for (int i = 1; i <= maxValue; ++i)
	{
		std::cout << i;

		if (i != maxValue)
		{
			std::cout << ", ";
		}
	}

	std::cout << std::endl << std::endl;



	// 2
	maxValue = -1;

	std::cout << "please insert a max value: ";
	std::cin >> maxValue;

	for (int i = maxValue; i >= 2; --i)
	{
		if (i % 2 == 0)
		{
			std::cout << i;
			if (i != 2)
			{
				std::cout << ", ";
			}
		}
	}

	std::cout << std::endl << std::endl;




	// 3

	for (int i = 1; i <= 19; ++i)
	{
		if (i <= 10)
		{
			std::cout << i;
		}
		else
		{
			std::cout << 10 - i % 10;
		}

		if (i != 19)
		{
			std::cout << ", ";
		}
	}
}
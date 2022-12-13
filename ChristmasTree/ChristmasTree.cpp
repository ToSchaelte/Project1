#include <iostream>

void printTreeRow(int minValue)
{
	for (int i = 0; i < 10; ++i)
	{
		if (i >= minValue)
		{
			std::cout << i << " ";
		}
		else
		{
			std::cout << "  ";
		}
	}
	for (int i = 10; i >= minValue; --i)
	{
		std::cout << i << " ";
	}
	std::cout << std::endl;
}

int main()
{
	printTreeRow(10);

	for (int minValue = 9; minValue >= 0; --minValue)
	{
		for (int j = 0; j < 2; ++j)
		{
			printTreeRow(minValue);
		}
	}

	for (int j = 0; j < 4; ++j)
	{
		printTreeRow(9);
	}

	for (int i = 8; i >= 4; i -= 2)
	{
		printTreeRow(i);
	}
}
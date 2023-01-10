#include <iostream>

void printTreeRow(int minValue, int maxValue)
{
	for (int i = 0; i < maxValue; ++i)
	{
		if (i >= minValue)
		{
			std::cout << i << " ";
		}
		else
		{
			if ((double)i / 10 >= 1)
			{
				std::cout << " ";
			}
			if ((double)i / 100 >= 1)
			{
				std::cout << " ";
			}
			std::cout << "  ";
		}
	}
	for (int i = maxValue; i >= minValue; --i)
	{
		std::cout << i << " ";
	}
	std::cout << std::endl;
}

int main()
{
	int maxValue = 42;
	int stretchFactor = maxValue / 5;
	int stemWidth = maxValue - maxValue / 7;
	int stemHeight = maxValue / 2 - maxValue / 10;

	printTreeRow(maxValue, maxValue);

	for (int minValue = maxValue-1; minValue >= 0; --minValue)
	{
		for (int j = 0; j < stretchFactor; ++j)
		{
			printTreeRow(minValue, maxValue);
		}
	}

	for (int j = 0; j < stemHeight; ++j)
	{
		printTreeRow(stemWidth, maxValue);
	}

	for (int i = maxValue*0.8; i >= 4; i -= 2)
	{
		printTreeRow(i, maxValue);
	}
}
#include <iostream>

int main()
{
	for (int maxValue = 10; maxValue >= 0; --maxValue)
	{
		for (int i = maxValue; i >= 0; --i)
		{
			std::cout << (i >= 10 ? "" : " ") << i << " ";
		}
		std::cout << std::endl;
	}
}
#include <iostream>
#include <cstring>

int AnzahlZeichen(char K[], char c)
{
	int count = 0;
	for (int i = 0; K[i]; i++)
		if (K[i] == c) ++count;
	return count;
}

bool Palindrom(char K[])
{
	for (int i = 0, int j = strlen(K) - 1; i < j; ++i, --j)
		if (K[i] != K[j]) return false;
	return true;
}

void Umdrehen(char K[])
{
	for (int i = 0, int j = strlen(K) - 1; i < j; ++i, --j)
	{
		char tmp = K[i];
		K[i] = K[j];
		K[j] = tmp;
	}
}

long Char2Int(char K[])
{
	long char2int = 0;
	for (int i = 0; i < strlen(K); ++i)
	{
		long tmp = K[i] - (long)'0';
		if (tmp >= 0 && tmp < 10)
		{
			char2int *= 10;
			char2int += tmp;
		}
	}
	return char2int;
}
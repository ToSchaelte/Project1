#include <iostream>
#include <ctime>
using namespace std;

int main()
{
	srand(time(NULL));
    int values[10];
	int max = 0;
	int min = 0;
	cout << "Array: ";
	for (int i = 0; i < 10; ++i)
	{
		values[i] = rand();
		if (values[i] > values[max]) max = i;
		else if (values[i] < values[min]) min = i;
		cout << values[i] << " ";
	}
	cout << endl
		<< "The bigges value is: " << values[max] << " at index " << max << endl
		<< "The smallest value is: " << values[min] << " at index " << min << endl;
}
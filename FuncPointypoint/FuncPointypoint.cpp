#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	int input, num;
	void (*pfunk[3]) (int) = {
		[](int num) { cout << hex << num; },
		[](int num) { cout << dec << num; },
		[](int num) { cout << oct << num; }
	};
	cout << "Please insert a number: ";
	cin >> num;
	do
	{
		cout << endl << "Which conversion? (0:end, 1:hex, 2:dec, 3:oct): ";
		cin >> input;
		if (input > 0 && input < 4) pfunk[input - 1](num);
		else if (input != 0) cout << endl << "invalid input" << endl;
		else cout << endl << "bye bye \\(^_^)/" << endl;
	} while (input);
	return 0;
}
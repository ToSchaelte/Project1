#include <iostream>
#include <math.h>
#include <string>
#include <iomanip>
using namespace std;

void helloWorld() {
	cout << "Hello World" << endl;
}

void test1() {
	string input;
	int count;
	cout << "please insert a text" << endl;
	getline(cin, input);
	cout << "how often do you want this text to be repeated? ";
	cin >> count;
	for (int i = 0; i < count; i += 1) {
		cout << input << endl;
	}
}


void test2() {
	int number;

	cout << "gib nummer: ";
	cin >> number;

	cout << "Dezimal : " << dec << number << endl;
	cout << "Oktal : " << oct << number << endl;
	cout << "Hexadezimal: " << hex << number << endl;

	cout << setw(10) << setfill('#') << left << "Hallo" << endl;
	cout << setprecision(3) << 1.95583 << endl;
}

void main() {
	helloWorld();
	test1();
	test2();
}
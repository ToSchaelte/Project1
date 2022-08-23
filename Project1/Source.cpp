#include <iostream>
#include <math.h>
#include <string>
using namespace std;

void test1();

void main() {
	test1();
}

void test1() {
	string input;
	int count;
	cout << "please insert a text" << endl;
	getline(cin, input);
	cout << "how often do you want this text to be repeated?";
	cin >> count;
	for (int i = 0; i < count; i += 1) {
		cout << input << endl;
	}
}
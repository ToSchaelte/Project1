#include <iostream>
#include <math.h>
#include <string>
#include <iomanip>
using namespace std;

void helloWorld();
void test1();
void test2();

void print(string);
void println(string);

void main() {
	//helloWorld();
	//test1();
	test2();
}

void helloWorld() {
	println("Hello World");
}

void test1() {
	string input;
	int count;
	println("please insert a text");
	getline(cin, input);
	print("how often do you want this text to be repeated?");
	cin >> count;
	for (int i = 0; i < count; i += 1) {
		println(input);
	}
}


void test2() {
	int number;

	cout << "gib nummer: ";
	cin >> number;

	cout << "Dezimal : " << dec << number << endl;
	cout << "Oktal : " << oct << number << endl;
	cout << "Hexadezimal: " << hex << number << endl;

	cout << setw(10) << setfill('#') << "Hallo" << endl;
	cout << setw(10) << setfill('#') << left << "Hallo" << endl;
	cout << setprecision(3) << 1.95583 << endl;
}




void print(string out) {
	cout << out;
}
void println(string out) {
	cout << out << endl;
}
#include <iostream>

using namespace std;

struct Student
{
	int id = 1000+(rand() % 9000);
	string lastName;
	string firstName;
	int pcNumber;
};

int main()
{
	srand(time(NULL));
	auto studentCount = 20;
	auto students = new Student[studentCount];
	for (auto i = 0; i < studentCount; ++i)
	{
		int pcNr;
		cout << "PC Number: ";
		cin >> pcNr;
		if (pcNr == 0)
		{
			studentCount = i;
			break;
		}
		students[i] = Student();
		students[i].pcNumber = pcNr;
		cout << "First name: ";
		cin >> students[i].firstName;
		cout << "Last name: ";
		cin >> students[i].lastName;
		cout << endl;
	}
	cout << endl;
	for (auto i = 0; i < studentCount; ++i)
		cout << "The ID of the student " << students[i].firstName << " " << students[i].lastName
		<< " at the PC " << students[i].pcNumber << " is: " << students[i].id << endl;
	delete[] students;
}
#pragma once
#include <string>

class Student
{
public:
	Student();
	Student(int, std::string, std::string);
	int id;
	std::string first_name;
	std::string last_name;
};
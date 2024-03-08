#include "Student.h"

Student::Student()
{
}

Student::Student(int id, std::string first_name, std::string last_name)
{
	this->id = id;
	this->first_name = first_name;
	this->last_name = last_name;
}

#pragma once

class Matrix
{
public:
	Matrix() = delete;
	Matrix(std::vector<std::vector<int>> values);
	Matrix operator*(Matrix m);
	std::string toString();

private:
	std::vector<std::vector<int>> values;
};
#include <iostream>
#include <iomanip>
#include <vector>
#include <sstream>
using namespace std;



struct Matrix
{
    vector<vector<int>> values;

    Matrix(vector<vector<int>> values)
    {
        this->values = values;
    }

    Matrix operator*(Matrix m)
    {
        vector<vector<int>> newValues = vector<vector<int>>(values.size());

        for (int row = 0; row < values.size(); ++row)
        {
            newValues[row] = vector<int>(m.values.size());
            for (int column = 0; column < m.values.size(); ++column)
            {
                newValues[row][column] = 0;
                for (int i = 0; i < values[0].size(); ++i)
                    newValues[row][column] += values[row][i] * m.values[i][column];
            }
        }

        return Matrix(newValues);
    }

    string toString()
    {
        stringstream sstream;

        sstream << "/ ";
        for (int i = 0; i < values[0].size(); ++i)
            sstream << setw(4) << values[0][i] << " ";
        sstream << "\\\n";

        for (int i = 1; i < values.size() - 1; ++i)
        {
            sstream << "| ";
            for (int j = 0; j < values[i].size(); ++j)
                sstream << setw(4) << values[i][j] << " ";
            sstream << "|\n";
        }

        sstream << "\\ ";
        for (int i = 0; i < values[values.size() - 1].size(); ++i)
            sstream << setw(4) << values[values.size() - 1][i] << " ";
        sstream << "/";

        return sstream.str();
    }
};

int main()
{
    vector<vector<int>> valuesA = {
        { 1, 3, 4 },
        { 2, 6, 8 },
        { 3, 9, 12}
    };
    vector<vector<int>> valuesB = {
        { 4, 2, 69 },
        { 3, 5, 73 },
        { 2, 8, 77 }
    };
    Matrix matrixA(valuesA);
    Matrix matrixB(valuesB);
    Matrix matrixC = matrixA * matrixB;
    cout << matrixC.toString();
}
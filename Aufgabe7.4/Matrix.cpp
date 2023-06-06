#include <iomanip>
#include <vector>
#include <sstream>

#include "Matrix.h"
#include "CommonUtils.h"

using namespace std;

Matrix::Matrix(vector<vector<int>> values)
{
    int len = 0;
    for (int i = 0; i < values.size(); ++i)
        if (len == 0) len = values[i].size();
        else if (values[i].size() != len) throw exception("this is not a correct matrix");
    this->values = values;
}

Matrix Matrix::operator*(Matrix m)
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

string Matrix::toString()
{
    stringstream sstream;
    sstream << "/ " << vectorToString(values[0], 4) << "\\\n";
    for (int i = 1; i < values.size() - 1; ++i)
        sstream << "| " << vectorToString(values[i], 4) << "|\n";
    sstream << "\\ " << vectorToString(values[values.size() - 1], 4) << "/";
    return sstream.str();
}
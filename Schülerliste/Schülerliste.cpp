#include <iostream>

using namespace std;

int indexOf(char *array, int arrayLength, char item)
{
    for (int i = 0; i < arrayLength; ++i)
        if (array[i] == item) return i;
    return -1;
}

void sortAlphabetical(char **a, char **b, int left, int right)
{
    if (left >= right - 1) return;
    int i = left;
    for (int j = left; j < right; ++j)
    {
        int k = 0;
        while (a[j][k] == a[right][k])
        {
            ++k;
            if (k >= 30) break;
        }
        if (a[j][k] < a[right][k])
        {
            swap(a[i], a[j]);
            swap(b[i], b[j]);
            ++i;
        }
    }
    swap(a[i], a[right]);
    swap(b[i], b[right]);
    sortAlphabetical(a, b, left, i - 1);
    sortAlphabetical(a, b, i + 1, right);
}

void sortAlphabetical(char **a, char **b, int arraySize)
{
    sortAlphabetical(a, b, 0, arraySize - 1);
}

int main()
{
    int studentCount = 0;
    cout << "How many students are in the class? ";
    cin >> studentCount;
    char **students = new char *[studentCount];
    char **studentFirstNames = new char *[studentCount];
    int li = 0;
    int fi = 0;
    for (int i = 0; i < studentCount*2; ++i)
    {
        if (i % 2 == 0)
        {
            students[li] = new char[30];
            cout << "Student Nr. " << li + 1 << "(last name): ";
            cin >> students[li];
            ++li;
            continue;
        }
        studentFirstNames[fi] = new char[30];
        cout << "Student Nr. " << fi + 1 << "(first name): ";
        cin >> studentFirstNames[fi];
        ++fi;
    }

    sortAlphabetical(students, studentFirstNames, studentCount);
    cout << endl << endl << "Sorted:" << endl;
    for (int i = 0; i < studentCount; ++i) cout << i+1 << ": " << students[i] << ", " << studentFirstNames[i] << endl;

    for (int i = 0; i < studentCount; ++i)
    {
        delete[] students[i];
        delete[] studentFirstNames[i];
    }
    delete[] students;
    delete[] studentFirstNames;
}
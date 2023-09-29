#include <iostream>

using namespace std;

int indexOf(char *array, int arrayLength, char item)
{
    for (int i = 0; i < arrayLength; ++i)
        if (array[i] == item) return i;
    return -1;
}

void sortAlphabetical(char ***a, int left, int right)
{
    if (left >= right - 1) return;
    int i = left;
    for (int j = left; j < right; ++j)
    {
        int k = 0;
        while (a[j][0][k] == a[right][0][k])
        {
            ++k;
            if (k >= 30) break;
        }
        if (a[j][0][k] < a[right][0][k])
        {
            swap(a[i], a[j]);
            ++i;
        }
    }
    swap(a[i], a[right]);
    sortAlphabetical(a, left, i - 1);
}

void sortAlphabetical(char ***a, int arraySize)
{
    sortAlphabetical(a, 0, arraySize - 1);
}

int main()
{
    // Init
    int studentCount = 0;
    cout << "How many students are in the class? ";
    cin >> studentCount;
    char ***students = new char **[studentCount];
    for (int i = 0; i < studentCount; ++i)
    {
        students[i] = new char *[2];
        students[i][0] = new char[30];
        cout << "Student Nr. " << i + 1 << "(last name): ";
        cin >> students[i][0];

        students[i][1] = new char[30];
        cout << "Student Nr. " << i + 1 << "(first name): ";
        cin >> students[i][1];
    }

    // Sort
    sortAlphabetical(students, studentCount);
    cout << endl << endl << "Sorted:" << endl;
    for (int i = 0; i < studentCount; ++i) cout << i+1 << ": " << students[i][0] << ", " << students[i][1] << endl;

    // Delete
    for (int i = 0; i < studentCount; ++i)
    {
        delete[] students[i][0];
        delete[] students[i][1];
        delete[] students[i];
    }
    delete[] students;
}
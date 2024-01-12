#include <iostream>

using namespace std;

struct student
{
    int id = 1000 + rand() % 9000;
    string last_name;
    string first_name;
    int pc_number;
};

int main()
{
    srand(time(nullptr));
    auto student_count = 20;
    const auto students = new student[student_count];
    for (auto i = 0; i < student_count; ++i)
    {
        int pc_nr;
        cout << "PC Number: ";
        cin >> pc_nr;
        if (pc_nr == 0)
        {
            student_count = i;
            break;
        }
        students[i] = student();
        students[i].pc_number = pc_nr;
        cout << "First name: ";
        cin >> students[i].first_name;
        cout << "Last name: ";
        cin >> students[i].last_name;
        cout << '\n';
    }
    cout << '\n';
    for (auto i = 0; i < student_count; ++i)
        cout << "The ID of the student " << students[i].first_name << " " << students[i].last_name
            << " at the PC " << students[i].pc_number << " is: " << students[i].id << '\n';
    delete[] students;
}

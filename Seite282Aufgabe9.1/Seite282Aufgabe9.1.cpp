#include <iostream>

using namespace std;

struct TBenutzer
{
    char Name[40 + 1];
    char Passwort[40 + 1];
};

bool IsPasswordValid(TBenutzer user)
{
    auto len = strlen(user.Name);
    for (auto i = 0; i < len; ++i)
        if (user.Name[i] != user.Passwort[len-1-i])
            return false;
    return true;
}

int main()
{
    auto user = TBenutzer();
    cout << "Name: ";
    cin >> user.Name;
    cout << "Password: ";
    cin >> user.Passwort;
    if (IsPasswordValid(user)) cout << "LOGIN KORREKT";
    else cout << "nicht korrekt";
}

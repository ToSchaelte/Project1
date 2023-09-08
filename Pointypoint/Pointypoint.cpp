#include <iostream>

using namespace std;

int main()
{
    string hellu = "Hello there!";
    string* iPointAtHellu = &hellu;
    string& iReferenceHellu = hellu;
    cout << *iPointAtHellu << endl
        << iReferenceHellu << endl;
    hellu = "General Kenobi!";
    cout << *iPointAtHellu << endl
        << iReferenceHellu << endl;
}
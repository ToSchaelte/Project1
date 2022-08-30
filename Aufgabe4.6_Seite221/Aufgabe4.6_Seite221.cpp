#include <iostream>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <iterator>
#include <iomanip>
using namespace std;

int main()
{
    vector<int> ip1(4);
    vector<int> ip2(4);
    vector<int> subnet_mask(4);

    cout << "Subnetting Version 1.0" << endl << endl;

    cout << setw(40) << left << "Bitte die 1. IP-Adresse eingeben: ";
    cin >> ip1.at(0) >> ip1.at(1) >> ip1.at(2) >> ip1.at(3);

    cout << setw(40) << "Bitte die 2. IP-Adresse eingeben: ";
    cin >> ip2.at(0) >> ip2.at(1) >> ip2.at(2) >> ip2.at(3);

    cout << setw(40) << "Bitte die Subnet-Mask eingeben: ";
    cin >> subnet_mask.at(0) >> subnet_mask.at(1) >> subnet_mask.at(2) >> subnet_mask.at(3);

    for (int i = 0; i < ip1.size(); i++)
    {
        ip1.at(i) &= subnet_mask.at(i);
        ip2.at(i) &= subnet_mask.at(i);
    }


    ostringstream oss1;
    copy(ip1.begin(), ip1.end() - 1, ostream_iterator<int>(oss1, "."));
    oss1 << ip1.back();

    cout << endl << "Die 1. IP-Adresse lautet: " << oss1.str() << endl;

    ostringstream oss2;
    copy(ip2.begin(), ip2.end() - 1, ostream_iterator<int>(oss2, "."));
    oss2 << ip2.back();

    cout << "Die 2. IP-Adresse lautet: " << oss2.str() << endl;
}
#include <iostream>
#include "Schaltjahr.h"

using namespace std;

bool istSchaltjahr(int year)
{
    return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
}

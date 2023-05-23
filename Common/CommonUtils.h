#pragma once

std::string vectorToString(std::vector<int> values, int width = 0);
bool isLeapYear(int year);
int getDayCountOfMonth(int month, int year);
bool isDateValid(int day, int month, int year);
std::string getDayAsString(int dayIndex);
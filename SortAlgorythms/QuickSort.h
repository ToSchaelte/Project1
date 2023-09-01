#pragma once

class QuickSort
{
public:
	static void sort(int a[], int arraySize);
private:
	static void sort(int a[], int left, int right);
	static void printRun(int a[]);
};
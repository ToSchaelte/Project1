#include <iostream>
#include <fstream>
#include "List.h"

#pragma region Helper functions

void read(std::string filename, List &list)
{
	std::ifstream reader;
	std::string loadedFile;
	reader.open(filename, std::ios::in);

	if (reader)
	{
		while (!reader.eof())
		{
			Student *student = new Student();
			reader >> student->id;
			reader >> student->last_name;
			reader >> student->first_name;
			list.add(student);
		}
		reader.close();
	}
}

void write(std::string filename, List &list)
{
	std::ofstream writer;
	writer.open(filename, std::ios::out);

	if (writer)
	{
		list.moveFirst();
		auto currentItem = list.getCurrentItem();
		while (currentItem->getNextItem() != nullptr)
		{
			currentItem = list.getCurrentItem();
			writer
				<< currentItem->value->id << "\n"
				<< currentItem->value->first_name << "\n"
				<< currentItem->value->last_name
				<< (currentItem->getNextItem() != nullptr ? "\n" : "");
			list.moveNext();
		}
		writer.close();
	}
}

void static swap(List &l, int i, int j)
{
	auto first = l.getItem(i);
	auto second = l.getItem(j);
	if (first == nullptr || second == nullptr) return;
	auto firstNext = first->getNextItem();
	auto firstPrev = first->getPrevItem();
	auto secondNext = second->getNextItem();
	auto secondPrev = second->getPrevItem();

	if (first == secondPrev)
	{
		first->setPrevItem(second);
		first->setNextItem(secondNext);
		if (secondNext != nullptr) secondNext->setPrevItem(first);
		second->setNextItem(first);
		second->setPrevItem(firstPrev);
		if (firstPrev != nullptr) firstPrev->setNextItem(second);
		return;
	}
	else if (first == secondNext)
	{
		first->setNextItem(second);
		first->setPrevItem(secondPrev);
		if (secondPrev != nullptr) secondPrev->setNextItem(first);
		second->setPrevItem(first);
		second->setNextItem(firstNext);
		if (firstNext != nullptr) firstNext->setPrevItem(second);
		return;
	}

	first->setNextItem(secondNext);
	first->setPrevItem(secondPrev);
	second->setNextItem(firstNext);
	second->setPrevItem(firstPrev);
	firstPrev = first->getPrevItem();
	if (firstPrev != nullptr) firstPrev->setNextItem(first);
	firstNext = first->getNextItem();
	if (firstNext != nullptr) firstNext->setPrevItem(first);
	secondPrev = second->getPrevItem();
	if (secondPrev != nullptr) secondPrev->setNextItem(second);
	secondNext = second->getNextItem();
	if (secondNext != nullptr) secondNext->setPrevItem(second);
}

static void sort(List &l, int left, int right)
{
	if (left >= right) return;
	int i = left;
	for (int j = left; j < right; ++j)
		if (l.getValue(j)->id < l.getValue(right)->id) swap(l, i++, j);
	swap(l, i, right);
	sort(l, left, i - 1);
	sort(l, i + 1, right);
}

static void sort(List &l)
{
	sort(l, 0, l.count() - 1);
}

static void writeList(List& list)
{
	list.moveFirst();
	auto currentItem = list.getCurrentItem();
	while (currentItem->getNextItem() != nullptr)
	{
		currentItem = list.getCurrentItem();
		std::cout << currentItem->value->id << " " << currentItem->value->first_name << " " << currentItem->value->last_name << "\n";
		list.moveNext();
	}
}

#pragma endregion

int main()
{
	std::cout << "Filepath of txt file: ";
	std::string path = "C:/Users/Tobias.Schaelte/Desktop/VornamenslisteITB26.txt";
	std::cin >> path;
	auto list = List();
	read(path, list);

	std::cout << "\n\n\The following data has been loaded:\n";

	auto currentItem = list.getCurrentItem();
	writeList(list);

	while (true)
	{
		std::cout << "\n\nWhat do you want to do?\n0: save & exit\n1: sort\n2: delete\n";
		int input;
		std::cin >> input;
		switch (input)
		{
		case 0:
			write(path, list);
			return 0;
		case 1:
			sort(list);
			std::cout << "\n\n\nSorted:\n";
			writeList(list);
			break;
		case 2:
			std::cout << "Which name do you want to delete? ";
			std::string name;
			std::cin >> name;
			
			list.moveFirst();
			auto currentItem = list.getCurrentItem();
			while (currentItem->getNextItem() != nullptr)
			{
				currentItem = list.getCurrentItem();
				if (name == currentItem->value->first_name || name == currentItem->value->last_name)
				{
					list.remove(currentItem);
					break;
				}
				list.moveNext();
			}

			std::cout << "\n\n\nUpdated list:\n";
			writeList(list);
			break;
		}
	}
}
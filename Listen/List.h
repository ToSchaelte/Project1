#pragma once

#include "ListItem.h"
#include "Student.h"

class List
{
public:
	List();
	~List();
	Student* getValue(int);
	ListItem* getItem(int);
	size_t count();
	void add(Student*);
	void add(ListItem*);
	void insert(ListItem*, int);
	void remove(int);
	void remove(ListItem*);
	ListItem* getCurrentItem();
	void moveNext();
	void moveLast();
	void movePrev();
	void moveFirst();

private:
	ListItem* currentItem;
};
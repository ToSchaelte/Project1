#pragma once
#include "Student.h"

class ListItem
{
public:
	ListItem(Student*);
	~ListItem();
	ListItem* getNextItem();
	ListItem* getPrevItem();
	void setNextItem(ListItem*);
	void setPrevItem(ListItem*);
	Student* value;

private:
	ListItem* nextItem;
	ListItem* prevItem;
};
#include "ListItem.h"

ListItem::ListItem(Student* value)
{
	this->value = value;
	nextItem = nullptr;
	prevItem = nullptr;
}

ListItem::~ListItem()
{
	delete value;
}

ListItem* ListItem::getNextItem()
{
	if (this == nullptr) return nullptr;
	return nextItem;
}

ListItem* ListItem::getPrevItem()
{
	if (this == nullptr) return nullptr;
	return prevItem;
}

void ListItem::setNextItem(ListItem* item)
{
	nextItem = item;
}

void ListItem::setPrevItem(ListItem* item)
{
	prevItem = item;
}

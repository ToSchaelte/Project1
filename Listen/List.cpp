#include "List.h"

List::List()
{
	currentItem = nullptr;
}

Student* List::getValue(int index)
{
	return getItem(index)->value;
}

ListItem* List::getItem(int index)
{
	if (nullptr == currentItem) return nullptr;
	if (index < 0) return getItem(0);
	auto iterator = currentItem;
	while (iterator->getPrevItem() != nullptr)
	{
		iterator = iterator->getPrevItem();
	}

	for (size_t i = 0; i < index && iterator->getNextItem() != nullptr; i++)
	{
		iterator = iterator->getNextItem();
	}
	return iterator;
}

size_t List::count()
{
	if (nullptr == currentItem) return 0;
	auto iterator = getItem(0);
	size_t i = 1;
	while (nullptr != iterator->getNextItem())
	{
		iterator = iterator->getNextItem();
		++i;
	}
	return i;
}

void List::add(Student* student)
{
	add(new ListItem(student));
}

void List::add(ListItem* item)
{
	if (nullptr == currentItem)
	{
		currentItem = item;
		return;
	}
	auto iterator = currentItem;
	while (iterator->getNextItem() != nullptr)
	{
		iterator = iterator->getNextItem();
	}
	iterator->setNextItem(item);
	item->setPrevItem(iterator);
}

void List::insert(ListItem* item, int index)
{
	if (index <= 0)
	{
		auto iterator = getItem(0);
		item->setNextItem(iterator);
		item->setPrevItem(nullptr);
		iterator->setPrevItem(iterator);
		return;
	}
	if (index >= count() - 1) add(item);

	auto bef = getItem(index - 1);
	auto af = bef->getNextItem();

	bef->setNextItem(item);
	item->setPrevItem(bef);
	af->setPrevItem(item);
	item->setNextItem(af);
}

void List::remove(int i)
{
	remove(getItem(i));
}

void List::remove(ListItem* item)
{
	auto prevItem = item->getPrevItem();
	auto nextItem = item->getNextItem();
	if (currentItem == item)
	{
		if (prevItem != nullptr) currentItem = prevItem;
		else if (nextItem != nullptr) currentItem = nextItem;
		else currentItem = nullptr;
	}
	if (prevItem != nullptr) prevItem->setNextItem(nextItem);
	if (nextItem != nullptr) nextItem->setPrevItem(prevItem);
	delete item;
}

ListItem* List::getCurrentItem()
{
	return currentItem;
}

void List::moveNext()
{
	if (nullptr == currentItem || nullptr == currentItem->getNextItem()) return;
	currentItem = currentItem->getNextItem();
}

void List::moveLast()
{
	currentItem = getItem(count() - 1);
}

void List::movePrev()
{
	if (nullptr == currentItem || nullptr == currentItem->getPrevItem()) return;
	currentItem = currentItem->getPrevItem();
}

void List::moveFirst()
{
	currentItem = getItem(0);
}

List::~List()
{
	auto iterator = getItem(0);
	while (iterator->getNextItem() != nullptr)
	{
		iterator = iterator->getNextItem();
		delete iterator->getPrevItem();
	}
	delete iterator;
}

#pragma once
#include "ListItemLab7.h"
#include "Operators.h"

template <class Type>
class List
{
private:
	ListItem<Type>* _head = nullptr;
	ListItem<Type>* _tail = nullptr;
	int _count = NULL;
public:
	void Add(Type data);
	void RemoveAt(int index);
	int GetCount();
	void Show();
	friend std::ostream& operator<<(std::ostream& os, List<Type>& list)
	{
		ListItem<Type>* temp = list._head;
		cout << "Sub-listings: ";
		while (temp != nullptr)
		{
			cout << temp->GetData() << "  ";
			temp = temp->Next;
		}
		return os;
	}

};

template <class Type>
void List<Type>::Add(Type data)
{
	ListItem<Type>* newItem = new ListItem<Type>(data);
	if (_head != nullptr)
	{
		_tail->Next = newItem;
		newItem->Prev = _tail;
		_tail = newItem;
		_count++;
		return;
	}
	else
	{
		_head = newItem;
		_tail = newItem;
		_count++;
		return;
	}
}

template <class Type>
void List<Type>::Show()
{
	ListItem<Type>* newItem = _head;
	newItem = _head;
	if (GetCount() == 0)
	{
		cout.width(12); cout << "\n\nLIST IS EMPTY\n";
		return;
	}
	while (newItem != nullptr)
	{
		cout << newItem->GetData() << '\n' ;
		newItem = newItem->Next;
	}
	cout << endl;
}

template <class Type>
void List<Type>::RemoveAt(int index)
{
	if (GetCount() == 0)
	{
		cout.width(12); cout << "\n\nLIST IS EMPTY\n";
		return;
	}
	if (GetCount() <= index)
	{
		cout << "\nIndex not found\n";
		return;
	}
	ListItem<Type>* newItem = _head;
	int indexItem = 0;
	if (GetCount() == (index + 1))
	{
		ListItem<Type>* tmp = _tail->Prev;
		delete _tail;
		_tail = tmp;
		_tail->Next = nullptr;
		_count--;
		return;
	}
	while (newItem != nullptr)
	{
		if (index == indexItem)
		{
			newItem->Prev->Next = newItem->Next;
			newItem->Next->Prev = newItem->Prev;
			delete newItem;
			_count--;
			cout << "\nMan is delete\n";
			return;
		}
		indexItem++;
		newItem = newItem->Next;
	}
	cout << "\nIndex not found";
}

template <class Type>
int List<Type>::GetCount()
{
	return _count;
}


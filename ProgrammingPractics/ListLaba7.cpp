#include "stdafx.h"
#include "ListLab7.h"

//template <class Type>
//void List<Type>::Add(Type data)
//{
//	ListItem<Type>* newItem = new ListItem<Type>(data);
//	if (_head != nullptr)
//	{
//		_tail->Next = newItem;
//		newItem->Prev = _tail;
//		_tail = newItem;
//		_count++;
//		cout << "\nPress any key to continue working\n";
//		char key = _getch();
//		return;
//	}
//	else
//	{
//		_head = newItem;
//		_tail = newItem;
//		_count++;
//		cout << "\nPress any key to continue working\n";
//		char key = _getch();
//		return;
//	}
//}
//
//
//template <class Type>
//void List<Type>::Show()
//{
//	ListItem<Type>* newItem = _head;
//	newItem = _head;
//	if (GetCount() == 0)
//	{
//		cout.width(12); cout << "\n\nLIST IS EMPTY\n";
//		return;
//	}
//	while (newItem != nullptr)
//	{
//		cout.width(12); cout << newItem->GetValue()->GetSurname();
//		cout.width(12); cout << newItem->GetValue()->GetName();
//		cout.width(12); cout << newItem->GetValue()->GetAge();
//		cout.width(12);
//		newItem = newItem->Next;
//		cout << endl;
//	}
//	cout << endl;
//}
//

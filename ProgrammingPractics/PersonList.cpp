#include "stdafx.h"
#include "PersonList.h"
#include "CheckNameSurname.h"
#include "ToolsForLabs.h"


namespace lab5
{	
	PersonListItem* PersonList::GetHead()
	{
		return _head;
	}

	PersonListItem* PersonList::GetTail()
	{
		return _tail;
	}

	void PersonList::SetCountList()
	{
		_count++;
	}

	void PersonList::Add(Person* person)
	{	
		PersonListItem* newItem = new PersonListItem(person);
		if (_head != nullptr)
		{
			_tail->Next = newItem;
			newItem->Prev = _tail;
			_tail = newItem;
			_count++;
			cout << "\nPress any key to continue working\n";
			char key = _getch();
			return;
		}
		else
		{
			_head = newItem;
			_tail = newItem;
			_count++;
			cout << "\nPress any key to continue working\n";
			char key = _getch();
			return;
		}
	}

	Person* PersonList::Find(int index)
	{	
		while (GetCount() != 0 && index <= _count)
		{
			PersonListItem* newItem = _head;
			int indexItem = 1;
			while (newItem != nullptr)
			{
				if (index == indexItem)
				{
					return newItem->GetValue();
				}
				newItem = newItem->Next;
				indexItem++;
			}
			cout << "\nIndex not found";
		}
		cout << "\nLIST EMPTY! or index is greater than the maximum index of the list\n";
	}

	int PersonList::IndexOf()
	{
		while (GetCount() != 0)
		{
			PersonListItem* newItem = _head;
			string name; string surname;
			cout << "\nWho u want find?\n";
			cout << "Name\n>"; cin >> name;
			cout << "Surname\n>"; cin >> surname;
			if (CheckNameSurname(name, surname) == 0)
			{
				cout << "\nPress any key to continue working\n";
				char key = _getch();
				return NULL;
			}
			int indexItem = 0;
			while (newItem != nullptr)
			{
				if (name == newItem->GetValue()->GetName() && surname == newItem->GetValue()->GetSurname())
				{
					return indexItem;
				}
				indexItem++;
				newItem = newItem->Next;
			}
			cout << "\nMan not found\n"; 
			return NULL;
		}
		cout << "\nLIST IS EMPTY!\n";
	}
	void PersonList::Remove(Person* person)
	{
		if (GetCount() == 0)
		{
			cout.width(12); cout << "\n\nLIST IS EMPTY\n";
			return;
		}
		string name; string surname;
		cout << "\nWho u want delete?\n";
		cout << "Name\n>"; cin >> name;
		cout << "Surname\n>"; cin >> surname;
		PersonListItem* newItem = _head;

		if ((name == _head->GetValue()->GetName()) && (surname == _head->GetValue()->GetSurname()))
		{
			PersonListItem* tmp = _head->Next;
			delete _head;
			_head = tmp;
			_count--;
			return;
		}

		if (name == _tail->GetValue()->GetName() && surname == _tail->GetValue()->GetSurname())
		{
			PersonListItem* tmp = _tail->Prev;
			delete _tail;
			_tail = tmp;
			_tail->Next = nullptr;
			_count--;
			return;
		}
		while (newItem != nullptr)
		{
			if ((name == newItem->GetValue()->GetName()) && (surname == newItem->GetValue()->GetSurname()))
			{
				newItem->Prev->Next = newItem->Next;
				newItem->Next->Prev = newItem->Prev;
				delete newItem;
				cout << "\nMan is delete\n";
				_count--;
				return;
			}
			newItem = newItem->Next;
		}
		cout << "\nMan not found";
	}

	void PersonList::RemoveAt(int index)
	{
		if (GetCount() == 0)
		{
			cout.width(12); cout << "\n\nLIST IS EMPTY\n";
			return;
		}
		PersonListItem* newItem = _head;
		int indexItem = 0;
		while (newItem != nullptr)
		{
			if (index == indexItem)
			{
				newItem->Next->Prev = newItem->Prev->Next;
				newItem = nullptr;
				cout << "\nMan is delete\n";
				return;
			}
			indexItem++;
		}
		cout << "\nIndex not found";
	}

	void PersonList::Clear()
	{
		if (GetCount() == 0)
		{
			cout.width(12); cout << "\n\nLIST IS EMPTY\n";
			return;
		}
		PersonListItem* newItem = _head->Next;
		if (_count == 1)
		{
			delete newItem;
			_count = 0;
			_head = nullptr;
			_tail = nullptr;
			return;
		}
		while (newItem != _tail)
		{
			newItem->Prev->Next = newItem->Next;
			newItem->Next->Prev = newItem->Prev;
			newItem = newItem->Next;
		}
		_count = 0;
		_head = nullptr;
		_tail = nullptr;
	}

	int PersonList::GetCount()
	{
		return _count;
	}

	void PersonList::Show()
	{
		PersonListItem* newItem = _head;
		newItem = _head;
		if (GetCount() == 0)
		{
			cout.width(12); cout << "\n\nLIST IS EMPTY\n";
			return;
		}
		while (newItem != nullptr)
		{
			cout.width(12); cout << newItem->GetValue()->GetSurname();
			cout.width(12); cout << newItem->GetValue()->GetName();
			cout.width(12); cout << newItem->GetValue()->GetAge();
			cout.width(12);
			newItem = newItem->Next;
			cout << endl;
		}
		cout << endl;
	}

	void PersonList::ShowDescriptions()
	{
		PersonListItem* temp = _head;

		if (temp)
		{
			cout << "\n\nPersons:\n";
			while (temp)
			{
				if (temp->GetValue()->GetAge() < 18)
				{
					lab6::Child* child = (lab6::Child*)temp->GetValue();
				}
				else
				{
					lab6::Adult* adult = (lab6::Adult*)temp->GetValue();
					cout << adult->GetDescription() << endl;
				}
				temp = temp->Next;
			}
		}
		else
		{
			cout << "No person found\n";
		}
		cout << endl;
	}

	PersonList::PersonList() 
	{

	}

	PersonList::~PersonList()
	{
		Clear();
	}
}

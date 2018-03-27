#include "stdafx.h"
//TODO: Зачем этот файл? \DONE	
#include "PersonList.h"


namespace lab5
{
	void PersonList::Add(Person& person)
	{
		string name;
		string surname;
		PersonListItem* newItem = new PersonListItem(person);
		if (_head != NULL)
		{
			_tail->Next = newItem;
			_tail = newItem;
			_tail->Next = NULL;
			cout << "\nPlease enter name and surname (ex. \"Jack Bauer\"):\n>";
			cin >> name; cin >> surname;
			if ((name[0] >= 'A' && name[0] <= 'Z') || (surname[0] >= 'A' && surname[0] <= 'Z'))
			{
				newItem->Value.Name = name;
				newItem->Value.Surname = surname;
				_count++;
				return;
			}
			cout << "\nEnter first and last name with a capital letter!\n";
			cout << "\nPress any key to continue working\n";
			char key = _getch();
			return;
		}
		else
		{
			cout << "\nPlease enter name and surname (ex. \"Jack Bauer\"):\n>";
			cin >> name; cin >> surname;
			if ((!name[0] >= 'A' && !name[0] <= 'Z') || (surname[0] >= 'A' && surname[0] <= 'Z'))
			{
				_head = newItem;
				_tail = newItem;
				_count++;
			}
			cout << "\nEnter first and last name with a capital letter!\n";
			cout << "\nPress any key to continue working\n";
			char key = _getch();
			return;
		}
	}

	Person& PersonList::Find(int index)
	{	
		while (GetCount() != 0 && index <= _count)
		{
			PersonListItem* newItem = _head;
			int indexItem = 1;
			while (newItem != NULL)
			{
				if (index == indexItem)
				{
					return newItem->Value;
				}
				newItem = newItem->Next;
				indexItem++;
			}
			cout << "\nIndex not found";
		}
		cout << "\nLIST EMPTY! or index is greater than the maximum index of the list\n";
	}

	int PersonList::IndexOf(Person& person)
	{
		while (GetCount() != 0)
		{
			PersonListItem* newItem = _head;
			string name; string surname;
			cout << "\nWho u want find?\n";
			cout << "Name\n>"; cin >> name;
			cout << "Surname\n>"; cin >> surname;
			int indexItem = 0;
			while (newItem != NULL)
			{
				if (name == newItem->Value.Name && surname == newItem->Value.Surname)
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
	void PersonList::Remove(Person& person)
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

		if (name == _head->Value.Name && surname == _head->Value.Surname)
		{
			PersonListItem* tmp = _head->Next;
			delete _head;
			_head = tmp;
			_count--;
			return;
		}

		if (name == _tail->Value.Name && surname == _tail->Value.Surname)
		{
			PersonListItem* tmp = _tail->Prev;
			delete _tail;
			_tail = tmp;
			_tail->Next = NULL;
			_count--;
			return;
		}
		while (newItem != NULL)
		{
			if (name == newItem->Value.Name && surname == newItem->Value.Surname)
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
		while (newItem != NULL)
		{
			if (index == indexItem)
			{
				newItem->Next->Prev = newItem->Prev->Next;
				newItem = NULL;
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
		PersonListItem* newItem = _head;
		while (newItem != _tail)
		{
			newItem->Prev->Next = newItem->Next;
			newItem->Next->Prev = newItem->Prev;
			newItem = newItem->Next;
			delete newItem;
		}
		_head = NULL;
		_tail = NULL;
	}

	int PersonList::GetCount()
	{
		return _count;
	}

	void PersonList::Show(Person& person)
	{
		PersonListItem* newItem = _head;
		newItem = _head;
		if (GetCount() == 0)
		{
			cout.width(12); cout << "\n\nLIST IS EMPTY\n";
			return;
		}
		while (newItem != NULL)
		{
			cout.width(12); cout << newItem->Value.Surname;
			cout.width(12); cout << newItem->Value.Name;
			cout.width(12);
			newItem = newItem->Next;
			cout << endl;
		}
		cout << endl;
	}

	Person PersonList::MakeRandomPerson()
	{
		Person newPerson;
		string MaleName[] =
		{
			"Igor", "Semen", "Alexander", "Slavyan", "Mirey",
			"Andrey", "Boris", "Bogdan", "Vadim", "Vladimir",
			"Alexey", "Anatoliy", "Vasiliy", "Georgiy", "Genadiy"
		};

		string MaleSurname[] =
		{
			"Borozdin", "Ivanov", "Renev", "Isanov", "Ahanov",
			"Sobolev", "Morozov", "Almazov", "Derzhavin", "Bogatirev",
			"Lyubimov", "Voroncov", "Admiralov", "Mayorov", "Gromov"
		};

		string FemaleName[] =
		{
			"Yuliya", "Olya", "Viktoriya", "ELizaveta", "Lana",
			"Anastasiya", "Mariya", "Ekaterina", "Angelina", "Sof'ya"
			"Anna", "Varvara", "Irina", "Tat'yana", "Kristina"
		};

		string FemaleSurname[] =
		{
			"Kudryavceva", "Evsyukova", "Morozova", "Rukosueva", "Polienko",
			"Mayer", "Vladova", "Evans", "Brown", "Weber",
			"Sokolovskaya", "Ellis", "Lemann", "Lewandovskaya", "Smith"
		};

		switch (rand() % 2 + 1)
		{
			case 1:
			{
				newPerson.Name = MaleName[rand() % 15];
				newPerson.Surname = MaleSurname[rand() % 15];
				break;
			}
			case 2:
			{
				newPerson.Name = FemaleName[rand() % 15];
				newPerson.Surname = FemaleSurname[rand() % 15];
				break;
			}
			default:
				break;
		}
		return newPerson;
	}

	void PersonList::AddForRandomPerson(Person& person)
	{
		PersonListItem* newItem = new PersonListItem(person);
		newItem->Next = NULL;
		newItem->Value = MakeRandomPerson();
		//TODO: Не нужно оставлять такие комментарии! \ DONE
		if (_head != NULL)
		{
			newItem->Prev = _tail; 
			_tail->Next = newItem; 
			_tail = newItem;
			_count++;
		}
		else
		{
			newItem->Prev = NULL;
			_head = newItem;
			_tail = newItem;
			_count++;
		}
	}

	void PersonList::MenuForClass(Person& person)
	{
		HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
		const char escapeSymbol = 27;
		char key;
		int temp = 1;
		int numberCase;
		int asciiValue = 0;
		PersonList p1;
		while (asciiValue != escapeSymbol)
		{
			system("cls");

			SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
			cout.width(12); cout << "Surname:";
			cout.width(12); cout << "Name: \n";

			SetConsoleTextAttribute(hStdOut, 2);
			p1.Show(person);

			SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			cout << "\n------List of Person: Main Menu------"
				<< "\n1. Add Person"
				<< "\n2. Find a person at the specified index"
				<< "\n3. Return the index of the person, if it is in the list"
				<< "\n4. Remove a person from the list"
				<< "\n5. Remove a person from the list by index"
				<< "\n6. Clear List"
				<< "\n7. Get the number of items"
				<< "\n------List of Person : Main Menu------";

			SetConsoleTextAttribute(hStdOut, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			cout << "\n\n\nChoose action (1-7):\n>";

			key = _getch();
			asciiValue = key;
			switch (asciiValue)
			{
				case '1':
				{
					p1.Add(person);
					cout << "\nPerson added\n";
					break;
				}
				case '2':
				{
					int index;
					cout << "\nInsert index:\n>";
					cin >> index;
					PersonListItem tmp = p1.Find(index);
					cout << "\nName:\n>";
					cout << tmp.Value.Name;
					cout << "\nSurname:\n>";
					cout << tmp.Value.Surname;
					cout << "\nPress any key to continue working\n";
					key = _getch();
					break;
				}
				case '3':
				{
					cout << p1.IndexOf(person);
					cout << "\nPress any key to continue working\n";
					key = _getch();
					break;
				}
				case '4':
				{
					int index;
					p1.Remove(person);
					cout << "\nPress any key to continue working\n";
					key = _getch();
					break;
				}
				case '5':
				{
					int index;
					cout << "\nInsert index:\n>";
					cin >> index;
					p1.RemoveAt(index);
					cout << "\nPress any key to continue working\n";
					key = _getch();
					break;
				}
				case '6':
				{
					p1.Clear();
					cout << "\nList is empty";
					cout << "\nPress any key to continue working\n";
					key = _getch();
					break;
				}
				case '7':
				{
					cout << p1.GetCount();
					cout << "\nPress any key to continue working\n";
					key = _getch();
					break;
				}
				case '8':
				{
					p1.AddForRandomPerson(person);
					cout << "\nPress any key to continue working\n";
					key = _getch();
					break;
				}
			}
		}
	}
}

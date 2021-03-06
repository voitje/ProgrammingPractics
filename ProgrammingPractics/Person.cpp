#include "stdafx.h"
#include "List.h"
#include "FunctionsLab4.h"
#include "ToolsForLabs.h"

namespace lab4
{
	Person ReadPerson()
	{
		Person newPerson;
		cout << "\nPlease enter name and surname (ex. \"Jack Bauer\"):\n>";
		cin >> newPerson.Name; cin >> newPerson.Surname;
		cout << "\nInsert Sex - Male(M)/Female(F):\n>";

		const char escapeSymbol = 27;
		int asciiValue = 0;
		char key = _getch();
		asciiValue = key;
		char newKey = key;
		while ((key != 'f') && (key != 'm'))
		{
			cout << ("\nINCORRECT SYMBOL!!!\nPlease, enter (Button 'f' or Button 'm'):\n>");
			newKey = _getch();
			key = newKey;
		}
		asciiValue = newKey;
		switch (asciiValue)
		{
			case 'f':
			{
				cout << 'F';
				newPerson.Gender = Female;
				break;
			}
			case 'm':
			{
				cout << 'M';
				newPerson.Gender = Male;
				break;
			}
			default:
				break;
		}
		return newPerson;

	}

	void PrintPerson(Person& person)
	{
		cout << "\n\nSurname: " << person.Surname << endl;
		cout << "\nName: " << person.Name << endl;
		switch (person.Gender)
		{
			case Male:
				cout << "\nSexPerson: " << "Male" << endl;
				break;
			case Female:
				cout << "\nSexPerson: " << "Female" << endl;
				break;
		}
	}

	void Create(List* list)
	{
		Node *newNode = new Node();
		newNode->PrevItem = NULL;
		newNode->NextItem = NULL;
		list->Head = NULL;
		list->Tail = NULL;
	}

	void Add(List* list)
	{
		Node *newNode = new Node();
		newNode->NextItem = NULL;
		newNode->Person = ReadPerson();
		if (list->Head != NULL)
		{
			newNode->PrevItem = list->Tail;
			list->Tail->NextItem = newNode;
			list->Tail = newNode;
			newNode->Index = newNode->PrevItem->Index + 1;
		}
		else
		{
			newNode->PrevItem = NULL;
			list->Head = newNode; list->Tail = newNode;
			newNode->Index = 0;
		}
	};

	void Show(List* list)
	{
		Node *newNode = list->Tail;
		newNode = list->Head; 
		while (newNode != NULL)
		{
			cout.width(12); cout << newNode->Index;
			cout.width(12); cout << newNode->Person.Surname;
			cout.width(12); cout << newNode->Person.Name;
			cout.width(12);
			switch (newNode->Person.Gender)
			{
				case 0:
					cout << "Male";
					break;
				case 1:
					cout << "Female";
					break;
			}
			newNode = newNode->NextItem; 
			cout << endl;
		}
		cout << endl;
	}
	
	Node* GetPointer(List* list, int index)
	{
		Node *newNode = list->Head;
		char key = _getch();
		int asciiValue = key;
		char newKey = key;
		if (IsEmpty(list) == true)
		{
			PrintEmptyList();
			return NULL;
		}
		if (index < 0)
		{
			while ((key != 'e'))
			{
				cout << ("\nINCORRECT SYMBOL!!!\nPlease, enter E for exit (index only from 0 to infinity):\n>");
				newKey = _getch();
				key = newKey;
			}
			return NULL;
		}
		if (index == newNode->Index)
		{
			cout << "Link on element:\n";
			return newNode;
		}

		newNode = newNode->NextItem;
	}

	void CopyConstString(char* string1, const char* string2)
	{
		int i = 0;
		for (; string2[i]; i++)
		{
			string1[i] = string2[i];
		}
		string1[i] = '\0';
	}

	void AddRandomPerson(List* list)
	{
		Node *newNode = new Node();
		newNode->NextItem = NULL;
		newNode->Person = GetRandomPerson();
		if (list->Head != NULL)
		{
			newNode->PrevItem = list->Tail;
			list->Tail->NextItem = newNode;
			list->Tail = newNode;
			newNode->Index = newNode->PrevItem->Index + 1;
		}
		else
		{
			newNode->PrevItem = NULL;
			list->Head = newNode; list->Tail = newNode;
			newNode->Index = 0;
		}
	}

	void Remove(List* list, int index)
	{
		Node *newNode = list->Head;
		int newIndex;
		if (IsEmpty(list))
		{
			char key = _getch();
			PrintEmptyList();
			return;
		}
		if (index < 0)
		{
			char key = _getch();
			int asciiValue = key;
			char newKey = key;
			while ((key != 'e'))
			{
				cout << ("\nINCORRECT SYMBOL!!!\nPlease, enter E for exit (index only from 0 to infinity):\n>");
				newKey = _getch();
				key = newKey;
			}
			return;
		}
		if (index > list->Tail->Index || index < list->Head->Index)
		{
			while ((index > list->Tail->Index) || (index < list->Head->Index))
			{
				cout << "\nINCORRECT SYMBOL!!!\nPlease, enter index index from 0 to " << list->Tail->Index << ":\n>";
				cin >> newIndex;
				index = newIndex;
			}
		}
		while (index != newNode->Index)
		{
			newNode = newNode->NextItem;
		}
		newNode->PrevItem->NextItem = newNode->NextItem;
		newNode->NextItem->PrevItem = newNode->PrevItem;
		delete newNode;
	}

	void Insert(List* list, Person& person, int index)
	{
		Node *newNode = list->Head;
		int i = 0;
		int newIndex;
		char key = _getch();
		int asciiValue = key;
		char newKey = key;
		if (IsEmpty(list) == true)
		{
			PrintEmptyList();
			return;
		}
		if (index > list->Tail->Index || index < list->Head->Index)
		{
			while ((index > list->Tail->Index) || (index < list->Head->Index))
			{
				cout << "\nINCORRECT SYMBOL!!!\nPlease, enter index index from 0 to " << list->Tail->Index << ":\n>";
				cin >> newIndex;
				index = newIndex;
			}
		}
		while (index != newNode->Index)
		{
			i++;
			newNode = newNode->NextItem;
		}
		newNode->Person = person;
		newNode->Index = i;
	}

	void ClearList(List* list)
	{
		if (list->Head == NULL && list->Tail == NULL)
		{
			char key = _getch();
			int asciiValue = key;
			char newKey = key;
			while ((key != 'e'))
			{
				PrintEmptyList();
			}
			return;
		}
		Node* newNode = list->Head;
		int i = 1;
		while (i != list->Tail->Index)
		{
			Remove(list, i);
			i++;
		}
		list->Head = NULL;
		list->Tail = NULL;
	}

	bool IsEmpty(List* list)
	{
		if (list->Head == NULL && list->Tail == NULL)
		{
			return 1;
		}
		return 0;
	}
}

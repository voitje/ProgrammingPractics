#include "stdafx.h"
#include "Person.h"
#include "Sex.h"

Person ReadPerson()
{
	Person newPerson;
	cout << "\nPlease enter name and surname (ex. “Jack Bauer”):\n>";
	cin >> newPerson.Name; cin >> newPerson.Surname;
	cout << "\nInsert Sex - Male(M)/Female(F):\n>";
	int n;
	char key = NULL;
	const char escapeSymbol = 27;
	int asciiValue = 0;
	key = _getch();
	asciiValue = key;
	char newKey = key;
	while ((key != 'f') && (key != 'm'))
	{
		cout << ("\nINCORRECT SYMBOL!!!\nPlease, enter (Button 'F' or Button 'M'):\n>");
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
		case 0:
			cout << "\nSexPerson: " << "Male" << endl;
			break;
		case 1:
			cout << "\nSexPerson: " << "Female" << endl;
			break;
	}
}

void Create(List* list)
{
	Node *newNode = new Node();
	newNode->prevItem = nullptr;
	newNode->nextItem = nullptr;
	list->head = nullptr;
	list->tail = nullptr;
	list->count = NULL;
}

void Add(List* list)
{
	Node *newNode = new Node(); 
	newNode->nextItem = nullptr;  
	newNode->Person = ReadPerson();
	if (list->head != nullptr)
	{
		newNode->prevItem = list->tail; 
		list->tail->nextItem = newNode; 
		list->tail = newNode; 
		newNode->Person.index = newNode->prevItem->Person.index + 1;
	}
	else 
	{
		newNode->prevItem = nullptr;
		list->head = newNode; list->tail = newNode;
		newNode->Person.index = 0;
	}
};

void Show(List* list)
{
	Node *newNode = list->tail;
	newNode = list->head;
	while (newNode != nullptr)
	{	
		cout.width(12); cout << newNode->Person.index;
		cout.width(12); cout << newNode->Person.Surname ;
		cout.width(12); cout << newNode->Person.Name ;
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
		newNode = newNode->nextItem;
		cout << endl;
	}
	cout << endl;
}

Person& GetPointer(List* list, int index)
{
	Node *newNode = list->head;
	if (index == newNode->Person.index)
	{
		return newNode->Person;
	}
	newNode = newNode->nextItem;
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
Person MakeRandomPerson()
{	
	Person newPerson;
	const char* MaleName[] =
	{
		"Igor", "Semen", "Alexander", "Slavyan", "Mirey",
		"Andrey", "Boris", "Bogdan", "Vadim", "Vladimir",
		"Alexey", "Anatoliy", "Vasiliy", "Georgiy", "Genadiy"
	};

	const char* MaleSurname[] =
	{
		"Borozdin", "Ivanov", "Renev", "Isanov", "Ahanov",
		"Sobolev", "Morozov", "Almazov", "Derzhavin", "Bogatirev",
		"Lyubimov", "Voroncov", "Admiralov", "Mayorov", "Gromov"
	};

	const char* FemaleName[] = 
	{ 
		"Yuliya", "Olya", "Viktoriya", "ELizaveta", "Lana",
		"Anastasiya", "Mariya", "Ekaterina", "Angelina", "Sof'ya"
		"Anna", "Varvara", "Irina", "Tat'yana", "Kristina"
	};

	const char* FemaleSurname[] = 
	{ 
		"Kudryavceva", "Evsyukova", "Morozova", "Rukosueva", "Polienko",
		"Mayer", "Vladova", "Evans", "Brown", "Weber", 
		"Sokolovskaya", "Ellis", "Lemann", "Lewandovskaya", "Smith"
	};

	cout << "\nInsert Sex - Male(M)/Female(F):\n> ";
	char key = _getch();
	int asciiValue = key;
	char newKey = key;
	while ((key != 'f') && (key != 'm'))
	{
		cout << ("\nINCORRECT SYMBOL!!!\nPlease, enter (Button 'F' or Button 'M'):\n>");
		newKey = _getch();
		key = newKey;
	}
	asciiValue = newKey;
		switch (asciiValue)
		{
			case 'f':
			{
				CopyConstString(newPerson.Name, FemaleName[rand() % 15]);
				CopyConstString(newPerson.Surname, FemaleSurname[rand() % 15]);
				newPerson.Gender = Female;
				break;
			}
			case 'm':
			{
				CopyConstString(newPerson.Name, MaleName[rand() % 15]);
				CopyConstString(newPerson.Surname, MaleSurname[rand() % 15]);
				newPerson.Gender = Male;
				break;
			}
			default:
				break;
		}
	return newPerson;
}

void AddForRandomPerson(List* list)
{
	Node *newNode = new Node(); 
	newNode->nextItem = nullptr;  
	newNode->Person = MakeRandomPerson();
	list->count++;
	if (list->head != nullptr)
	{
		newNode->prevItem = list->tail; 
		list->tail->nextItem = newNode; 
		list->tail = newNode; 
		newNode->Person.index = newNode->prevItem->Person.index + 1;
	}
	else 
	{
		newNode->prevItem = nullptr;
		list->head = newNode; list->tail = newNode;
		newNode->Person.index = 0;
	}
}

void Remove(List* list, int index)
{
	Node *newNode = list->head;
	while(index != newNode->Person.index)
	{
		newNode = newNode->nextItem;
	}
	newNode->prevItem->nextItem = newNode->nextItem;
	newNode->nextItem->prevItem = newNode->prevItem;
	delete newNode;
}

void Insert(List* list, Person& person, int index)
{	
	Node *newNode = list->head;
	int i = 0;
	while (index != newNode->Person.index)
	{
		i++;
		newNode = newNode->nextItem;
	}
	newNode->Person = person;
	newNode->Person.index = i;
}

void ClearList(List* list)
{
	Node* newNode = list->head;
	int i = 1;
	while (i != list->tail->Person.index)
	{
		Remove(list, i);
		i++;
	}
	list->head = NULL;
	list->tail = NULL;
}

void MenuPerson(List* list)
{
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	const char escapeSymbol = 27;
	char key;
	int temp = 1;
	int numberCase;
	int asciiValue = 0;
	Person person1;
	while (asciiValue != escapeSymbol)
	{	
		system("cls");
		
		SetConsoleTextAttribute(hStdOut, FOREGROUND_RED |  FOREGROUND_INTENSITY);
		cout.width(12); cout << "Index:";
		cout.width(12); cout << "Surname:";
		cout.width(12); cout << "Name: ";
		cout.width(12); cout << "Sex: \n";
		
		SetConsoleTextAttribute(hStdOut, 2); 
		Show(list);

		SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY); 
		cout << "\n------List of Person: Main Menu------"
			<< "\n1. Add Person"
			<< "\n2. Add Random Person"
			<< "\n3. Insert Person"
			<< "\n4. Get Pointer On Person By Index"
			<< "\n5. Remove Person By Index"
			<< "\n6. Clear List"
			<< "\n------List of Person : Main Menu------";

		SetConsoleTextAttribute(hStdOut, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		cout << "\n\n\nChoose action (1-7):\n>";

		key = _getch();
		asciiValue = key;
		switch (asciiValue)
		{
			case '1':
			{	
				cout << '1';
				Add(list);
				cout << "\nPerson added\n";
				break;
			}
			case '2':
			{	
				cout << '2';
				AddForRandomPerson(list);
				break;
			}
			case '3':
			{	
				cout << '3';
				int index;
				cout << "\nInsert index:\n>";
				cin >> index;
				cout << "\n Enter a person from the keyboard or generate randomly?"
					<< "\nPress the R button to randomly generate"
					<< "\nPress the K button to enter from the keyboard\n>";
				char key = _getch();
				asciiValue = key;
				switch (asciiValue)
				{
					case 'r':
					{
						Insert(list, MakeRandomPerson(), index);
						break;
					}
					case 'k':
					{
						Insert(list, ReadPerson(), index);
						break;
					}
				}
				break;
			}
			case '4':
			{		
				cout << '4';
				int index;
				cout << "\n Insert index:\n>";
				cin >> index;
				cout << "Link on element:\n>";
				cout << &GetPointer(list, index);
				char key = _getch();
				asciiValue = key;
				break;
			}
			case '5':
			{	
				cout << '5';
				int index;
				cout << "\nInsert index:\n>";
				cin >> index;
				Remove(list, index);
				break;
			}
			case '6':
			{	
				cout << '6';
				ClearList(list);
				cout << "\nList is empty";
				break;
			}
		}
	}
}

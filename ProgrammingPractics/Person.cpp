#include "stdafx.h"

enum Sex { Male, Female };

struct Person
{
	char Surname[40];
	char Name[20];
	Sex SexPerson;
};

Person ReadPerson()
{
	Person newPerson;
	cout << "\nInsert Surname: ";
	cin >> newPerson.Surname;
	cout << "\nInsert Name: ";
	cin >> newPerson.Name;
	cout << "\nInsert Sex - Male(M)/Female(F): ";
	int n;
	char key = NULL;
	const char escapeSymbol = 27;
	int asciiValue = 0;

	key = _getch();
	asciiValue = key;
	switch (asciiValue)
	{
	case 'f':
	{
		newPerson.SexPerson = Female;
		cout << 'F';
		break;
	}
	case 'm':
	{
		newPerson.SexPerson = Male;
		cout << 'M';
		break;
	}
	default:
		break;
	}
	return newPerson;;
}
//TODO: ѕередача по значению - не очень хороша€ практика
void PrintPerson(Person person)
{
	cout << "\n\nSurname: " << person.Surname << endl;
	cout << "\nName: " << person.Name << endl;
	if (person.SexPerson == 0)
	{
		cout << "\nSexPerson: " << "Male" << endl;
	}
	else
	{
		cout << "\nSexPerson: " << "Female" << endl;
	}
}

void MenuPerson()
{
	const char escapeSymbol = 27;
	char key;
	int temp = 1;
	int asciiValue = 0;
	Person person1;
	while (asciiValue != escapeSymbol)
	{
		system("cls");
		cout << "Press Esc to quit the program\n"
			<< "\n1. Adding a person to the structure";
		key = _getch();
		asciiValue = key;
		switch (asciiValue)
		{
			case '1':
			{
				while (asciiValue != escapeSymbol)
				{
					system("cls");
					cout << "Press Esc to quit the program\n"
						<< "Result of program execution:\n\n";
					Person person1 = ReadPerson();
					system("cls");
					cout << "\nPerson added: \n";
					PrintPerson(person1);
					char key = _getch();
					asciiValue = key;
				}
				break;
			}
		}
	}
}

#include "stdafx.h"
#include "MenuLab4.h"



namespace lab4
{
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

			SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
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

			cout << "\n\n\nChoose action (1-6):\n>";

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
					AddRandomPerson(list);
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
						Insert(list, GetRandomPerson(), index);
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
					if (GetPointer(list, index) == NULL)
					{
						cout << "\nPlease insert correct date!\n";
					}
					else
					{
						cout << GetPointer(list, index);
					}
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
}

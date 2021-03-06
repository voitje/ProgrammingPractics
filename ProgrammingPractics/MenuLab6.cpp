#include "stdafx.h"
#include "MenuLab6.h"
#include "FamilyTools.h"


namespace lab6
{
	void MenuLabSix()
	{
		HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
		const char escapeSymbol = 27;
		char key;
		int temp = 1;
		int numberCase;
		int asciiValue = 0;
		PersonList list;
		
		while (asciiValue != escapeSymbol)	
		{
			system("cls");

			SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
			cout.width(12); cout << "Surname:";
			cout.width(12); cout << "Name:";
			cout.width(12); cout << "Age: \n";

			SetConsoleTextAttribute(hStdOut, 2);
			list.Show();
			
			SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			cout << "\n------List of Person: Main Menu------"
				<< "\n1. Add Adult"
				<< "\n2. Add Child"
				<< "\n3. Check information about Person"
				<< "\n4. Find a person at the specified index"
				<< "\n5. Return the index of the person, if it is in the list"
				<< "\n6. Remove a person from the list by index"
				<< "\n7. Clear List"
				<< "\n8. Get the number of items"
				<< "\n------List of Person : Main Menu------";

			SetConsoleTextAttribute(hStdOut, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			cout << "\n\n\nChoose action (1-9):\n>";
			key = _getch();
			asciiValue = key;
			switch (asciiValue)
			{
				case '1':
				{
					list.Add(GetRandomAdult());
					cout << "\nPerson added\n";
					break;
				}
				case '2':
				{
					list.Add(GetRandomChild());
					cout << "\nPerson added\n";
					break;
				}
				case '3':
				{
					SetConsoleTextAttribute(hStdOut, 2);
					list.ShowDescriptions();
					cout << "\nPress any key to continue working\n";
					key = _getch();
					key = _getch();
					break;
				}
				case '4':
				{
					int index;
					cout << "\nInsert index:\n>";
					cin >> index;
					PersonListItem tmp = list.Find(index);
					cout << "\nName:\n>";
					cout << tmp.GetValue()->GetName();
					cout << "\nSurname:\n>";
					cout << tmp.GetValue()->GetSurname();
					cout << "\nPress any key to continue working\n";
					key = _getch();
					key = _getch();
					break;
				}
				case '5':
				{
					cout << list.IndexOf();
					cout << "\nPress any key to continue working\n";
					key = _getch();
					key = _getch();
					break;
				}
				
				case '6':
				{
					int index;
					cout << "\nInsert index:\n>";
					cin >> index;
					list.RemoveAt(index);
					cout << "\nPress any key to continue working\n";
					key = _getch();
					break;
				}
				case '7':
				{
					list.Clear();
					cout << "\nList is empty";
					cout << "\nPress any key to continue working\n";
					key = _getch();
					break;
				}
				case '8':
				{
					cout << list.GetCount();
					cout << "\nPress any key to continue working\n";
					key = _getch();
					break;
				}
			}
		}
	}
}
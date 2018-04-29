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
		lab5::PersonList p1;
		lab5::Person* person = new lab5::Person();
		
		while (asciiValue != escapeSymbol)	
		{
			system("cls");

			SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
			cout.width(12); cout << "Surname:";
			cout.width(12); cout << "Name:";
			cout.width(12); cout << "Age: \n";

			SetConsoleTextAttribute(hStdOut, 2);
			p1.Show();
			
			SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			cout << "\n------List of Person: Main Menu------"
				<< "\n1. Add Adult"
				<< "\n2. Add Child"
				<< "\n3. Check information about Person"
				<< "\n4. Find a person at the specified index"
				<< "\n5. Return the index of the person, if it is in the list"
				<< "\n6. Remove a person from the list"
				<< "\n7. Remove a person from the list by index"
				<< "\n8. Clear List"
				<< "\n9. Get the number of items"
				<< "\n------List of Person : Main Menu------";

			SetConsoleTextAttribute(hStdOut, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			cout << "\n\n\nChoose action (1-9):\n>";
			key = _getch();
			asciiValue = key;
			switch (asciiValue)
			{
				case '1':
				{
					p1.Add(GetRandomAdult());
					cout << "\nPerson added\n";
					break;
				}
				case '2':
				{
					p1.Add(GetRandomChild());
					cout << "\nPerson added\n";
					break;
				}
				case '3':
				{
					SetConsoleTextAttribute(hStdOut, 2);
					p1.ShowDescriptions();
					cout << "\nPress any key to continue working\n";
					key = _getch();
					break;
				}
				case '4':
				{
					int index;
					cout << "\nInsert index:\n>";
					cin >> index;
					lab5::PersonListItem tmp = p1.Find(index);
					cout << "\nName:\n>";
					cout << tmp.GetValue()->GetName();
					cout << "\nSurname:\n>";
					cout << tmp.GetValue()->GetSurname();
					cout << "\nPress any key to continue working\n";
					key = _getch();
					break;
				}
				case '5':
				{
					cout << p1.IndexOf();
					cout << "\nPress any key to continue working\n";
					key = _getch();
					break;
				}
				case '6':
				{
					int index;
					p1.Remove(person);
					cout << "\nPress any key to continue working\n";
					key = _getch();
					break;
				}
				case '7':
				{
					int index;
					cout << "\nInsert index:\n>";
					cin >> index;
					p1.RemoveAt(index);
					cout << "\nPress any key to continue working\n";
					key = _getch();
					break;
				}
				case '8':
				{
					p1.Clear();
					cout << "\nList is empty";
					cout << "\nPress any key to continue working\n";
					key = _getch();
					break;
				}
				case '9':
				{
					cout << p1.GetCount();
					cout << "\nPress any key to continue working\n";
					key = _getch();
					break;
				}
			}
		}
	}
}
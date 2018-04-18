#include "stdafx.h"
#include "MenuLab6.h"

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
			//TODO: Список должен поддерживать всё тоже, что и в предыдущей лабе, только мы должны выбирать - кого в этот список класть - Adult или Child.
			cout << "\n------List of Person: Main Menu------"
				<< "\n1. Add Adult"
				<< "\n2. Add Child"
				<< "\n3. Check information about Person"
				<< "\n4. Clear list"
				<< "\n------List of Person : Main Menu------";

			SetConsoleTextAttribute(hStdOut, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			//TODO: Некорректное меню - пишет, что до 7
			cout << "\n\n\nChoose action (1-7):\n>";
			key = _getch();
			asciiValue = key;

			switch (asciiValue)
			{
				case '1':
				{
					p1.Add(Adult::GetRandom());
					cout << "\nPerson added\n";
					break;
				}
				case '2':
				{
					p1.Add(Child::GetRandom());
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
					p1.Clear();
					cout << "\nPress any key to continue working\n";
					key = _getch();
					break;
				}
			}
		}
	}
}
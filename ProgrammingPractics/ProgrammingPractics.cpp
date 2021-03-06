// ProgrammingPractics.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include "lab1.h"
#include "Lab2.h"
#include "Lab3.h"
#include "List.h"
#include "PersonList.h"
#include "MenuLab4.h"
#include "MenuLab5.h"
#include "MenuLab6.h"
#include "MenuLab7.h"

int main()
{	
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	int asciiValue = 0;
	char key = NULL;
	const char escapeSymbol = 27;
	lab4::List *list = new lab4::List;
	while (asciiValue != escapeSymbol)
	{
		system("cls");
		SetConsoleTextAttribute(hStdOut, 7);
		cout << "\n1. First Laboratory"
			<< "\n2. Second Laboratory"
			<< "\n3. Third Laboratory"
			<< "\n4. Work whit structure Person (Laboratory Three)"
			<< "\n5. Work with structure (Laboratory Four)"
			<< "\n6. Fifth Laboratory"
			<< "\n7. Sixth Laboratory"
			<< "\n8. Seventh Laboratory";
		key = _getch();
		asciiValue = key;
		switch (asciiValue)
		{
			case '1':
			{
				MenuFirstLaboratory();
				break;
			}
			case '2':
			{
				MenuSecondLaboratory();
				break;
			}
			case '3':
			{
				lab3::MenuThirdLaboratory();
				break;
			}
			case '4':
			{	
				system("cls");
				while (key != 'e')
				{	
					cout << "\n=====================================================\n";
					lab3::Person person1 = lab3::ReadPerson();
					cout << "\n=====================================================\n";
					lab3::PrintPerson(person1);
					cout << "\n=====================================================\n";
					cout << "Continue? (Y\\N)\n>";
					char newKey;
					cin >> newKey;
					if (newKey == 'n')
					{
						key = 'e';
					}
				}
				break;
			}
			case '5':
			{	
				lab4::Create(list);
				MenuPerson(list);
				break;
			}
			case '6':
			{
				lab5::MenuLabFive();
				break;
			}
			case '7':
			{
				lab6::MenuLabSix();
				break;
			}
			case '8':
			{
				MenuLabSeven();
				break;
			}
		}
	}
   return 0;
}

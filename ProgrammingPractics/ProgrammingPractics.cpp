// ProgrammingPractics.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "lab1.h"
#include "Lab2.h"
#include "Lab3.h"
#include "Person.h"

int main()
{	
	int asciiValue = 0;
	char key = NULL;
	const char escapeSymbol = 27;
	while (asciiValue != escapeSymbol)
	{
		system("cls");
		cout << "\n1. First Laboratory"
			<< "\n2. Second Laboratory"
			<< "\n3. Third Laboratory"
			<< "\n4. Work with structure";
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
				MenuThirdLaboratory();
				break;
			}
			case '4':
			{	
				MenuPerson();
				break;
			}
		}
	}
    return 0;
}


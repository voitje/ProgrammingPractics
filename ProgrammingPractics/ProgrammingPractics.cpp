// ProgrammingPractics.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


int main()
{	
	int asciiValue = 0;
	char key = NULL;
	const char escapeSymbol = 27;
	while (asciiValue != escapeSymbol)
	{
		//TODO: В лабораторных не отработан ввод неверных символов!
		system("cls");
		cout << "\n1. First Task"
			<< "\n2. Second Task";
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
		}
	}
    return 0;
}


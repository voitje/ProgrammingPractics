// ProgrammingPractics.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "lab1.h"
#include "Lab2.h"
#include "Lab3.h"

int main()
{	
	int asciiValue = 0;
	char key = NULL;
	const char escapeSymbol = 27;
	while (asciiValue != escapeSymbol)
	{
		system("cls");
		cout << "\n1. First Laboratory"
			<< "\n2. Second Laboratory";
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
			/*case '3':*/

			//{
			//	key = _getch();
			//	asciiValue = key;
			//	//MenuThirdLaboratory();
			//	char string1[100]; char string2[100];
			//	/*for (int i = 0; asciiValue != 13; i++)
			//	{
			//		cin >> string1[i]; 
			//	}*/
			//	cin.getline(string1, )
			//	for (int i = 0; asciiValue != 13; i++)
			//	{
			//		cin >> string2[i];
			//	}
			//	cout << Concatenate(string1, string2);
			//	
			//}
		}
	}
    return 0;
}


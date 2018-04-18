#include "stdafx.h"
#include "MenuLab7.h"
#include "ListLab7.h"
#include "ListItemLab7.h"
#include "ToolsForLabs.h"


void MenuLabSeven()
{
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	const char escapeSymbol = 27;
	char key;
	int temp = 1;
	int numberCase;
	int asciiValue = 0;
	List<double> fl;
	List<lab5::Person*> pers;
	List<double*> mas;
	List<List<double>*> link;
	while (asciiValue != escapeSymbol)
	{
		system("cls");

		SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
		cout << "Work with double:\n";
		SetConsoleTextAttribute(hStdOut, 2);
		fl.Show();

		SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
		cout.width(20); cout << "Work with array of double:\n";
		SetConsoleTextAttribute(hStdOut, 2);
		mas.Show();

		SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
		cout.width(20); cout << "Work with list of double:\n";

		//TODO: Выводятся адреса - это не правильно!
		SetConsoleTextAttribute(hStdOut, 2);
		link.Show();

		SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
		cout.width(20); cout << "Work with list of Person:\n";
		SetConsoleTextAttribute(hStdOut, 2);
		pers.Show();


		SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		cout << "\n------List of Person: Main Menu------"
			<< "\n1. Demonstrate on double"
			<< "\n2. Demonstrate on Person"
			<< "\n3. Demonstrate on List<double>"
			<< "\n4. Demonstrate on double[5]"
			<< "\n5. Delete fourt element from double[5]"
			<< "\n6. Delete fourt element from List<double>"
			<< "\n7. Delete fourt element from Person"
			<< "\n8. Delete fourt element from double"
			<< "\n7. Clear List" // TODO: Непонятно, какой из листов очищаем!
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
				double data;
				cout << "\nInsert value\n>";
				cin >> data;
				fl.Add(data);
				break;
			}
			case '2':
			{
				cout << '2';
				enum lab4::Sex tempSex = enum lab4::Sex(rand() % 2);
				pers.Add(MakeRandomPerson(tempSex));
				break;
			}
			case '3':
			{
				List<double> data;
				List<double> data1;
				List<double> data2;
				List<double> data3;
				List<double> data4;

				data.Add(0);
				data1.Add(1);
				data2.Add(2);
				data3.Add(3);
				data4.Add(4);

				link.Add(&data);
				link.Add(&data1);
				link.Add(&data2);
				link.Add(&data3);
				link.Add(&data4);
				cout << link;
				char temp = _getch();
				
				break;
			}
			case '4':
			{
				cout << '4';
				double arr1[] = { 1, 2, 3, 4, 5 };
				double arr2[] = { 1.2, 2.2, 3.2, 4.2, 5.2 };
				double arr3[] = { 1.23, 2.23, 3.23, 4.23, 5.24 };
				double arr4[] = { 1.09, 2.45, 3.1415, 4.28, 5.0 };
				double arr5[] = { 1.0, 2.0, 3.0, 4.0, 5.9 };
				mas.Add(arr1);
				mas.Add(arr2);
				mas.Add(arr3);
				mas.Add(arr4);
				mas.Add(arr5);
				char key = _getch();
				asciiValue = key;
				break;
			}
			case '5':
			{
				cout << '5';
				int index = 3;
				mas.RemoveAt(index);
				break;
			}
			case '6':
			{
				int index = 3;
				link.RemoveAt(index);
				break;
			}
			case '7':
			{
				int index = 3;
				pers.RemoveAt(index);
				break;
			}
			case '8':
			{
				int index = 3;
				fl.RemoveAt(index);
				break;
			}
		}
	}
}

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
	//TODO: Именования! \ DONE
	List<double> listDouble;
	List<lab5::Person*> listPerson;
	List<double*> listArrayOfDouble;
	List<List<double>*> listOfList;
	while (asciiValue != escapeSymbol)
	{
		system("cls");

		SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
		cout << "Work with double:\n";
		SetConsoleTextAttribute(hStdOut, 2);
		listDouble.Show();

		SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
		cout.width(20); cout << "Work with array of double:\n";
		SetConsoleTextAttribute(hStdOut, 2);
		listArrayOfDouble.Show();

		SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
		cout.width(20); cout << "Work with list of double:\n";

		SetConsoleTextAttribute(hStdOut, 2);
		listOfList.Show();

		SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
		cout.width(20); cout << "Work with list of Person:\n";
		SetConsoleTextAttribute(hStdOut, 2);
		listPerson.Show();


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
			<< "\n------List of Person : Main Menu------";

		SetConsoleTextAttribute(hStdOut, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		cout << "\n\n\nChoose action (1-8):\n>";
		key = _getch();
		asciiValue = key;
		int index = 3;
		switch (asciiValue)
		{
			case '1':
			{
				//TODO: Не обработан пользовательский ввод совсем \ DONE
				cout << '1';
				double data;
				cout << "\nInsert value\n>";
				while (!(cin >> data))
				{
					cin.clear();
					cin.ignore(cin.rdbuf()->in_avail());
					cout << "Incorrect value!!! Insert value : ";
				}
				listDouble.Add(data);
				break;
			}
			case '2':
			{
				cout << '2';
				enum lab4::Sex tempSex = enum lab4::Sex(rand() % 2);
				listPerson.Add(MakeRandomPerson(tempSex));
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

				listOfList.Add(&data);
				listOfList.Add(&data1);
				listOfList.Add(&data2);
				listOfList.Add(&data3);
				listOfList.Add(&data4);
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
				listArrayOfDouble.Add(arr1);
				listArrayOfDouble.Add(arr2);
				listArrayOfDouble.Add(arr3);
				listArrayOfDouble.Add(arr4);
				listArrayOfDouble.Add(arr5);
				char key = _getch();
				asciiValue = key;
				break;
			}
			case '5':
			{
				cout << '5';
				listArrayOfDouble.RemoveAt(index);
				break;
			}
			case '6':
			{
				listOfList.RemoveAt(index);
				break;
			}
			case '7':
			{
				listPerson.RemoveAt(index);
				break;
			}
			case '8':
			{
				listDouble.RemoveAt(index);
				break;
			}
		}
	}
}

#include "stdafx.h"

void FirstTask()
{	
	cout << "Hello, World";
}

void SecondTask()
{
	int a; 
	a = 5; 
	int b = 3;
	cout << "\n Variable a equals " << a; 
	cout << "\n Variable b equals " << b; 
	cout << "\n Summ of a and b equals " << a + b; 
}

void ThirdTask()
{
	int a = 5;
	int b = 3;
	float z = 5.0;
	float y = 3.0;
	cout << "Float variables division: " << z / y << endl;
	cout << "Integer variables division: " << a / b << endl;
}

void FourthTask()
{
	int a;
	int b;
	cout << "---Program for integer summation---";
	cout << "\n\n Enter first integer value: ";
	cin >> a; 
	cout << " Enter second integer value: ";
	cin >> b;
	cout <<" \n Summ of "<< a <<" and "<< b <<" equals "<< a + b <<"\n";
}

void FifthTask()
{
	int value;
	int anotherValue;
	int* pointer;
	value = 5;
	pointer = &value; 
	anotherValue = *pointer;
	cout <<"Value, stored in pointer: "<< anotherValue <<"\n";
	cout << "Address in pointer: "<< pointer <<"\n";
	cout <<"Value in pointer: "<< pointer <<"\n";
}

void SixthTask()
{
	int a;
	cout << "Enter value for check on even/odd: ";
	cin >> a;
	if (a % 2 == 0)
	{
		cout <<"\n Value "<< a << "is even! \n";
	}
	else
	{
		cout << "\n Value" << a << "is odd! \n";
	}
}

void SeventhTask()
{
	int a;
	cout << "Enter value for check on even/odd: ";
	cin >> a;
	if (a % 5 == 0)
	{
		cout <<"\n Value " << a <<" multiples 5! \n";
	}
	else if (a % 2 == 0)
	{
		cout << "\n Value " << a << " multiples 2! \n";
	}
	else
	{
		cout << "\n Value "<< a <<" doesn`t multiply 5 or 2! \n";
	}
}

void EighthTask()
{
	int a = 0;
	while (a < 5) 
	{
		cout <<"Value is "<< a << "now \n";
		a++;
	}
}

void NinethTask()
{
	int a = 0;
	cout << "\nPress Esc to quit the program" << endl;
	do 
	{
		cout << "Value is " << a << "now \n";
		a++;
	} while (a < 5);
}

void TenthTask()
{
	int a = 10;
	for (int i = 0; i < 10; i++)
	{
		cout <<"Iteration #"<< i <<"\n";
	}
	cout <<"\n\n";
	for (int i = 0; i < a; i++)
	{
		a--;
		cout <<"Iteration #"<< i <<"Value is "<< a <<"\n";
	}
}

void EleventhTask()
{
	int a = 10;
	for (int i = 0; i < 10; i++)
	{
		a--;
		if (i >= a)
		{
			cout <<"I is more or equal A! Break of cycle";
			break; 
		}
	}
	cout <<"\n A is " << a <<"\n";
}

void TwelfthTask()
{
	int a = 5;
	int b = 3;
	float z;
	z = a;
	cout << "Value of z is " << z <<"\n";
	a = z;
	a = (int)z;
	cout << "Value of a is " << a << "\n";
	z = a / b;
	cout << "Value of z is " << z << "\n";
	z = ((float)a) / b;
	cout << "Value of z is " << z << "\n";
}

void(*arrayPointerFunctions[])() =
{
	FirstTask, SecondTask, ThirdTask,
	FourthTask, FifthTask, SixthTask,
	SeventhTask, EighthTask, NinethTask,
	TenthTask, EleventhTask, TwelfthTask
};

void MenuCase(void(*arrayPointerToFunctions)())
{
	const char escapeSymbol = 27;
	int asciiValue = 0;
	while (asciiValue != escapeSymbol)
	{

		system("cls");
		cout << "Press Esc to quit the program\n"
			<< "Result of program execution:\n\n";
		arrayPointerToFunctions();
		char key = _getch();
		asciiValue = key;
	}
}

void MenuFirstLaboratory()
{
	const char escapeSymbol = 27;
	char key;
	int asciiValue = 0;
	while (asciiValue != escapeSymbol)
	{
		system("cls");
		cout << "Select the tasks section\n"
			<< "\n1. 1 - 6"
			<< "\n2. 7 - 12";
		key = _getch();
		asciiValue = key;
		switch (asciiValue)
		{
		case '1':
		{
			int asciiValue = 0;
			while (asciiValue != escapeSymbol)
			{
				system("cls");
				cout << "Press Esc to quit the program\n"
					<< "\n1. First Task"
					<< "\n2. Second Task"
					<< "\n3. Third Task"
					<< "\n4. Fourth Task"
					<< "\n5. Fifth Task"
					<< "\n6. Sixth Task";
				key = _getch();
				asciiValue = key;
				switch (asciiValue)
				{
				case '1':
				{
					MenuCase(*arrayPointerFunctions[0]);
					break;
				}
				case '2':
				{
					MenuCase(*arrayPointerFunctions[1]);
					break;
				}
				case '3':
				{
					MenuCase(*arrayPointerFunctions[2]);
					break;
				}
				case '4':
				{
					MenuCase(*arrayPointerFunctions[3]);
					break;
				}
				case '5':
				{
					MenuCase(*arrayPointerFunctions[4]);
					break;
				}
				case '6':
				{
					MenuCase(*arrayPointerFunctions[5]);
					break;
				}
				}
			}
			break;
		}
		case '2':
		{
			int asciiValue = 0;
			while (asciiValue != escapeSymbol)
			{
				system("cls");
				cout << "Press Esc to quit the program\n"
					<< "\n1. Seventh Task"
					<< "\n2. Eighth Task"
					<< "\n3. Nineth Task"
					<< "\n4. Ten Task"
					<< "\n5. Eleventh Task"
					<< "\n6. Twelfth Task";
				key = _getch();
				asciiValue = key;
				switch (asciiValue)
				{
				case '1':
				{
					MenuCase(*arrayPointerFunctions[6]);
					break;
				}
				case '2':
				{
					MenuCase(*arrayPointerFunctions[7]);
					break;
				}
				case '3':
				{
					MenuCase(*arrayPointerFunctions[8]);
					break;
				}
				case '4':
				{
					MenuCase(*arrayPointerFunctions[9]);
					break;
				}
				case '5':
				{
					MenuCase(*arrayPointerFunctions[10]);
					break;
				}
				case '6':
				{
					MenuCase(*arrayPointerFunctions[11]);
					break;
				}
				}
			}
		}
		}
	}
}

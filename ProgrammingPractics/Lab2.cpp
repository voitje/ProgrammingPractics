#include "stdafx.h"
//TODO: ��������� �� ���� ������������. 
//TODO: ����� ������ ���� ���������� � ������� ��� ���������� ������������.
void PrintHelloWorld()
{
	cout << "Hello, World!\n";
}

double MakeCalculation(int value1, int value2)
{
	char key;
	cout << "Enter mathematic operation (+, -, *, /, %): ";
	cin >> key;

	while ((key != '+') && (key != '-') && (key != '*') && (key != '/') && (key != '%'))
	{
		cout << ("\nINCORRECT SYMBOL!!!\nPlease, enter (+, -, *, /, %):");
		cin >> key;
	}

	switch (key)
	{
		//TODO: ��������� �������������� ���� �� RSDN
	case '+':
		return value1 + value2;
		break;

	case '-':
		return value1 - value2;
		break;

	case '*':
		return value1 * value2;
		break;

	case '/':
		return value1 / value2;

	case '%':
		return value1 % value2;
		break;

	default:
		return -1;
		break;
	}
}

int GetRoots(int a, int b, int c, double* x1, double* x2)
{
	double D = b * b - (4 * a*c);
	double sqrtD = sqrt(D);
	if (a == 0)
	{
		*x1 = (-c) / b;
		x2 = NULL;
		return 1;
		
	}
	if (D < 0)
	{
		x1 = x2 = NULL;
		return 0;
	}
	if ((int)D == 0)
	{
		*x1 = -(b / 2 * a);
		x2 = NULL;
		return 1;
	}
	*x1 = (-b - sqrtD) / (2 * a);
	*x2 = (-b + sqrtD) / (2 * a);
	return 2;
}

int GetPower(int base, int power)
{
	int temp = 1;
//TODO: ��� if-else ������ ���� ����������� ������!
	if (power == 0)
		return 1;
	if (temp == power)
		return base;
	return GetPower(base*base, temp++);
}

void SortArray(double* array, int n)
{
//TODO: ��� for ������ ���� ����������� ������!
	for (int i = 1; i < n; i++)
		for (int j = i; j > 0 && array[j - 1] > array[j]; j--) 
			swap(array[j - 1], array[j]);        
}
//TODO: ����������� ���������� �������� ���������� ���� RSDN https://rsdn.org/article/mag/200401/codestyle.XML
//TODO: � ��������� ���� ��� � ����������� �� ����������
void MultiplyMatrices(int arrayA [n][m], int arrayB[n][m], int arrayC[n][m], int n11, int m22, int n22)
{
	for (int i = 0; i < n11; i++)
	{
		for (int j = 0; j < m22; j++)
		{
			arrayC[i][j] = 0;
			for (int k = 0; k < n22 ; k++)
//TODO: ��� for ������ ���� ����������� ������!
				arrayC[i][j] += arrayA[i][k] * arrayB[k][j];
		}
	}
}
void MenuSecondLaboratory()
{
	const char escapeSymbol = 27;
	char key;
	int temp = 1;
	int asciiValue = 0;
	while (asciiValue != escapeSymbol)
	{
		system("cls");
		cout << "Press Esc to quit the program\n"
			<< "\n1. Print Hello, World!"
			<< "\n2. Calculator"
			<< "\n3. Quadratic equation"
			<< "\n4. Exponentiation"
			<< "\n5. Sorting an array"
			<< "\n6. Matrix multiplication";
		key = _getch();
		asciiValue = key;
		switch (asciiValue)
		{
		case '1':
		{
			const char escapeSymbol = 27;
			int asciiValue = 0;
			while (asciiValue != escapeSymbol)
			{

				system("cls");
				cout << "Press Esc to quit the program\n"
					<< "Result of program execution:\n\n";
				PrintHelloWorld();
				char key = _getch();
				asciiValue = key;
			}
			break;
		}
		case '2':
		{
			const char escapeSymbol = 27;
			int asciiValue = 0;
			while (asciiValue != escapeSymbol)
			{

				system("cls");
				cout << "Press Esc to quit the program\n";
				int value1; int value2;
				cout << "\nFirst digit :"; cin >> value1;
				cout << "\nSirst digit :"; cin >> value2;
				cout << MakeCalculation(value1, value2);
				char key = _getch();
				asciiValue = key;
			}
			break;
		}
		case '3':
		{
			const char escapeSymbol = 27;
			int asciiValue = 0;
			while (asciiValue != escapeSymbol)
			{

				system("cls");
				cout << "Press Esc to quit the program\n"
					<< "Result of program execution:\n\n";
				int a; int b; int c;
				double* x1 = new double;
				double* x2 = new double;
				cout << "Enter A: "; cin >> a;
				cout << "Enter B: "; cin >> b;
				cout << "Enter C: "; cin >> c;
				cout << "Number of decisions: " << GetRoots(a, b, c, x1, x2) << endl;
				if (GetRoots(a, b, c, x1, x2) > 0)//TODO: ��� if-else ������ ���� ����������� ������!
					cout << "\nRadicals: " << *x1 << ' ' << *x2 << endl;
				char key = _getch();
				asciiValue = key;
			}
			break;
		}
		case '4':
		{
			const char escapeSymbol = 27;
			int asciiValue = 0;
			while (asciiValue != escapeSymbol)
			{

				system("cls");
				cout << "Press Esc to quit the program\n"
					<< "Result of program execution:\n\n";
				int base; int power;
				cout << "\nEnter the number that you want to raise to the power of: "; cin >> base;
				cout << "\nEnter the degree: ";  cin >> power;
				cout << "\nAnswer: " << GetPower(base, power);
				char key = _getch();
				asciiValue = key;
			}
			break;
		}
		case '5':
		{
			const char escapeSymbol = 27;
			int asciiValue = 0;
			while (asciiValue != escapeSymbol)
			{

				system("cls");
				cout << "Press Esc to quit the program\n";
				double array[1000]; int n1;
				const char escapeSymbol = 27;
				char key;
				int asciiValue = 0;
				if (temp == 1)
				{
					cout << "Enter the number of elements: "; cin >> n1;
				}
				while (asciiValue != escapeSymbol)
				{
					system("cls");
					cout << "\nArray: \n";
					if (temp == 1)
					{
						memset(array, 0, sizeof(array));
						temp = 0;
					}
					for (int i = 0; i < n1; i++)
						cout << array[i] << ' ';
					cout << "\nFill the array:\n"
						<< "\n1. Random "
						<< "\n2. From the keyboard\n";
					key = _getch();
					asciiValue = key;
					switch (asciiValue)
					{
						//TODO: ��������� �������������� � ������������ � RSDN.
					case '1':
					{//TODO: ��� for ������ ���� ����������� ������!
						for (int i = 0; i < n1; i++)
							array[i] = rand() % 100;
						break;
					}
					case '2':
					{
						cout << "\nEnter " << n1 << " elements:\n ";
						for (int i = 0; i < n1; i++)
						{
							cin >> array[i];
						}
						break;
					}
					}
					SortArray(array, n1);
					cout << "\nThe array was sorted: \n";
					for (int i = 0; i < n1; i++)//TODO: ��� for ������ ���� ����������� ������!
						cout << array[i] << ' ';
					char key = _getch();
					asciiValue = key;
				}

			}
		}

		case '6':
		{
			const char escapeSymbol = 27;
			int asciiValue = 0;
			while (asciiValue != escapeSymbol)
			{
//TODO: ����������� ���������� �������� ���������� ���� RSDN https://rsdn.org/article/mag/200401/codestyle.XML
//TODO: � ��������� ���� ��� � ����������� �� ����������
				system("cls");
				cout << "Press Esc to quit the program\n"
					<< "Result of program execution:\n\n";
				int arrayA[n][m]; int arrayB[n][m]; int arrayC[n][m]; int n11; int m22; int n22; int m11;
				cout << "The first matrix:\n";
				cout << "\nRows: "; cin >> n11; cout << "Columns: "; cin >> m11;
				cout << "\nThe second matrix:\n";
				cout << "\nRows: "; cin >> n22; cout << "Columns: "; cin >> m22;
				//TODO: ���� ����� ������������, ���������!
				for (int i = 0; i < n11; i++)
					for (int j = 0; j < m11; j++)
						arrayA[i][j] = rand() % 10;
				for (int i = 0; i < n22; i++)
					for (int j = 0; j < m22; j++)
						arrayB[i][j] = rand() % 10;
				cout << "\nFirst matrix: ";
				for (int i = 0; i < n11; i++)
				{
					cout << endl;
					for (int j = 0; j < m11; j++)
						cout << arrayA[i][j] << ' ';
				}
				cout << "\n\nSecond matrix: ";
				for (int i = 0; i < n22; i++)
				{
					cout << endl;
					for (int j = 0; j < m22; j++)
						cout << arrayB[i][j] << ' ';
				}
				MultiplyMatrices(arrayA, arrayB, arrayC, n11, m22, n22);
				cout << "\nMultiply the first matrix by the second: ";
				for (int i = 0; i < n11; i++)
				{
					cout << endl;
					for (int j = 0; j < m22; j++)
						cout << arrayC[i][j] << ' ';
				}
				char key = _getch();
				asciiValue = key;
			}
			break;
		}

		}

	}
}

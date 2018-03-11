#include "stdafx.h"
#include "Lab2.h"

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
	if (power == 0)
	{
		return 1;
	}
	if (temp == power)
	{
		return base;
	}
	return GetPower(base*base, temp++);
}

void SortArray(double* array, int n)
{
	for (int i = 1; i < n; i++)
	{
		for (int j = i; j > 0 && array[j - 1] > array[j]; j--)
		{
			swap(array[j - 1], array[j]);
		}
	}
}

void MultiplyMatrices(int arrayA [n][m], int arrayB[n][m], int arrayC[n][m], int n11, int m22, int n22)
{
	for (int i = 0; i < n11; i++)
	{
		for (int j = 0; j < m22; j++)
		{
			arrayC[i][j] = 0;
			for (int k = 0; k < n22; k++)
			{
				arrayC[i][j] += arrayA[i][k] * arrayB[k][j];
			}
		}
	}
}

void WriteMatrix(int columnMatrix, int rowsMatrix, int arrayName[n][m])
{
	for (int i = 0; i < columnMatrix; i++)
	{
		cout << endl;
		for (int j = 0; j < rowsMatrix; j++)
		{
			cout << arrayName[i][j] << ' ';
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
					break;
				}
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
					if (GetRoots(a, b, c, x1, x2) > 0)
					{
						cout << "\nRadicals: " << *x1 << ' ' << *x2 << endl;
					}
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
					double array[1000]; 
					int n1;
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
						{
							cout << array[i] << ' ';
						}
						cout << "\nFill the array:\n"
							<< "\n1. Random "
							<< "\n2. From the keyboard\n";
						key = _getch();
						asciiValue = key;
						switch (asciiValue)
						{
							case '1':
							{
								for (int i = 0; i < n1; i++)
								{
									array[i] = rand() % 100;
								}
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
						for (int i = 0; i < n1; i++)
						{
							cout << array[i] << ' ';
						}
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
					system("cls");
					cout << "Press Esc to quit the program\n"
						<< "Result of program execution:\n\n";
					int arrayA[n][m];
					int arrayB[n][m];
					int arrayC[n][m];
					int columnA; int rowsA;
					int columnB; int rowsB;

					cout << "The first matrix:\n";
					cout << "\nRows: "; cin >> columnA;
					cout << "Columns: "; cin >> rowsB;

					cout << "\nThe second matrix:\n";
					cout << "\nRows: "; cin >> columnB;
					cout << "Columns: "; cin >> rowsA;
					
					for (int i = 0; i < columnA; i++)
					{
						for (int j = 0; j < rowsB; j++)
						{
							arrayA[i][j] = rand() % 10;
							arrayB[i][j] = rand() % 10;
						}
					}
					cout << "\n\nFirst matrix: ";
					WriteMatrix(columnA, rowsB, arrayA);

					cout << "\n\nSecond matrix: ";
					WriteMatrix(columnB, rowsA, arrayB);

					MultiplyMatrices(arrayA, arrayB, arrayC, columnA, rowsA, columnB);

					cout << "\n\nMultiply the first matrix by the second: ";
					WriteMatrix(columnA, rowsA, arrayC);

					char key = _getch();
					asciiValue = key;
				}
				break;
			}
		}
	}
}

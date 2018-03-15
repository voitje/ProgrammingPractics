#include "stdafx.h"
#include "Lab2.h"

void PrintHelloWorld()
{
	cout << "Hello, World!\n";
}

double MakeCalculation(int value1, int value2)
{
	char key;
	cout << "Enter mathematic operation (+, -, *, /, %):";
	cin >> key;
	//TODE: Зацикливание \ DONE
	while((key != '+') && (key != '-') && (key != '*') && (key != '/') && (key != '%'))
	{
		cout << ("\nINCORRECT SYMBOL!!!\nPlease, enter (+, -, *, /, %):");
		char newKey;
		cin >> newKey;
		key = newKey;
	}
	
	switch (key)
	{
		case '+':
			return value1 + value2;
		case '-':
			return value1 - value2;
		case '*':
			return value1 * value2;
		case '/':
			return value1 / value2;
		case '%':
			return value1 % value2;
		default:
			return -1;
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

int GetPower(int base, int power, int temp, int tempBase)
{	
	//TODO: Не работает \ DONE
	if (power == 0)
	{
		return 1;
	}
	if (temp == power)
	{
		return base;
	}
	return GetPower(base*tempBase, power, temp+=1, tempBase);
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

void MultiplyMatrices(int arrayA [n][m], int arrayB[n][m], int arrayC[n][m], int rowsA, int columnB, int columnA)
{
	for (int i = 0; i < rowsA; i++)
	{
		for (int j = 0; j < columnB; j++)
		{
			arrayC[i][j] = 0;
			for (int k = 0; k < columnA; k++)
			{
				arrayC[i][j] += arrayA[i][k] * arrayB[k][j];
			}
		}
	}
}

void WriteMatrix(int rowsMatrix, int columnMatrix, int arrayName[n][m])
{
	for (int i = 0; i < rowsMatrix; i++)
	{
		cout << endl;
		for (int j = 0; j < columnMatrix; j++)
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
	int  temptemp = 0;
	int asciiValue = 0;
	while (asciiValue != escapeSymbol)
	{
		system("cls");
		cout << "Press Esc to quit the program when after running the program\n"
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
				while (asciiValue != escapeSymbol)
				{
					system("cls");
					cout << "Press Esc to quit the program when after running the program\n"
						<< "Result of program execution:\n\n";
					PrintHelloWorld();
					char key = _getch();
					asciiValue = key;
				}
				break;
			}
			case '2':
			{
				while (asciiValue != escapeSymbol)
				{
					system("cls");
					cout << "Press Esc to quit the program when after running the program\n";
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
				while (asciiValue != escapeSymbol)
				{
					system("cls");
					cout << "Press Esc to quit the program when after running the program\n"
						<< "Result of program execution:\n\n";
					int a; int b; int c;
					double* x1 = new double;
					double* x2 = new double;
					cout << "Enter A: "; cin >> a;
					cout << "Enter B: "; cin >> b;
					cout << "Enter C: "; cin >> c;
					cout << "Number of decisions: " << GetRoots(a, b, c, x1, x2) << endl;
					if (GetRoots(a, b, c, x1, x2) == 1)
					{
						cout << "\nRadical: " << *x1 << endl;
					}
					if (GetRoots(a, b, c, x1, x2) == 2)
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
				while (asciiValue != escapeSymbol)
				{
					system("cls");
					cout << "Press Esc to quit the program when after running the program\n"
						<< "Result of program execution:\n\n";
					int base; int power; int temp = 1; 
					cout << "\nEnter the number that you want to raise to the power of N: "; cin >> base;
					int tempBase = base;
					cout << "\nEnter the power N: ";  cin >> power;
					cout << "\nAnswer: " << GetPower(base, power,temp, tempBase);
					char key = _getch();
					asciiValue = key;
				}
				break;
			}
			case '5':
			{
				while (asciiValue != escapeSymbol)
				{
					system("cls");
					cout << "Press Esc to quit the program when after running the program\n";
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
						if (temp == 1)
						{
							memset(array, 0, sizeof(array));
							temp = 0;
						}
						cout << "\nArray:\n";
						for (int i = 0; i < n1; i++)
						{
							cout << array[i] << ' ';
						}
						SortArray(array, n1);
						cout << "\n\nThe array was sorted: \n";
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
				while (asciiValue != escapeSymbol)
				{
					system("cls");
					cout << "Press Esc to quit the program when after running the program\n"
						<< "Result of program execution:\n\n";
					int arrayA[n][m];
					int arrayB[n][m];
					int arrayC[n][m];
					int columnA; int rowsA;
					int columnB; int rowsB;

					cout << "The first matrix:\n";
					cout << "\nRows: "; cin >> rowsA;
					cout << "Columns: "; cin >> columnA; 

					cout << "\nThe second matrix:\n";
					cout << "\nRows: "; cin >> rowsB;
					cout << "Columns: "; cin >> columnB;
					
					for (int i = 0; i < rowsA; i++)
					{
						for (int j = 0; j < columnA; j++)
						{
							arrayA[i][j] = rand() % 10;
						}
					}
					for (int i = 0; i < rowsB; i++)
					{
						for (int j = 0; j < columnB; j++)
						{
							arrayB[i][j] = rand() % 10;
						}
					}
					cout << "\n\nFirst matrix: ";
					WriteMatrix(rowsA, columnA, arrayA);

					cout << "\n\nSecond matrix: ";
					WriteMatrix(rowsB, columnB, arrayB);

					MultiplyMatrices(arrayA, arrayB, arrayC, rowsA, columnB, columnA);

					cout << "\n\nMultiply the first matrix by the second: ";
					WriteMatrix(rowsA, columnB, arrayC);

					char key = _getch();
					asciiValue = key;
				}
				break;
			}
		}
	}
}

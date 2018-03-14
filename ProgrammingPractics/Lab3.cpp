#include "stdafx.h"
#include "Lab3.h"

int GetLength(char* string)
{
	int length = 0;
	for (int i = 0; string[i] != 0; ++i)
	{
		++length;
	}
	return length;
}
char* Concatenate(char* stringA, char* stringB)
{
	char* string = new char[8];
	int i = 0;
	int j = 0;
	//TODO: Именование не по RSDN.
	int skaA = strlen(stringA);
	int skaB = strlen(stringB);
	//TODO: Ниже дубли. Изменить.
	for (; stringA[i] != '\0'; i++)
	{
		string[i] = stringA[i];
	}
	for (; stringB[j] != '\0'; j++, i++)
	{
		string[i] = stringB[j];
	}
	string[i] = '\0';
	return string;
}

char* GetSubstring(char* string, int startIndex, int charCount)
{
	if (startIndex < 0 || charCount < 0 || (strlen(string) < startIndex + charCount + 2))
	{
		return NULL;
	}
	int i = 0;
	int j = 0;
	char* temp = new char[8];;
	for (j = 0, i = startIndex; i < charCount + startIndex; i++, j++)
	{
		temp[j] = string[i];
	}
	temp[j] = '\0';
	return temp;
}

int FindSubstring(char* string, char* substring)
{	
	int n = strlen(substring);
	int result = -1;
	for (int i = 0, j = 0; i < strlen(string); i++)
	{
		if (string[i] == substring[j])
		{
			while (n != 0)
			{
				if (string[i] == substring[j])
				{
					n--;
				}
				i++;
				j++;
			}
			if (n == 0)
			{
				return (i - strlen(substring));
			}
			result == -1;
		}
		j == 0;
	}
	return result;
}

char* ChangeToUppercase(char* string)
{	
	int asciiUppercaseA = 97;
	int asciiUppercaseZ = 122;
	for (int i = 0; i < strlen(string); i++)
	{
		if (string[i] >= asciiUppercaseA && string[i] <= asciiUppercaseZ)
		{
			string[i] -= 32;
		}
	}
	return string;
}

char* ChangeToLowercase(char* string)
{	
	int asciiLowercaseA = 65;
	int asciiLowercaseZ = 90;
	for (int i = 0; i < strlen(string); i++)
	{
		if (string[i] >= asciiLowercaseA && string[i] <= asciiLowercaseZ)
		{
			string[i] += 32;
		}
	}
	return string;
}

int Copy(char * string, char * resString, int i, int j)
{
	while (string[i])
	{
		resString[j++] = string[i++];
	}
	resString[j] = '\0';
	return i;
}

void SplitFilename(char* source, char* path, char* name, char* extension)
{
	int index = 0;
	int pointPlace;
	int subIndex = 0;
	while (source[index] != '\0')
	{
		if (source[index] == '.')
		{
			break;
		}
		index++;
	}
	if ((source[index - 1]) && (index))
	{
		pointPlace = index;
		index = Copy(source, extension, index, subIndex);

		while ((source[index] != '\\') && (index))
		{
			index--;
		}
		if (index != pointPlace - 1)
		{
			if (index)
			{
				for (subIndex = 0; subIndex < index + 1; subIndex++)
				{
					path[subIndex] = source[subIndex];
				}
				path[subIndex] = '\0';
				for (index = 0; subIndex < pointPlace;)
				{
					name[index++] = source[subIndex++];
				}
				name[index] = '\0';
			}
			else
			{
				for (index = 0; index < pointPlace; index++)
				{
					name[index] = source[index];
				}
				name[index] = '\0';
				path[0] = NULL;
			}
		}
		return;
	}
path[0] = NULL;
extension[0] = NULL;
name[0] = NULL;	
}

char* ReplaceSpacesOnTabs(char* string, int countSpace)
{
	char* newString = new char[strlen(string)];
	int endSymbol = 0;
	int currentSymbolNewString = 0;

	for (int i = 0; i < strlen(string); i++)
	{
		currentSymbolNewString = i;
		bool isTab = true;
		for (int i = 0; i < countSpace; i++)
		{
			if (string[currentSymbolNewString++] != ':')
			{
				isTab = false;
			}
		}

		if (isTab)
		{
			newString[i] = '\t';
		}
		else
		{
			newString[i] = string[i];
		}
		endSymbol++;
	}
	newString[endSymbol] = '\0';
	return newString;
}

char* ReplaceTabsOnSpaces(char* string)
{	
	char* string1 = new char[8];
	int j = 0;
	for (int i = 0; i < strlen(string); i++, j++)
	{
		string1[j] = string[i];
		if (string[i] == '\t')
		{
			if (j % 4 == 0)
			{ 
				string1[j] = ':'; string1[j + 1] = ':';
				string1[j + 2] = ':'; string1[j + 3] = ':';
				j = j + 3;
			}
			else
			{
				while (j % 4 != 0)
				{
					string1[j] = ':';
					j++;
				}
				j--;
			}
		}
	}
	string1[j] = '\0';
	return string1;
}

void MenuThirdLaboratory()
{
	const char escapeSymbol = 27;
	char key;
	int temp = 1;
	int asciiValue = 0;
	while (asciiValue != escapeSymbol)
	{
		system("cls");
		cout << "Press Esc to quit the program\n"
			<< "\n1. Length of string"
			<< "\n2. Concatenate"
			<< "\n3. Substring from a string"
			<< "\n4. Find Substring"
			<< "\n5. Uppercase"
			<< "\n6. Lowercase"
			<< "\n7. Split Filename"
			<< "\n8. Replace Tabs On Spaces"
			<< "\n9. Replace Spaces On Tabs(in developing)";
		key = _getch();
		asciiValue = key;
		switch (asciiValue)
		{
			case '1':
			{
				while (asciiValue != escapeSymbol)
				{
					system("cls");
					char string[100];
					cout << "Press Esc to quit the program\n\n";
					cout << "\nString: "; 
					cin >> string;
					cout << "\nLength of string: "; 
					cout << GetLength(string);
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
					char* s2;
					char stringA[100];
					char stringB[100];
					cout << "Press Esc to quit the program\n\n";
					cout << "\nFirst string: "; cin >> stringA;
					cout << "\nSecond string: "; cin >> stringB;
					s2 = Concatenate(stringA, stringB);
					for (int i = 0; s2[i] != '\0'; i++)
					{
						cout << s2[i];
					}
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
					char string1[100];
					char* str;
					cout << "Press Esc to quit the program\n\n";
					cout << "\nWrite string: ";
					cin.getline(string1, 100);
					int startIndex; int charCount;
					cout << "\nStart Index: "; cin >> startIndex;
					cout << "\nChar Count: "; cin >> charCount;
					cout << "\nResult: ";
					str = GetSubstring(string1, startIndex, charCount);
					if (str == NULL)
					{
						cout << "-1";
					}
					else
					{
						for (int i = 0; i < str[i] != '\0'; i++)
						{
							cout << str[i];
						}
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
					char string[100];
					char substring[100];
					cout << "Press Esc to quit the program\n\n";
					cout << "\nString: "; cin.getline(string, 100);
					cout << "\nSubstring: "; cin.getline(substring, 100);
					cout << "\nResult: ";
					cout << FindSubstring(string, substring);
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
					char string[100];
					cout << "Press Esc to quit the program\n\n";
					cout << "String: "; cin.getline(string, 100);
					cout << "\nAfter: ";
					cout << ChangeToUppercase(string);
					char key = _getch();
					asciiValue = key;

				}
				break;
			}
			case '6':
			{
				while (asciiValue != escapeSymbol)
				{
					system("cls");
					char string[100];
					cout << "Press Esc to quit the program\n\n";
					cout << "String: "; cin.getline(string, 100);
					cout << "\nAfter: ";
					cout << ChangeToLowercase(string);
					char key = _getch();
					asciiValue = key;
				}
				break;
			}
			case '7':
			{
				while (asciiValue != escapeSymbol)
				{
					system("cls");
					char source[100];
					char path[100];
					char name[100];
					char extension[100];
					cout << "Press Esc to quit the program\n\n";
					cout << "\nWay: "; cin >> source;
					SplitFilename(source, path, name, extension);
					cout << "\nPath: "; cout << path;
					cout << "\nName: "; cout << name;
					cout << "\nExtension: "; cout << extension;
					char key = _getch();
					asciiValue = key;
				}
				break;
			}
			case '8':
			{
				while (asciiValue != escapeSymbol)
				{
					system("cls");
					char string[100];
					char* resultOfWork;
					cout << "Press Esc to quit the program\n\n";
					cout << "\nString: "; cin.getline(string, 100);
					resultOfWork = ReplaceTabsOnSpaces(string);
					for (int i = 0; resultOfWork[i] != '\0'; i++)
					{
						cout << resultOfWork[i];
					}
					char key = _getch();
					asciiValue = key;
				}
				break;
			}
			case '9':
			{
				while (asciiValue != escapeSymbol)
				{
					system("cls");
					cout << "Press Esc to quit the program\n\n"; 
					char* resultOfWork = (char*)"Cake::::is::a:lie!";
					cout << ReplaceSpacesOnTabs(resultOfWork, 4);
					char key = _getch();
					asciiValue = key;
				}
				break;
			}
		}
	}
}

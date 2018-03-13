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
	int skaA = strlen(stringA);
	int skaB = strlen(stringB);
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
		string = "NULL";
		return string;
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

char* Uppercase(char* string)
{
	for (int i = 0; i < strlen(string); i++)
	{
		if (string[i] > 97 && string[i] < 122)
		{
			string[i] -= 32;
		}
	}
	return string;
}

char* Lowercase(char* string)
{
	for (int i = 0; i < strlen(string); i++)
	{
		if (string[i] > 65 && string[i] < 90)
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
				for (index = 0; subIndex<pointPlace;)
				{
					name[index++] = source[subIndex++];
				}
				name[index] = '\0';
			}
			else
			{
				for (index = 0; index<pointPlace; index++)
				{
					name[index] = source[index];
				}
				name[index] = '\0';
				path[0] = NULL;
			}
		}
		else
		{
			path[0] = NULL;
			extension[0] = NULL;
			name[0] = NULL;
		}
	}
	else
	{
		path[0] = NULL;
		extension[0] = NULL;
		name[0] = NULL;
	}

}

char* ReplaceSpacesOnTabs(char* string)
{
	for (int i = 0; i < strlen(string); i++)
	{	
		if (i % 4 == 0)
		{
			if (string[i] == ':' && string[i + 1] == ':' && string[i + 2] == ':' && string[i + 3] == ':')
			{
				string[i] = '\t';
				for (int j = i + 2; j < (strlen(string) - 2); j++)
				{
					string[j] = string[j + 2];
				}
			}
		}
	}
	return string;
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

Person ReadPerson()
{	
	Person person;
	cout << "\nSurname: ";
	cin >> person.Surname;
	cout << "\nName: ";
	cin >> person.Name;
	return person;
}
void PrintPerson(Person person)
{
	cout << "\nSurname: ";
	cout << person.Surname;
	cout << "\nName: ";
	cout << person.Name;
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
				const char escapeSymbol = 27;
				int asciiValue = 0;
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
				const char escapeSymbol = 27;
				int asciiValue = 0;
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
				const char escapeSymbol = 27;
				int asciiValue = 0;
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
					for (int i = 0; i < str[i] != '\0'; i++)
					{
						cout << str[i];
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
				const char escapeSymbol = 27;
				int asciiValue = 0;
				while (asciiValue != escapeSymbol)
				{
					system("cls");
					char string[100];
					cout << "Press Esc to quit the program\n\n";
					cout << "String: "; cin.getline(string, 100);
					cout << "\nAfter: ";
					cout << Uppercase(string);
					char key = _getch();
					asciiValue = key;

				}
				break;
			}
			case '6':
			{
				const char escapeSymbol = 27;
				int asciiValue = 0;
				while (asciiValue != escapeSymbol)
				{
					system("cls");
					char string[100];
					cout << "Press Esc to quit the program\n\n";
					cout << "String: "; cin.getline(string, 100);
					cout << "\nAfter: ";
					cout << Lowercase(string);
					char key = _getch();
					asciiValue = key;
				}
				break;
			}
			case '7':
			{
				const char escapeSymbol = 27;
				int asciiValue = 0;
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
				const char escapeSymbol = 27;
				int asciiValue = 0;
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
				const char escapeSymbol = 27;
				int asciiValue = 0;
				while (asciiValue != escapeSymbol)
				{

					system("cls");
					char string[100];
					cout << "Press Esc to quit the program\n\n"; 
					char* resultOfWork = ":::Cake\tis\ta lie!"; 
					cout << ReplaceSpacesOnTabs(resultOfWork);
					char key = _getch();
					asciiValue = key;
				}
				break;
			}
		}
	}
}

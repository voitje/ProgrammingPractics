#include "stdafx.h"
#include "Lab3.h"

namespace lab3
{
	int GetLength(char* string)
	{
		int length = 0;
		for (int i = 0; string[i] != 0; ++i)
		{
			++length;
		}
		return length;
	}

	void JoingString(char* stringA, char* stringB, int startIndex)
	{
		int i = startIndex;
		for (int j = 0; stringB[j] != '\0'; i++, j++)
		{
			stringA[i] = stringB[j];
		}
		stringA[i] = '\0';
	}

	char* Concatenate(char* stringA, char* stringB)
	{
		char* string = new char[8];
		JoingString(string, stringA, 0);
		JoingString(string, stringB, strlen(stringA));
		return string;
	}

	char* GetSubstring()
	{
		cin.ignore(4096, '\n');
		cout << "\nWrite string: ";
		char* string1 = new char[32];
		cin.getline(string1, 100);
		int startIndex; int charCount;
		cout << "\nStart Index: "; cin >> startIndex;
		cout << "\nChar Count: "; cin >> charCount;
		cout << "\nResult: ";
		if (startIndex < 0 || charCount < 0 || (strlen(string1) < startIndex + charCount + 2))
		{
			return NULL;
		}
		int i = 0;
		int j = 0;
		char* temp = new char[8];;
		for (j = 0, i = startIndex; i < charCount + startIndex; i++, j++)
		{
			temp[j] = string1[i];
		}
		temp[j] = '\0';
		cin.ignore(4096, '\n');
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
				result = -1;
			}
			j = 0;
		}
		return result;
	}

	char* ChangeToUppercase(char* string)
	{
		for (int i = 0; i < strlen(string); i++)
		{
			if (string[i] >= 'a' && string[i] <= 'z')
			{
				string[i] -= 32;
			}
		}
		return string;
	}

	char* ChangeToLowercase(char* string)
	{
		for (int i = 0; i < strlen(string); i++)
		{
			if (string[i] >= 'A' && string[i] <= 'Z')
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
		char* newString = new char[100];
		int j = 0;
		int newStringIndex = 0;
		for (int i = 0; i < GetLength(string); i++)
		{
			if (string[i] == ':' && (i + 1) % countSpace == 0 && i != 0)
			{
				newStringIndex = newStringIndex - j;
				newString[newStringIndex++] = '\t';
				j = 0;
			}
			else
			{
				newString[newStringIndex++] = string[i];
			}
			if (string[i] == ':')
			{
				j++;
			}
			else
			{
				j = 0;
			}

		}
		newString[newStringIndex] = 0;
		return newString;
	}
	
	char* ReplaceTabsOnSpaces(char* string)
	{
		char* string1 = new char[20];
		int j = 0;
		for (int i = 0; i < strlen(string); i++, j++)
		{
			string1[j] = string[i];
			if (string[i] == '\t')
			{
				if (j % 4 == 0)
				{	
					int temp = j;
					string1[j] = ':';
					while (j != temp + 3)
					{
						j++;
						string1[j] = ':';
					}
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

	lab3::Person ReadPerson()
	{
		lab3::Person newPerson;
		cout << "\nPlease enter name and surname (ex. \"Jack Bauer\"):\n>";
		cin >> newPerson.Name; cin >> newPerson.Surname;
		cout << "\nInsert Sex - Male(M)/Female(F):\n>";
		int n;
		char key = NULL;
		const char escapeSymbol = 27;
		int asciiValue = 0;
		key = _getch();
		asciiValue = key;
		char newKey = key;
		while ((key != 'f') && (key != 'm'))
		{
			cout << ("\nINCORRECT SYMBOL!!!\nPlease, enter (Button 'F' or Button 'M'):\n>");
			newKey = _getch();
			key = newKey;
		}
		asciiValue = newKey;
		switch (asciiValue)
		{
			case 'f':
			{
				cout << 'F';
				newPerson.Gender = Female;
				break;
			}
			case 'm':
			{
				cout << 'M';
				newPerson.Gender = Male;
				break;
		}
		default:
			break;
		}
		return newPerson;

	}

	void PrintPerson(lab3::Person& person)
	{
		cout << "\n\nSurname: " << person.Surname << endl;
		cout << "\nName: " << person.Name << endl;
		switch (person.Gender)
		{
			case 0:
				cout << "\nSexPerson: " << "Male" << endl;
				break;
			case 1:
				cout << "\nSexPerson: " << "Female" << endl;
				break;
		}
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
				<< "\n9. Replace Spaces On Tabs";
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
						cout << "Press Esc to quit the program when after running the program\n\n";
						cout << "\nString:\n>";
						cin >> string;
						cout << "\nLength of string:\n>";
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
						cout << "Press Esc to quit the program when after running the program\n\n";
						cout << "\nFirst string:\n>"; cin >> stringA;
						cout << "\nSecond string:\n>"; cin >> stringB;
						s2 = Concatenate(stringA, stringB);
						for (int i = 0; s2[i] != '\0'; i++)
						{
							cout << s2[i];
						}
						char key = _getch();
						asciiValue = key;
					}
					break;
				}
				case '3':
				{
					
					while (asciiValue != escapeSymbol)
					{
						system("cls");
						char* str;		
						cout << "Press Esc to quit the program when after running the program\n\n";
						str = GetSubstring();
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
						char string = NULL;
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
						cout << "Press Esc to quit the program when after running the program\n\n";
						cout << "\nString:\n>"; cin.getline(string, 100);
						cout << "\nSubstring:\n>"; cin.getline(substring, 100);
						cout << "\nResult:\n>";
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
						cout << "Press Esc to quit the program when after running the program\n\n";
						cout << "Insert string:\n>";; cin.getline(string, 100);
						cout << "\nAfter:\n>";
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
						cout << "Press Esc to quit the program when after running the program\n\n";
						cout << "Insert string:\n>"; cin.getline(string, 100);
						cout << "\nAfter:\n>";
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
						cout << "Press Esc to quit the program when after running the program\n\n";
						cout << "\nWay: "; 
						cin.getline(source, 100, '\n');
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
						cout << "Press Esc to quit the program when after running the program\n\n";
						cout << "Insert string:\n>"; cin.getline(string, 100);
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
						cout << "Press Esc to quit the program when after running the program\n\n";
						char resultOfWork[100];
						cout << "Insert string:\n>";
						cin.getline(resultOfWork, 100);
						cout << "!\t!\t!\t!\t!\t!\n";
						cout << ReplaceSpacesOnTabs(resultOfWork, 8);
						char key = _getch();
						asciiValue = key;
					}
					break;
				}
			}
		}
	}
}

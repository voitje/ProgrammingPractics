#pragma once

enum Sex { Male, Female };

struct Person
{
	char Surname[40];
	char Name[20];
	Sex SexPerson;
};
void MenuPerson();
Person ReadPerson();
void PrintPerson(Person person);
void MenuThirdLaboratory();
int GetLength(char* string);
char* Concatenate(char* stringA, char* stringB);
char* GetSubstring(char* string, int startIndex, int charCount);
int FindSubstring(char* string, char* substring);
char* ChangeToUppercase(char* string);
char* ChangeToLowercase(char* string);
char* ReplaceSpacesOnTabs(char* string, int countSpace);
char* ReplaceTabsOnSpaces(char* string);
void JoingString(char* stringA, char* stringB, int startIndex);

//TODO: Должна быть в отдельном файле
//TODO: Реализуйте перечисление типа пол.

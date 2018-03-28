#pragma once
#include "PersonLab3.h"

namespace lab3
{
	Person ReadPerson();
	void PrintPerson(Person& person);
	void MenuThirdLaboratory();
	int GetLength(char* string);
	char* Concatenate(char* stringA, char* stringB);
	char* GetSubstring();
	int FindSubstring(char* string, char* substring);
	char* ChangeToUppercase(char* string);
	char* ChangeToLowercase(char* string);
	char* ReplaceSpacesOnTabs(char* string, int countSpace);
	char* ReplaceTabsOnSpaces(char* string);
	void JoingString(char* stringA, char* stringB, int startIndex);
	//TODO: Нет такого метода
	bool check();
}


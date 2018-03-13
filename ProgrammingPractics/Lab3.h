#pragma once

void MenuThirdLaboratory();
int GetLength(char* string);
char* Concatenate(char* stringA, char* stringB);
char* GetSubstring(char* string, int startIndex, int charCount);
int FindSubstring(char* string, char* substring);
char* Uppercase(char* string);
char* Lowercase(char* string);
char* ReplaceSpacesOnTabs(char* string);
char* ReplaceTabsOnSpaces(char* string);
struct Person
{
	char Surname[40];
	char Name[20];
};
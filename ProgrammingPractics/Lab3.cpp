#include "stdafx.h"

int GetLength(char* string)
{
	int length = 0;
	for (int i = 0; string[i] != 0; ++i) 
		++length;

	return length;
}
char* Concatenate(char* string1, char* string2) 
{
	char string3[100];
	for (int i = sizeof(string1), j = 0; i < sizeof(string1) + sizeof(string2); i++, j++)
	{
		string3[i] = string2[j];
	}
	for (int i = 0; i < sizeof(string3); i++)
		cout << string3[i];
	return string3;
}
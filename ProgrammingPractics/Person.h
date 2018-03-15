#pragma once
#include "Sex.h"

struct Person
{
	char Surname[40];
	char Name[20];
	Sex Gender;
};

void MenuPerson();
void PrintPerson(Person& person);
Person ReadPerson();
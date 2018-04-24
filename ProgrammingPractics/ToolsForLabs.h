#pragma once
#include "stdafx.h"
#include "SexLab4.h"
#include "Person.h"
#include "PersonLab5.h"
#include "PersonList.h"

void IsAppropriationPerson(string name, string surname, lab4::Sex gender, lab4::Person person);
bool CheckName(string name);
bool CheckSurname(string surname);
void IsAppropriation(string name, string surname, lab4::Sex gender, lab5::Person* person);
lab5::Person* MakeRandomPerson(lab4::Sex tempSex);
void PrintEmptyList();
lab4::Person GetRandomPerson();
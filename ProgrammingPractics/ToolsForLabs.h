#pragma once
#include "stdafx.h"
#include "SexLab4.h"
#include "Person.h"
#include "PersonLab5.h"
#include "PersonList.h"

lab4::Person IsAppropriationPerson(string name, string surname, lab4::Sex gender, lab4::Person person);
bool CheckNameSurname(string name);
void IsAppropriation(string name, string surname, lab4::Sex gender, lab5::Person* person);
lab5::Person* MakeRandomPerson(lab4::Sex tempSex);
void PrintEmptyList();
lab4::Person GetRandomPerson();
string GetSurname(lab4::Sex);
string GetName(lab4::Sex);
string GetParents(string parents, string text);
lab6::Adult* MakeRandomPersonForLabSix(lab4::Sex tempSex);
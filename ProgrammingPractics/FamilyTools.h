#pragma once
#include "stdafx.h"
#include "ChildLab6.h"
#include "PersonList.h"
#include "PersonLab5.h"
#include "ToolsForLabs.h"
#include "AdultLab6.h"

//lab6::Child* GetRandomChild()
//{
//	string MaleName[] =
//	{
//		"Igor", "Semen", "Alexander", "Slavyan", "Mirey",
//		"Andrey", "Boris", "Bogdan", "Vadim", "Vladimir",
//		"Alexey", "Anatoliy", "Vasiliy", "Georgiy", "Genadiy"
//	};
//
//	string MaleSurname[] =
//	{
//		"Borozdin", "Ivanov", "Renev", "Isanov", "Ahanov",
//		"Sobolev", "Morozov", "Almazov", "Derzhavin", "Bogatirev",
//		"Lyubimov", "Voroncov", "Admiralov", "Mayorov", "Gromov"
//	};
//
//	string FemaleName[] =
//	{
//
//		"Yuliya", "Olya", "Viktoriya", "Elizaveta", "Lana",
//		"Anastasiya", "Mariya", "Ekaterina", "Angelina", "Sofya"
//		"Anna", "Varvara", "Irina", "Tatyana", "Kristina"
//	};
//
//	string FemaleSurname[] =
//	{
//		"Kudryavceva", "Evsyukova", "Morozova", "Rukosueva", "Polienko",
//		"Mayer", "Vladova", "Evans", "Brown", "Weber",
//		"Sokolovskaya", "Ellis", "Lemann", "Lewandovskaya", "Smith"
//	};
//
//	const int arrayLength = 15;
//	string tempName;
//	string tempSurname;
//	const int minor = 17;
//	int tempAge = 1 + rand() % minor;
//	lab4::Sex tempSex = lab4::Sex(rand() % 2);
//
//	lab5::Person* tempMother;
//	lab5::Person* tempFather;
//	if (rand() % 3)
//	{
//		tempMother = MakeRandomPerson((lab4::Sex)1);
//	}
//	else
//	{
//		tempMother = nullptr;
//	}
//
//	if (rand() % 3)
//	{
//		tempFather = MakeRandomPerson((lab4::Sex)0);
//	}
//	else
//	{
//		tempFather = nullptr;
//	}
//	if (tempSex)
//	{
//		tempName = FemaleName[rand() % arrayLength];
//		tempSurname = FemaleSurname[rand() % arrayLength];;
//	}
//	else
//	{
//		tempName = MaleName[rand() % arrayLength];
//		tempSurname = MaleSurname[rand() % arrayLength];
//	}
//	return new lab6::Child(tempName, tempSurname, tempAge, tempSex,
//		tempMother, tempFather);
//}
//
//lab6::Adult* GetRandomAdult()
//{
//	string MaleName[] =
//	{
//		"Igor", "Semen", "Alexander", "Slavyan", "Mirey",
//		"Andrey", "Boris", "Bogdan", "Vadim", "Vladimir",
//		"Alexey", "Anatoliy", "Vasiliy", "Georgiy", "Genadiy"
//	};
//	string FemaleName[] =
//	{
//		"Yuliya", "Olya", "Viktoriya", "Elizaveta", "Lana",
//		"Anastasiya", "Mariya", "Ekaterina", "Angelina", "Sofya"
//		"Anna", "Varvara", "Irina", "Tatyana", "Kristina"
//	};
//	string MaleSurname[] =
//	{
//		"Borozdin", "Ivanov", "Renev", "Isanov", "Ahanov",
//		"Sobolev", "Morozov", "Almazov", "Derzhavin", "Bogatirev",
//		"Lyubimov", "Voroncov", "Admiralov", "Mayorov", "Gromov"
//	};
//	string FemaleSurname[] =
//	{
//		"Kudryavceva", "Evsyukova", "Morozova", "Rukosueva", "Polienko",
//		"Mayer", "Vladova", "Evans", "Brown", "Weber",
//		"Sokolovskaya", "Ellis", "Lemann", "Lewandovskaya", "Smith"
//	};
//
//	string WorkPlaces[] =
//	{
//		"programmer in Microsoft",
//		"settler in the settler in the hostel",
//		"consultant in DNS",
//		"accountant in bank",
//		"rescuer in the Ministry of Emergency Situations",
//		"seller in Yarche",
//		"barber in the Big Bro",
//		"football player in Manchester United",
//		"director of the Gazprom"
//	};
//
//	const int arrayLength = 15;
//	const int arrayLengthWorkPlace = 9;
//	string tempName;
//	string tempSurname;
//	string tempWorkPlace;
//	const int minor = 18;
//	const int eld = 80;
//	int tempAge = minor + rand() % eld;
//	enum lab4::Sex tempSex = enum lab4::Sex(rand() % 2);
//	lab5::Person* tempMarriedOn = MakeRandomPerson((lab4::Sex)!tempSex);
//
//	if (rand() % 5)
//	{
//		tempWorkPlace = WorkPlaces[rand() % arrayLengthWorkPlace];
//	}
//	else
//	{
//		tempWorkPlace = "\0";
//	}
//	if (tempSex)
//	{
//		tempName = FemaleName[rand() % arrayLength];
//		tempSurname = FemaleSurname[rand() % arrayLength];
//	}
//	else
//	{
//		tempName = MaleName[rand() % arrayLength];
//		tempSurname = MaleSurname[rand() % arrayLength];
//	}
//	return new lab6::Adult(tempName, tempSurname, tempAge, tempSex,
//		tempMarriedOn, tempWorkPlace);
//}

static string PrintMother(lab5::Person* person)
{
	string mother = person->GetName() + ' ' + person->GetSurname();
	return mother;
}

static string PrintFather(lab5::Person* person)
{
	string father = person->GetName() + ' ' + person->GetSurname();
	return father;
}

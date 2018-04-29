#include "stdafx.h"
#include "ToolsForLabs.h"

lab6::Child* GetRandomChild()
{
	const int arrayLength = 15;
	string tempName;
	string tempSurname;
	const int minor = 17;
	int tempAge = 1 + rand() % minor;
	lab4::Sex tempSex = lab4::Sex(rand() % 2);

	lab5::Person* tempMother;
	lab5::Person* tempFather;
	if (rand() % 3)
	{
		tempMother = MakeRandomPerson((lab4::Sex)1);
	}
	else
	{
		tempMother = nullptr;
	}

	if (rand() % 3)
	{
		tempFather = MakeRandomPerson((lab4::Sex)0);
	}
	else
	{
		tempFather = nullptr;
	}
	if (tempSex)
	{
		tempName = GetName(lab4::Female);
		tempSurname = GetSurname(lab4::Female);
	}
	else
	{
		tempName = GetName(lab4::Male);
		tempSurname = GetSurname(lab4::Male);
	}
	return new lab6::Child(tempName, tempSurname, tempAge, tempSex,
		tempMother, tempFather);
}

lab6::Adult* GetRandomAdult()
{
	string WorkPlaces[] =
	{
		"programmer in Microsoft",
		"settler in the settler in the hostel",
		"consultant in DNS",
		"accountant in bank",
		"rescuer in the Ministry of Emergency Situations",
		"seller in Yarche",
		"barber in the Big Bro",
		"football player in Manchester United",
		"director of the Gazprom"
	};

	const int arrayLength = 15;
	const int arrayLengthWorkPlace = 9;
	string tempName;
	string tempSurname;
	string tempWorkPlace;
	const int minor = 18;
	const int eld = 80;
	int tempAge = minor + rand() % eld;
	enum lab4::Sex tempSex = enum lab4::Sex(rand() % 2);
	lab5::Person* tempMarriedOn = MakeRandomPerson((lab4::Sex)!tempSex);

	if (rand() % 5)
	{
		tempWorkPlace = WorkPlaces[rand() % arrayLengthWorkPlace];
	}
	else
	{
		tempWorkPlace = "\0";
	}
	if (tempSex)
	{
		tempName = GetName(lab4::Female);
		tempSurname = GetSurname(lab4::Female);
	}
	else
	{
		tempName = GetName(lab4::Male);
		tempSurname = GetSurname(lab4::Male);
	}
	return new lab6::Adult(tempName, tempSurname, tempAge, tempSex,
		tempMarriedOn, tempWorkPlace);
}




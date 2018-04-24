#include "stdafx.h"
#include "AdultLab6.h"
#include "PersonList.h"
#include "PersonLab5.h"
#include "ToolsForLabs.h"

namespace lab6
{
	Adult::Adult(string name, string surname, unsigned int age, 
		enum lab4::Sex sex, Person* marriedOn, string workPlace)
	{  
		SetName(name);
		SetSurname(surname);
		SetAge(age);
		SetSex(sex);
		SetMarriedOn(marriedOn);
		SetWorkPlace(workPlace);
	}
	
	void Adult::SetAge(unsigned int age)
	{
		if (age >= 18)
		{
			_age = age;
		}
		else
		{
			char temp = _getch();
			cout << "\nThe entered age does not meet the requirements, by default it will be assigned to 18\n";
			_age = 18;
		}
	}

	void Adult::SetMarriedOn(Person* marriedOn)
	{
		if (marriedOn != nullptr)
		{
			_marriedOn = marriedOn;
		}
	}

	void Adult::SetWorkPlace(string workPlace)
	{
		if (workPlace != "")
		{
			_workPlace = workPlace;
		}
	}

	lab5::Person* Adult::GetMarriedOn()
	{
		return _marriedOn;
	};

	string Adult::GetWorkPlace()
	{
		return _workPlace;
	};

	string Adult::GetDescription()
	{
		string result = Person::GetDescription();
		char* ageStr = new char[10];
		_itoa_s(_age, ageStr, 10, 10);
		result = result + " " + ageStr + " years old,  ";
		delete ageStr;
		if (_marriedOn == nullptr)
		{
			result = result + "single, " + GetWorkPlace();
		}
		else
		{
			result = result + "mirried on, " + GetMarriedOn()->GetName() + " " + 
				GetMarriedOn()->GetSurname() + ", " + GetWorkPlace();
		}
		return result;
	}
	//Я переношу функцию ниже ее в FamilyTools.h делаю исправления и не могу исправить ошибки
	Adult* Adult::GetRandomAdult()
	{
		string MaleName[] =
		{
			"Igor", "Semen", "Alexander", "Slavyan", "Mirey",
			"Andrey", "Boris", "Bogdan", "Vadim", "Vladimir",
			"Alexey", "Anatoliy", "Vasiliy", "Georgiy", "Genadiy"
		};
		string FemaleName[] =
		{
			"Yuliya", "Olya", "Viktoriya", "Elizaveta", "Lana",
			"Anastasiya", "Mariya", "Ekaterina", "Angelina", "Sofya"
			"Anna", "Varvara", "Irina", "Tatyana", "Kristina"
		};
		string MaleSurname[] =
		{
			"Borozdin", "Ivanov", "Renev", "Isanov", "Ahanov",
			"Sobolev", "Morozov", "Almazov", "Derzhavin", "Bogatirev",
			"Lyubimov", "Voroncov", "Admiralov", "Mayorov", "Gromov"
		};
		string FemaleSurname[] =
		{
			"Kudryavceva", "Evsyukova", "Morozova", "Rukosueva", "Polienko",
			"Mayer", "Vladova", "Evans", "Brown", "Weber",
			"Sokolovskaya", "Ellis", "Lemann", "Lewandovskaya", "Smith"
		};

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
			tempName = FemaleName[rand() % arrayLength];
			tempSurname = FemaleSurname[rand() % arrayLength];
		}
		else
		{
			tempName = MaleName[rand() % arrayLength];
			tempSurname = MaleSurname[rand() % arrayLength];
		}
		return new lab6::Adult(tempName, tempSurname, tempAge, tempSex,
			tempMarriedOn, tempWorkPlace);
	}
	Adult::~Adult()
	{
		delete _marriedOn;
		delete &_workPlace;
	}
}
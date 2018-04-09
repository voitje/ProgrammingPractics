﻿#include "stdafx.h"
#include "ChildLab6.h"
#include "PersonList.h"
#include "PersonLab5.h"

namespace lab6
{
	Child::Child(string name, string surname, int age, lab4::Sex sex, Person* mother, Person* father)
	{
		SetName(name);
		SetSurname(surname);
		SetAge(age);
		SetSex(sex);
		SetMother(mother);
		SetFather(father);
	};

	void Child::SetAge(int age)
	{
		if (age <= 17)
		{
			_age = age;
		}
		else
		{
			_age = 17;
		}
	}

	void Child::SetMother(Person* mother)
	{
		_mother = mother;
	}

	void Child::SetFather(Person* father)
	{
		_father = father;
	}

	lab5::Person* Child::GetMother()
	{
		return _mother;
	}

	lab5::Person* Child::GetFather()
	{
		return _father;
	}

	Child* Child::GetRandom()
	{
		string MaleName[] =
		{
			"Igor", "Semen", "Alexander", "Slavyan", "Mirey",
			"Andrey", "Boris", "Bogdan", "Vadim", "Vladimir",
			"Alexey", "Anatoliy", "Vasiliy", "Georgiy", "Genadiy"
		};

		string MaleSurname[] =
		{
			"Borozdin", "Ivanov", "Renev", "Isanov", "Ahanov",
			"Sobolev", "Morozov", "Almazov", "Derzhavin", "Bogatirev",
			"Lyubimov", "Voroncov", "Admiralov", "Mayorov", "Gromov"
		};

		string FemaleName[] =
		{
			"Yuliya", "Olya", "Viktoriya", "ELizaveta", "Lana",
			"Anastasiya", "Mariya", "Ekaterina", "Angelina", "Sof'ya"
			"Anna", "Varvara", "Irina", "Tat'yana", "Kristina"
		};

		string FemaleSurname[] =
		{
			"Kudryavceva", "Evsyukova", "Morozova", "Rukosueva", "Polienko",
			"Mayer", "Vladova", "Evans", "Brown", "Weber",
			"Sokolovskaya", "Ellis", "Lemann", "Lewandovskaya", "Smith"
		};

		string tempName;
		string tempSurname;

		int tempAge = 1 + rand() % 17;
		lab4::Sex tempSex = lab4::Sex(rand() % 2);

		Person* tempMother;
		Person* tempFather;

		if (rand() % 3)
		{
			tempMother = lab5::PersonList::MakeRandomPerson((lab4::Sex)1);
		}
		else
		{
			tempMother = nullptr;
		}

		if (rand() % 3)
		{
			tempFather = lab5::PersonList::MakeRandomPerson((lab4::Sex)0);
		}
		else
		{
			tempFather = nullptr;
		}

		if (tempSex)
		{
			tempName = FemaleName[rand() % 15];
			tempSurname = FemaleSurname[rand() % 15];;
		}
		else
		{
			tempName = MaleName[rand() % 15];
			tempSurname = MaleSurname[rand() % 15];
		}
		return new Child(tempName, tempSurname, tempAge, tempSex, tempMother, tempFather);
	}

	string Child::GetDescriptionChild()
	{
		string result = Person::GetDescription();
		string parents;
		char* ageStr = new char[10];
		_itoa_s(_age, ageStr, 10, 10);
		result = result + " " + ageStr + " years old,  ";
		delete ageStr;

		if (_sex == Male)
		{
			result = result + "Male, ";
		}
		else
		{
			result = result + "Female, ";
		}

		if (_mother == nullptr && _father == nullptr)
		{
			parents = parents + "Parents are not specified…";
		}
		else if (_mother == nullptr)
		{
			parents = parents + "Father is " + _father->GetName() + ' ' + _father->GetSurname() + "\n\n";
		}
		else if (_father == nullptr)
		{
			parents = parents + "Mother is " + _mother->GetName() + ' ' + _mother->GetSurname() + "\n\n";
		}
		else
		{
			parents = parents + "Father is " + _father->GetName() + ' ' + _father->GetSurname();
			parents = parents + "\nMother is " + _mother->GetName() + ' ' + _mother->GetSurname() + "\n\n";
		}

		return result + parents;
	}
}
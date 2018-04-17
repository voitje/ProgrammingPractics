#include "stdafx.h"
#include "ToolsForLabs.h"

void IsAppropriation(string name, string surname, lab4::Sex gender, lab4::Person person)
{
	person.Name = name;
	person.Surname = surname;
	person.Gender = gender;
}
bool CheckName(string name)
{
	if (!(name[0] >= 'A' && name[0] <= 'Z'))
	{
		cout << "\nEnter the correct name(with a capital letter)\n";
		return false;
	}

	int i = 1;
	while (name[i] != '\0')
	{
		if (!(name[i] >= 'a' && name[i] <= 'z'))
		{
			cout << "Enter the correct name (only Latin is accepted)";
			return false;
		}
		i++;
	}
	return true;
}

bool CheckSurname(string surname)
{
	if (!(surname[0] >= 'A' && surname[0] <= 'Z'))
	{
		cout << "\nEnter the correct name(with a capital letter)\n";
		return false;
	}

	int i = 1;
	while (surname[i] != '\0')
	{
		if (!(surname[i] >= 'a' && surname[i] <= 'z'))
		{
			cout << "Enter the correct name (only Latin is accepted)";
			return false;
		}
		i++;
	}
	return true;
}

void IsAppropriation(string name, string surname, lab4::Sex gender, lab5::Person* person)
{
	person->SetName(name);
	person->SetSurname(surname);
	person->SetSex(gender);
}

lab5::Person* MakeRandomPerson(lab4::Sex tempSex)
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
		"Yuliya", "Olya", "Viktoriya", "Elizaveta", "Lana",
		"Anastasiya", "Mariya", "Ekaterina", "Angelina", "Sofya"
		"Anna", "Varvara", "Irina", "Tatyana", "Kristina"
	};

	string FemaleSurname[] =
	{
		"Kudryavceva", "Evsyukova", "Morozova", "Rukosueva", "Polienko",
		"Mayer", "Vladova", "Evans", "Brown", "Weber",
		"Sokolovskaya", "Ellis", "Lemann", "Lewandovskaya", "Smith"
	};

	switch (tempSex)
	{
	case lab4::Male:
	{
		return new lab5::Person(MaleName[rand() % 15], MaleSurname[rand() % 15], (1 + rand() % 100), lab4::Male);
		break;
	}
	case lab4::Female:
	{
		return new lab5::Person(FemaleName[rand() % 15], FemaleSurname[rand() % 15], (1 + rand() % 100), lab4::Female);
		break;
	}
	default:
		break;
	}
}

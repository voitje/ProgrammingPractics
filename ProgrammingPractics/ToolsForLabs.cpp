#include "stdafx.h"
#include "ToolsForLabs.h"

lab4::Person IsAppropriationPerson(string name, string surname, lab4::Sex gender, lab4::Person person)
{
	person.Name = name;
	person.Surname = surname;
	person.Gender = gender;
	return person;
}

bool CheckNameSurname(string name)
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


void IsAppropriation(string name, string surname, lab4::Sex gender, lab5::Person* person)
{
	person->SetName(name);
	person->SetSurname(surname);
	person->SetSex(gender);
}

string GetName(lab4::Sex sex)
{
	switch (sex)
	{
		case(lab4::Male):
			{
				string MaleName[] =
				{
					"Igor", "Semen", "Alexander", "Slavyan", "Mirey",
					"Andrey", "Boris", "Bogdan", "Vadim", "Vladimir",
					"Alexey", "Anatoliy", "Vasiliy", "Georgiy", "Genadiy"
				};
				const int arrayLength = 15;
				return MaleName[rand() % arrayLength];
			}
		case (lab4::Female):
			{
				string FemaleName[] =
				{
					"Yuliya", "Olya", "Viktoriya", "Elizaveta", "Lana",
					"Anastasiya", "Mariya", "Ekaterina", "Angelina", "Sofya"
					"Anna", "Varvara", "Irina", "Tatyana", "Kristina"
				};
				const int arrayLength = 15;
				return FemaleName[rand() % arrayLength];
			}
	}
}

string GetSurname(lab4::Sex sex)
{
	switch (sex)
	{
		case(lab4::Male):
		{
			string MaleSurname[] =
			{
				"Borozdin", "Ivanov", "Renev", "Isanov", "Ahanov",
				"Sobolev", "Morozov", "Almazov", "Derzhavin", "Bogatirev",
				"Lyubimov", "Voroncov", "Admiralov", "Mayorov", "Gromov"
			};
			const int arrayLength = 15;
			return MaleSurname[rand() % arrayLength];
		}
		case (lab4::Female):
		{
			string FemaleSurname[] =
			{
				"Kudryavceva", "Evsyukova", "Morozova", "Rukosueva", "Polienko",
				"Mayer", "Vladova", "Evans", "Brown", "Weber",
				"Sokolovskaya", "Ellis", "Lemann", "Lewandovskaya", "Smith"
			};
			const int arrayLength = 15;
			return FemaleSurname[rand() % arrayLength];
		}
	}
}
lab5::Person* MakeRandomPerson(lab4::Sex tempSex)
{
	const int arrayLength = 15;
	const int oldAge = 100;
	switch (tempSex)
	{
		case lab4::Male:
		{
			return new lab5::Person(GetSurname(lab4::Male), GetName(lab4::Male),
				(1 + rand() % oldAge), lab4::Male);
		}
		case lab4::Female:
		{
			return new lab5::Person(GetSurname(lab4::Female), GetName(lab4::Female),
				(1 + rand() % oldAge), lab4::Female);
		}
		default:
			break;
	}
}

void PrintEmptyList()
{
	char key = _getch();
	char newKey = key;
	while ((key != 'e'))
	{
		cout << ("\nList is empty, press the E button to exit the function.\n>");
		newKey = _getch();
		key = newKey;
	}
}

lab4::Person GetRandomPerson()
{
	lab4::Person newPerson;
	switch (rand() % 2 + 1)
	{
		case 1:
		{
			newPerson = IsAppropriationPerson(GetName(lab4::Male), 
				GetSurname(lab4::Male), lab4::Male, newPerson);
			break;
		}
		case 2:
		{
			newPerson = IsAppropriationPerson(GetName(lab4::Female),
				GetSurname(lab4::Female), lab4::Female, newPerson);
			break;
		}
		default:
			break;
	}
	return newPerson;
}

string GetParents(string parents, string text)
{
	return parents = parents + ' ' + text;
}

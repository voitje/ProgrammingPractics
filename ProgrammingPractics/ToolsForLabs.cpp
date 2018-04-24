#include "stdafx.h"
#include "ToolsForLabs.h"

void IsAppropriationPerson(string name, string surname, lab4::Sex gender, lab4::Person person)
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
	const int arrayLength = 15;
	const int oldAge = 100;
	switch (tempSex)
	{
		case lab4::Male:
		{
			return new lab5::Person(MaleName[rand() % arrayLength],
				MaleSurname[rand() % arrayLength], (1 + rand() % oldAge), lab4::Male);
		}
		case lab4::Female:
		{
			return new lab5::Person(FemaleName[rand() % arrayLength],
				FemaleSurname[rand() % arrayLength], (1 + rand() % oldAge), lab4::Female);
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
	const int arrayLength = 15;
	switch (rand() % 2 + 1)
	{
		case 1:
		{
			// Ќе работают хот€ делают то ниже написанно
			/*IsAppropriationPerson(MaleName[rand() % arrayLength],
				MaleSurname[rand() % arrayLength], lab4::Male, newPerson);*/
			newPerson.Name = MaleName[rand() % arrayLength];
			newPerson.Surname = MaleSurname[rand() % arrayLength];
			newPerson.Gender = lab4::Male;

			break;
		}
		case 2:
		{
			// Ќе работают хот€ делают то ниже написанно
			/*IsAppropriationPerson(FemaleName[rand() % arrayLength],
				FemaleSurname[rand() % arrayLength], lab4::Female, newPerson);*/
			newPerson.Name = FemaleName[rand() % arrayLength];
			newPerson.Surname = FemaleSurname[rand() % arrayLength];
			newPerson.Gender = lab4::Female;
			break;
		}
		default:
			break;
	}
	return newPerson;
}

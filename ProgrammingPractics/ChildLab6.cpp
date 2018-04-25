#include "stdafx.h"
#include "ChildLab6.h"
#include "PersonList.h"
#include "PersonLab5.h"
#include "ToolsForLabs.h"

namespace lab6
{
	//TODO: Длинная строка
	Child::Child(string name, string surname, unsigned int age, lab4::Sex sex, Person* mother, Person* father)
	{//TODO: дублируется между наследниками, устраните.
		SetName(name);
		SetSurname(surname);
		SetAge(age);
		SetSex(sex);
		SetMother(mother);
		SetFather(father);
	};

	void Child::SetAge(unsigned int age)
	{
		if (age <= 17)
		{
			_age = age;
		}
		else
		{
			char temp = _getch();
			cout << "\nThe entered age does not meet the requirements, by default it will be assigned to 18\n";
			_age = 17;
		}
	}

	void Child::SetMother(Person* mother)
	{
		if (mother != nullptr)
		{
			_mother = mother;
		}
	}

	void Child::SetFather(Person* father)
	{
		if (father != nullptr)
		{
			_father = father;
		}
	}

	lab5::Person* Child::GetMother()
	{
		return _mother;
	}

	lab5::Person* Child::GetFather()
	{
		return _father;
	}
	

	string Child::GetDescription()
	{
		string result = Person::GetDescription();
		string parents;
		char* ageStr = new char[10];
		_itoa_s(_age, ageStr, 10, 10);
		result = '@' + result + " " + ageStr + " years old,  ";
		delete ageStr;

		if (_sex == lab4::Male)
		{
			result = result + "Male, ";
		}
		else
		{
			result = result + "Female, ";
		}

		if (_mother == nullptr && _father == nullptr)
		{
			parents = parents + "Parents are not specified…\n\n@";
		}
		if (_mother != nullptr)//TODO: Дублирование так и осталось.
		{
			parents = parents + "Mother is " + PrintMother(_mother) + "\n\n";
		}
		if (_father != nullptr)
		{
			parents = parents + "Father is " + PrintFather(_father) + "\n\n";
		}
		return result + parents;
	}
	//Я переношу функцию ниже ее в FamilyTools.h делаю исправления и не могу исправить ошибки
	//TODO: Решите проблемы с циклическими зависимостями.
	Child* Child::GetRandomChild()
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
		if (tempSex == 1)
		{
			tempName = FemaleName[rand() % arrayLength];
			tempSurname = FemaleSurname[rand() % arrayLength];;
		}
		else
		{
			tempName = MaleName[rand() % arrayLength];
			tempSurname = MaleSurname[rand() % arrayLength];
		}
		return new lab6::Child(tempName, tempSurname, tempAge, tempSex,
			tempMother, tempFather);
	}

	Child::~Child()
	{
		delete _mother;
		delete _father;
		delete &_school;
	}
}

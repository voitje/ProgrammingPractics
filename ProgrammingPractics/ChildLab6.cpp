#include "stdafx.h"
#include "ChildLab6.h"
#include "PersonList.h"
#include "PersonLab5.h"
#include "ToolsForLabs.h"

namespace lab6
{
	
	Child::Child(string name, string surname, unsigned int age,
		lab4::Sex sex, Person* mother, Person* father) : Person(name, surname, age, sex)
	{
		SetAge(age); 
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
		if (_mother != nullptr)//TODO: Дублирование так и осталось. \ Вынес в функцию
		{
			parents = GetParents(parents, "Mother is") + Person::GetDescription() + "\n\n";
		}
		if (_father != nullptr)
		{
			parents = GetParents(parents, "Father is") + Person::GetDescription() + "\n\n";
		}
		return result + parents;
	}

	Child::~Child()
	{
		delete _mother;
		delete _father;
		delete &_school;
	}
}

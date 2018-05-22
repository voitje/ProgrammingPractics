#include "stdafx.h"
#include "PersonLab6.h"
#include "ToolsForLabs.h"
namespace lab6
{
	string Person::GetName()
	{
		return _name;
	}

	string Person::GetSurname()
	{
		return _surname;
	}

	int Person::GetAge()
	{
		return _age;
	}

	void Person::SetName(string name)
	{
		if (CheckNameSurname(name) == true)
		{
			_name = name;
			return;
		}
		cout << "\nEnter the correct name\n";
	}

	lab4::Sex Person::GetSex()
	{
		return _sex;
	}

	void Person::SetSurname(string surname)
	{
		if (CheckNameSurname(surname) == true)
		{
			_surname = surname;
			return;
		}
		cout << "\nEnter the correct surname\n";
	}

	void Person::SetAge(unsigned int age)
	{
		if (age < 0 || age > 100)
		{
			cout << "\nNegative age\n";
			return;
		}
		_age = age;
	}

	void Person::SetSex(lab4::Sex sex)
	{
		_sex = sex;
	}

	string Person::GetDescription()
	{
		return _name + " " + " " + _surname;
	}

	Person::Person(string name, string surname, unsigned int age, enum lab4::Sex sex)
	{
		SetName(name);
		SetSurname(surname);
		SetAge(age);
		SetSex(sex);
	}
}
#include "stdafx.h"
#include "PersonLab5.h"
namespace lab5
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
		_name = name;
	}

	lab4::Sex Person::GetSex()
	{
		return _sex;
	}

	void Person::SetSurname(string surname)
	{
		_surname = surname;
	}

	void Person::SetAge(int age)
	{
		if (age <= 0)
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
		string result = _name + " " + " " + _surname;
		return result;
	}
}
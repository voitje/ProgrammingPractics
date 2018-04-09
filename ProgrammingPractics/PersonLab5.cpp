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
	{//TODO: Нет никакой защиты для поля, всё присваивается без проверок! Нарушается инкапсуляция.
		_name = name;
	}

	lab4::Sex Person::GetSex()
	{
		return _sex;
	}

	void Person::SetSurname(string surname)
	{//TODO: Нет никакой защиты для поля, всё присваивается без проверок! Нарушается инкапсуляция.
		_surname = surname;
	}
	//TODO: Правильнее использовать беззнаковый тип!
	void Person::SetAge(int age)
	{//TODO: Нет ограничения сверху
		//TODO: Возраст может быть = 0!
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
	{//TODO: Можно не создавать отдельную переменную, а сразу возвращать строку.
		string result = _name + " " + " " + _surname;
		return result;
	}
}
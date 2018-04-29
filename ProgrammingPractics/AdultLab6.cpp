#include "stdafx.h"
#include "AdultLab6.h"
#include "PersonList.h"
#include "PersonLab5.h"
#include "ToolsForLabs.h"

namespace lab6
{
	Adult::Adult(string name, string surname, unsigned int age, 
		enum lab4::Sex sex, Person* marriedOn, string workPlace) : Person(name, surname, age, sex)
	{
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

	Adult::~Adult()
	{
		delete _marriedOn;
		delete &_workPlace;
	}
}
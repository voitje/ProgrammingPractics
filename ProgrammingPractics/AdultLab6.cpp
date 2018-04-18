#include "stdafx.h"
#include "AdultLab6.h"
#include "PersonList.h"
#include "PersonLab5.h"
#include "CheckNameSurname.h"
#include "ToolsForLabs.h"

namespace lab6
{
	Adult::Adult(string name, string surname, unsigned int age, enum lab4::Sex sex, Person* marriedOn, string workPlace)
	{//TODO: многое пересекается с children - можно было бы устранить дублирование с помощью конструктора базового класса.
		SetName(name);
		SetSurname(surname);
		SetAge(age);
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
	//TODO: Этот метод не должен быть тут.
	Adult* Adult::GetRandom()
	{
		string MaleName[] = 
		{ 
			"Igor", "Semen", "Alexander", "Slavyan", "Mirey",
			"Andrey", "Boris", "Bogdan", "Vadim", "Vladimir",
			"Alexey", "Anatoliy", "Vasiliy", "Georgiy", "Genadiy" 
		};
		string FemaleName[] = 
		{
			"Yuliya", "Olya", "Viktoriya", "Elizaveta", "Lana",
			"Anastasiya", "Mariya", "Ekaterina", "Angelina", "Sofya"
			"Anna", "Varvara", "Irina", "Tatyana", "Kristina"
		};
		string MaleSurname[] = 
		{
			"Borozdin", "Ivanov", "Renev", "Isanov", "Ahanov",
			"Sobolev", "Morozov", "Almazov", "Derzhavin", "Bogatirev",
			"Lyubimov", "Voroncov", "Admiralov", "Mayorov", "Gromov"
		};
		string FemaleSurname[] = 
		{
			"Kudryavceva", "Evsyukova", "Morozova", "Rukosueva", "Polienko",
			"Mayer", "Vladova", "Evans", "Brown", "Weber",
			"Sokolovskaya", "Ellis", "Lemann", "Lewandovskaya", "Smith"
		};

		string WorkPlaces[] = 
		{
			"programmer in Microsoft", 
			"settler in the settler in the hostel", 
			"consultant in DNS",
			"accountant in bank", 
			"rescuer in the Ministry of Emergency Situations", 
			"seller in Yarche",
			"barber in the Big Bro", 
			"football player in Manchester United", 
			"director of the Gazprom"
		};
		//TODO: Теже дубли и магические числа, которые нужно было исправлять в Person. Исправляйте тут.
		string tempName;
		string tempSurname;
		string tempWorkPlace;
		int tempAge = 18 + rand() % 80;
		enum lab4::Sex tempSex = enum lab4::Sex(rand() % 2);
		Person* tempMarriedOn = MakeRandomPerson((lab4::Sex)!tempSex);

		if (rand() % 5)
		{
			tempWorkPlace = WorkPlaces[rand() % 9];
		}
		else
		{
			tempWorkPlace = "\0";
		}
		if (tempSex)
		{
			tempName = FemaleName[rand() % 15];
			tempSurname = FemaleSurname[rand() % 15];
		}
		else
		{
			tempName = MaleName[rand() % 15];
			tempSurname = MaleSurname[rand() % 15];
		}
		return new Adult(tempName, tempSurname, tempAge, tempSex, tempMarriedOn, tempWorkPlace);
	}//TODO: Пустая строка.

	Adult::~Adult()
	{
		//TODO: Почему адреса указателей?
		delete &_marriedOn;
		delete &_workPlace;
	}
}
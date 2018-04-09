#pragma once
#include "stdafx.h"
#include "PersonList.h"
#include "CheckNameSurname.h"

namespace lab6
{
	class Adult : public lab5::Person
	{
	private:
		Person* _marriedOn = nullptr;
		string _workPlace;
	public://TODO: ��� ����������?
		Adult(string name, string surname, int age, enum lab4::Sex sex, Person* marriedOn, string workPlace);
		string GetDescriptionAdult();
		void SetAge(int age);
		void SetMarriedOn(Person* marriedOn);
		void SetWorkPlace(string workPlace);
		Person* GetMarriedOn();
		string GetWorkPlace();
		//TODO: ����� ������ ��� �� ������ ����!
		static Adult* GetRandom();
	};
}
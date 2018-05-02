#pragma once
#include "stdafx.h"
#include "PersonList.h"


namespace lab6
{
	class Adult : public lab5::Person
	{
	private:
		Person* _marriedOn = nullptr;
		string _workPlace;

	public:
		Adult(string name, string surname, unsigned int age, 
			enum lab4::Sex sex, Person* marriedOn, string workPlace);
		virtual string GetDescription();
		virtual void SetAge(unsigned int age);
		void SetMarriedOn(Person* marriedOn);
		void SetWorkPlace(string workPlace);
		Person* GetMarriedOn();
		string GetWorkPlace();
		Adult::~Adult();
		//TODO: ����� ��� ���?
		//TODO: override  ��������������� func()
		//virtual void func() override;
	};
}
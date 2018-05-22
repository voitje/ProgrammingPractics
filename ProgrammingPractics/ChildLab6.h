#pragma once
#include "stdafx.h"
#include "PersonLab6.h"


namespace lab6
{
	class Child : public Person
	{
		private:
			Person* _mother;
			Person* _father;
			string _school;
		public:
			Child(string name, string surname, unsigned int age, 
				lab4::Sex sex, Person* mother, Person* father);
			virtual string GetDescription() override;
			virtual void SetAge(unsigned int age);
			void SetMother(Person* mother);
			void SetFather(Person* father);
			Person* GetMother();
			Person* GetFather();
			Child::~Child();
	};
}
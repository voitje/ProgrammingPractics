#pragma once
#include "stdafx.h"
#include "PersonLab5.h"

namespace lab6
{
	class Child : public lab5::Person
	{
		private:
			Person* _mother;
			Person* _father;
			string _school;
		public:
			Child(string name, string surname, int age, lab4::Sex sex, Person* mother, Person* father);
			virtual string GetDescription();
			static Child* GetRandom();
			virtual void SetAge(int age);
			void SetMother(Person* mother);
			void SetFather(Person* father);
			Person* GetMother();
			Person* GetFather();
			Child::~Child();
	};
}
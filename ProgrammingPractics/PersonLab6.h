#pragma once
#include "SexLab4.h"
#include "stdafx.h"

namespace lab6
{
	class Person
	{
		protected:
			string _name;
			string _surname;
			unsigned int _age;
			lab4::Sex _sex;
		public:
			string GetName();
			string GetSurname();
			int GetAge();
			lab4::Sex GetSex();
			void SetName(string name);
			void SetSurname(string surname);
			virtual void SetAge(unsigned int age);
			void SetSex(lab4::Sex sex);
			virtual string GetDescription() = 0;
			Person() { };
			Person(string name, string surname, unsigned int age, enum lab4::Sex sex);
	};
}
#pragma once
#include "SexLab4.h"
namespace lab5
{
	//TODO: Если идёт наследование от этого класса - должны ли мы иметь возможность создавать экземпляр класса Person
	//TODO: Имеет ли это смысл?
	class Person
	{
		protected:
			string _name;
			string _surname;
			int _age;
			lab4::Sex _sex;
		public://TODO: Нарушение форматирования, зачем пустые строки между сигнатурами?
			string GetName();

			string GetSurname();

			int GetAge();

			lab4::Sex GetSex();

			void SetName(string name);

			void SetSurname(string surname);

			void SetAge(int age);

			void SetSex(lab4::Sex sex);

			string GetDescription();//TODO: Где конструктор и деструктор?
	};
}
#pragma once
#include "SexLab4.h"
namespace lab5
{
	class Person
	{//TODO: Не по RSDN форматирование \ DONE
		protected:
			//TODO: Публичные поля. Нарушение инкапсуляции! \ DONE
			string _name;
			string _surname;
			int _age;
			lab4::Sex _sex;

			//TODO: Всё что ниже должно быть перенесено в cpp. \ DONE
		public:
			string GetName();

			string GetSurname();

			int GetAge();

			lab4::Sex GetSex();

			void SetName(string name);

			void SetSurname(string surname);

			void SetAge(int age);

			void SetSex(lab4::Sex sex);

			string GetDescription();
	};
}
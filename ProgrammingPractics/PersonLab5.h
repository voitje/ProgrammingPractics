#pragma once
#include "SexLab4.h"
namespace lab5
{
	class Person
	{//TODO: �� �� RSDN �������������� \ DONE
		protected:
			//TODO: ��������� ����. ��������� ������������! \ DONE
			string _name;
			string _surname;
			int _age;
			lab4::Sex _sex;

			//TODO: �� ��� ���� ������ ���� ���������� � cpp. \ DONE
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
#pragma once

namespace lab5
{
	class Person
	{//TODO: �� �� RSDN ��������������
	public:
		//TODO: ��������� ����. ��������� ������������!
		string Name;
		string Surname;
		int Age;
		//TODO: �� ��� ���� ������ ���� ���������� � cpp.
		string GetName()
		{
			return Name;
		}

		string GetSurname()
		{
			return Surname;
		}

		int GetAge()
		{
			return Age;
		}

		void SetName(string name)
		{
			Name = name;
		}

		void SetSurname(string surname)
		{
			Surname = surname;
		}

		void SetAge(int age)
		{
			Age = age;
		}
		//TODO: ����� ���������� ������ � ������ �������, � ������ � �������.
		void Read(Person& person)
		{
			//TODO: �� �� RSDN.
			int age;  string surname; string name;
			cout << "\n���\n>"; cin >> name; person.SetName(name);
			cout << "�������\n>"; cin >> surname; person.SetSurname(surname);
			cout << "�������\n>"; cin >> age; person.SetAge(age);
		}
		//TODO: ����� �������� �����������. ����������, ��� ���� ������ �������� ������ ���������� � ������ ������� ��������, �� �� � ����. 
		//TODO: � ����� ������������ ������ ���������� � ����.
		 void Show(Person& person)
		{
			cout << "\n���\n>" << person.GetName();
			cout << "�������\n>" << person.GetSurname();
			cout << "�������\n>" << person.GetAge();
		}
	};
}
#include "stdafx.h"
#include "PersonLab5.h"
namespace lab5
{
	string Person::GetName()
	{
		return Name;
	}

	string Person::GetSurname()
	{
		return Surname;
	}

	int Person::GetAge()
	{
		return Age;
	}

	void Person::SetName(string name)
	{
		Name = name;
	}

	void Person::SetSurname(string surname)
	{
		Surname = surname;
	}

	void Person::SetAge(int age)
	{
		Age = age;
	}
	//TODO: ����� ���������� ������ � ������ �������, � ������ � �������.
	void Person::Read()
	{
		//TODO: �� �� RSDN. \ DONE
		int age;  
		string surname; 
		string name;
		cout << "\n���\n>"; cin >> name; SetName(name);
		cout << "�������\n>"; cin >> surname; SetSurname(surname);
		cout << "�������\n>"; cin >> age; SetAge(age);
	}
	//TODO: ����� �������� �����������. ����������, ��� ���� ������ �������� ������ ���������� � ������ ������� ��������, �� �� � ����. 
	//TODO: � ����� ������������ ������ ���������� � ����.
	void Person::Show()
	{
		cout << "\n���\n>" << GetName();
		cout << "�������\n>" << GetSurname();
		cout << "�������\n>" << GetAge();
	}
}
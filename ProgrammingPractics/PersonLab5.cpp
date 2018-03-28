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
	//TODO: Метод записывает данные о другом объекте, а должен о текущем.
	void Person::Read()
	{
		//TODO: Не по RSDN. \ DONE
		int age;  
		string surname; 
		string name;
		cout << "\nИмя\n>"; cin >> name; SetName(name);
		cout << "Фамилия\n>"; cin >> surname; SetSurname(surname);
		cout << "Возраст\n>"; cin >> age; SetAge(age);
	}
	//TODO: Метод работает некорректно. Получается, что один объект человека должен рассказать о другом объекте человека, но не о себе. 
	//TODO: А метод предполагает выдачу информации о себе.
	void Person::Show()
	{
		cout << "\nИмя\n>" << GetName();
		cout << "Фамилия\n>" << GetSurname();
		cout << "Возраст\n>" << GetAge();
	}
}
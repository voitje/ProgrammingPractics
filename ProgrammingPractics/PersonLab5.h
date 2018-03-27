#pragma once

namespace lab5
{
	class Person
	{
	public:
		string Name;
		string Surname;
		int Age;
		//Person();

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

		void Read(Person& person)
		{
			int age;  string surname; string name;
			cout << "\nИмя\n>"; cin >> name; person.SetName(name);
			cout << "Фамилия\n>"; cin >> surname; person.SetSurname(surname);
			cout << "Возраст\n>"; cin >> age; person.SetAge(age);
		}

		 void Show(Person& person)
		{
			cout << "\nИмя\n>" << person.GetName();
			cout << "Фамилия\n>" << person.GetSurname();
			cout << "Возраст\n>" << person.GetAge();
		}
	};
}
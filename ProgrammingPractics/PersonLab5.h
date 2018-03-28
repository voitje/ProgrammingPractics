#pragma once

namespace lab5
{
	class Person
	{//TODO: Не по RSDN форматирование
	public:
		//TODO: Публичные поля. Нарушение инкапсуляции!
		string Name;
		string Surname;
		int Age;
		//TODO: Всё что ниже должно быть перенесено в cpp.
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
		//TODO: Метод записывает данные о другом объекте, а должен о текущем.
		void Read(Person& person)
		{
			//TODO: Не по RSDN.
			int age;  string surname; string name;
			cout << "\nИмя\n>"; cin >> name; person.SetName(name);
			cout << "Фамилия\n>"; cin >> surname; person.SetSurname(surname);
			cout << "Возраст\n>"; cin >> age; person.SetAge(age);
		}
		//TODO: Метод работает некорректно. Получается, что один объект человека должен рассказать о другом объекте человека, но не о себе. 
		//TODO: А метод предполагает выдачу информации о себе.
		 void Show(Person& person)
		{
			cout << "\nИмя\n>" << person.GetName();
			cout << "Фамилия\n>" << person.GetSurname();
			cout << "Возраст\n>" << person.GetAge();
		}
	};
}
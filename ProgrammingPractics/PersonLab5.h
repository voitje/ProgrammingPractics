#pragma once

namespace lab5
{
	class Person
	{//TODO: Не по RSDN форматирование \ DONE
		private:
			//TODO: Публичные поля. Нарушение инкапсуляции! \ DONE
			string Name;
			string Surname;
			int Age;
			//TODO: Всё что ниже должно быть перенесено в cpp. \ DONE
		public:
			string GetName();

			string GetSurname();

			int GetAge();

			void SetName(string name);

			void SetSurname(string surname);

			void SetAge(int age);

			void Read();

			void Show();
	};
}
#pragma once

namespace lab5
{
	class Person
	{//TODO: �� �� RSDN �������������� \ DONE
		private:
			//TODO: ��������� ����. ��������� ������������! \ DONE
			string Name;
			string Surname;
			int Age;
			//TODO: �� ��� ���� ������ ���� ���������� � cpp. \ DONE
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
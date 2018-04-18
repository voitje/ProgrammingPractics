#pragma once
#include "PersonLab5.h"

namespace lab5
{
	class PersonListItem
	{
		private:
			Person* _value;
		public:
			PersonListItem(Person* person)
			{
				if (person != nullptr)
				{
					_value = person;
				}
			}
			Person* GetValue()
			{
				return _value;
			}
			PersonListItem* Next = nullptr;
			PersonListItem* Prev = nullptr;
			~PersonListItem()
			{//TODO: Некорректный деструктор, никак не выполняет свою функцию!
				PersonListItem* Next = nullptr;
				PersonListItem* Prev = nullptr;
				_value = nullptr;
			}
	};
}
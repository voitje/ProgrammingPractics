#pragma once
#include "PersonLab6.h"

namespace lab6
{
	class PersonListItem
	{
	private:
		Person * _value;
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
	};
}
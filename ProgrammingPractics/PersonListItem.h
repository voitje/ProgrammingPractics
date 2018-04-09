	#pragma once
#include "PersonLab5.h"

namespace lab5
{
	class PersonListItem
	{
		private:
			Person* Value;
		public:
			PersonListItem(Person* person)
			{
				Value = person;
			}
			Person* GetValue()
			{
				return Value;
			}
			PersonListItem* Next = NULL;
			PersonListItem* Prev = NULL;
	};
}
	#pragma once
#include "PersonLab5.h"

namespace lab5
{
	class PersonListItem
	{
		private://TODO: Именование приватного поля не по RSDN!
			Person* Value;
		public://TODO: Где деструктор?
			PersonListItem(Person* person)
			{//TODO: Никакой защиты приватных полей!
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
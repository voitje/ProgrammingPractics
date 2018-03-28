#pragma once
#include "PersonLab5.h"

namespace lab5
{
	//TODO: В отдельный файл! \ DONE
	class PersonListItem
	{//TODO: Форматирование не по RSDN! \DONE
		public:
			PersonListItem(Person person)
			{
				Value = person;
			}
			Person Value;
			PersonListItem* Next = NULL;
			PersonListItem* Prev = NULL;
	};
}
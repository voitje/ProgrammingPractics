#pragma once
#include "PersonLab5.h"

namespace lab5
{
	//TODO: � ��������� ����! \ DONE
	class PersonListItem
	{//TODO: �������������� �� �� RSDN! \DONE
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
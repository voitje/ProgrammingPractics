	#pragma once
#include "PersonLab5.h"

namespace lab5
{
	class PersonListItem
	{
		private://TODO: ���������� ���������� ���� �� �� RSDN!
			Person* Value;
		public://TODO: ��� ����������?
			PersonListItem(Person* person)
			{//TODO: ������� ������ ��������� �����!
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
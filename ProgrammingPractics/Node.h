#pragma once

#include "Person.h"

namespace lab4
{
	struct Node
	{
		Person Person;
		//TODO: ���������� �� RSDN \ DONE
		Node* NextItem;
		Node* PrevItem;
	};
}
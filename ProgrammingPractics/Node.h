#pragma once

#include "Person.h"

namespace lab4
{
	struct Node
	{
		Person Person;
		Node* NextItem;
		Node* PrevItem;
		int Index = 0;
	};
}
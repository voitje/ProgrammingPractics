#pragma once

#include "Person.h"

namespace lab4
{
	struct Node
	{
		Person Person;
		//TODO: Именование по RSDN \ DONE
		Node* NextItem;
		Node* PrevItem;
	};
}
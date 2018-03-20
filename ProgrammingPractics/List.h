#pragma once

#include "Node.h"

namespace lab4
{
	struct List
	{//TODO: Именование по RSDN \ DONE
		Node* Head;
		Node* Tail;
	};

	void MenuPerson(List* list);
	void Create(List* list);
	Person ReadPerson();
	Person& GetPointer(List* list, int index);
	Person MakeRandomPerson();
	void Add(List* list);
	void Show(List* list);
	void AddForRandomPerson(List* list);
	void Remove(List* list, int index);
	void Insert(List* list, Person& person, int index);
	void ClearList(List* list);
}


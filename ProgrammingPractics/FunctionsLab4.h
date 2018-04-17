#pragma once
#include "Node.h"
#include "List.h"

namespace lab4
{
	void MenuPerson(List* list);
	void Create(List* list);
	Person ReadPerson();
	Node* GetPointer(List* list, int index);
	Person MakeRandomPerson();
	void Add(List* list);
	void Show(List* list);
	void AddRandomPerson(List* list);
	void Remove(List* list, int index);
	void Insert(List* list, Person& person, int index);
	void ClearList(List* list);
	bool IsEmpty(List* list);
}

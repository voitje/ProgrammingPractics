#pragma once

#include "Node.h"

namespace lab4
{
	//TODO: ������ ���� � ��������� �����!
	struct List
	{
		Node* Head;
		Node* Tail;
	};

	void MenuPerson(List* list);
	void Create(List* list);
	Person ReadPerson();
	Node* GetPointer(List* list, int index);
	Person MakeRandomPerson();
	void Add(List* list);
	void Show(List* list);
	void AddForRandomPerson(List* list);
	void Remove(List* list, int index);
	void Insert(List* list, Person& person, int index);
	void ClearList(List* list);
	bool IsEmpty(List* list);
}


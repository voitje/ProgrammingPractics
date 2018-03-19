#pragma once
#include "Sex.h"

struct Person
{
	char Surname[40];
	char Name[20];
	Sex Gender;
	int Age;
	int index = 0;
};

struct Node
{
	Person Person; 
	Node* nextItem; 
	Node* prevItem; 
};

struct List
{
	Node* head;
	Node* tail;
	int count = 0;
};

void MenuPerson(List* list);
void PrintPerson(Person& person);
Person ReadPerson();
void Create(List* list);
void Add(List* list);
void Show(List* list);
Person& GetPointer(List* list, int index);
Person MakeRandomPerson();
void AddForRandomPerson(List* list);
void Remove(List* list, int index);
void Insert(List* list, Person& person, int index);
void ClearList(List* list);


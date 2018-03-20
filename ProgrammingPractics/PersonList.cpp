#include "stdafx.h"
//#include "PersonList.h"
//
//namespace labFive
//{
//	void Add(List* list)
//	{
//		Node *newNode = new Node();
//		newNode->nextItem = nullptr;
//		newNode->Person = ReadPerson();
//		if (list->head != nullptr)
//		{
//			newNode->prevItem = list->tail;
//			list->tail->nextItem = newNode;
//			list->tail = newNode;
//			newNode->Person.index = newNode->prevItem->Person.index + 1;
//		}
//		else
//		{
//			newNode->prevItem = nullptr;
//			list->head = newNode; list->tail = newNode;
//			newNode->Person.index = 0;
//		}
//	};
//}
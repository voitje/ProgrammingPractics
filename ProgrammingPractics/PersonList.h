#pragma once
#include "SexLab4.h"
#include "PersonLab5.h" 
#include "PersonListItem.h"
#include "AdultLab6.h"
#include "ChildLab6.h"

namespace lab5
{	
	class PersonList
	{
		private:
			PersonListItem* _head; 
			PersonListItem* _tail;
			int _count = NULL;
		public:
			void Add(Person* person);
			Person* Find(unsigned int index);
			int IndexOf();
			void Remove(Person* person);
			void RemoveAt(int index);
			void Clear();
			int GetCount();
			void Show();
			PersonListItem* GetHead();
			PersonListItem* GetTail();
			void SetCount();
			void ShowDescriptions();
			PersonList::~PersonList()
			{
				Clear();
			}
	};
}
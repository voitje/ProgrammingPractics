//TODO: Почему отключена директива? \ В двух файлах подключаю
#pragma once
#include "SexLab3.h"
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
			Person* Find(int index);
			int IndexOf();
			void Remove(Person* person);
			void RemoveAt(int index);
			void Clear();
			int GetCount();
			//TODO: перенести из класса \ DONE
			void Show();
			static Person* MakeRandomPerson();
			static Person* MakeRandomPerson(lab4::Sex tempSex);
			//TODO: for убрать \ DONE
			void AddRandomPerson(Person* person);
			PersonListItem* GetHead();
			PersonListItem* GetTail();
			void SetCountList();
			void SetHead(PersonListItem* item);
			void SetTail(PersonListItem* item);
			void ShowDescriptions();
	};
}
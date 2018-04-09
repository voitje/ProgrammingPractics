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
		public://TODO: ��� ����������� � ����������?
			void Add(Person* person);
			Person* Find(int index);
			int IndexOf();
			void Remove(Person* person);
			void RemoveAt(int index);
			void Clear();
			int GetCount();
			void Show();
			//TODO: ��������� �� ������, �� ��� ��������, ������ ���� ������� ����� ���� �� ������.
			static Person* MakeRandomPerson();
			static Person* MakeRandomPerson(lab4::Sex tempSex);
			//TODO: ����� ������ ����� ���� �� ������!
			void AddRandomPerson(Person* person);
			PersonListItem* GetHead();
			PersonListItem* GetTail();
			void SetCountList();
			//TODO: ����� ��� ��� ��� ������?
			void SetHead(PersonListItem* item);
			void SetTail(PersonListItem* item);
			void ShowDescriptions();
	};
}
//TODO: ������ ��������� ���������? \ � ���� ������ ���������
//#pragma once
#include "SexLab3.h"
#include "PersonLab5.h" 
#include "PersonListItem.h"

namespace lab5
{	
	//TODO: � ��������� ����! \ DONE
	class PersonList
	{//TODO: �������������� �� �� RSDN! \ DONE
		private:
			PersonListItem* _head; 
			PersonListItem* _tail;
			int _count = NULL;
		public:
			//TODO: ����� ��� �������� � ����? \ DONE
			void Add(Person& person);
			Person& Find(int index);
			int IndexOf(Person& person);
			void Remove(Person& person);
			void RemoveAt(int index);
			void Clear();
			int GetCount();
			static void MenuForClass(Person& person);
			void Show(Person& person);
			Person MakeRandomPerson();
			void AddForRandomPerson(Person& person);
	};
}
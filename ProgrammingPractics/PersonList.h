//TODO: Зачем этот файл?
//#pragma once
#include "SexLab3.h"
#include "PersonLab5.h"


namespace lab5
{	
	class PersonListItem
	{
	public:
		PersonListItem(Person person)
		{
			Value = person;
		}
		Person Value;
		PersonListItem* Next = NULL;
		PersonListItem* Prev = NULL;
	};

	class PersonList
	{
	private:
		PersonListItem* _head; 
		PersonListItem* _tail;
		int _count = NULL;
	public:
		//PersonList();
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
//TODO: Зачем этот файл?
//#pragma once
//#include "Sex.h"
////#include "Person.h"
//
//
//namespace labFive
//{	
//	
//	class Person
//	{
//	public:
//		char Name[20];
//		char Surname[20];
//		int Age;
//		Sex Gender;
//		Person() {};
//	};
//
//	class PersonListItem
//	{
//	public:
//		PersonListItem(Person person)
//		{
//			Value = person;
//		}
//		Person Value;
//		PersonListItem* Next = NULL;
//		PersonListItem* Prev = NULL;
//	};
//
//	class PersonList
//	{
//	private:
//		PersonListItem* _head; 
//		int _count;
//	public:
//		PersonList();
//		void Add(Person* person);
//		Person* Find(int index);
//		int IndexOf(Person* person);
//		void Remove(Person* person);
//		void RemoveAt(int index);
//		void Clear();
//		int GetCount();
//	};
//}
//TODO: Почему отключена директива? \ В двух файлах подключаю
//#pragma once
#include "SexLab3.h"
#include "PersonLab5.h" 
#include "PersonListItem.h"

namespace lab5
{	
	//TODO: В отдельный файл! \ DONE
	class PersonList
	{//TODO: Форматирование не по RSDN! \ DONE
		private:
			PersonListItem* _head; 
			PersonListItem* _tail;
			int _count = NULL;
		public:
			//TODO: Зачем эти комменты в коде? \ DONE
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
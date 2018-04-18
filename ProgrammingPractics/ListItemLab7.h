#pragma once
#include "stdafx.h"

template <class Type>
class ListItem
{
	private:
		Type _data;
	public:
		ListItem<Type>(Type data)
		{//TODO: Ниже nullptr!
			if (data != NULL)
			{
				_data = data;
			}
		}
		Type GetData()
		{
			return _data;
		}
		ListItem<Type>* Next = nullptr;
		ListItem<Type>* Prev = nullptr;
};

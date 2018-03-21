#pragma once
#include "SexLab3.h"

namespace lab3
{
	//TODO: У вас одинаковые персоны между лабами, почему бы не использовать одну и ту же структуру? 
	struct Person
	{
		char Surname[40];
		char Name[20];
		Sex Gender;
		int Age;
		//TODO: Вообще индекс - это не часть персоны, это часть контейнера, содержащего персону \ DONE
	};
}


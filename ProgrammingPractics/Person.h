#pragma once

#include "SexLab4.h"

namespace lab4
{
	struct Person
	{
		char Surname[40];
		char Name[20];
		Sex Gender;
		int Age;
		//TODO: Вообще индекс - это не часть персоны, это часть контейнера, содержащего персону \ DONE
	};
}


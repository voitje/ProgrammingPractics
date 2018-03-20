#pragma once
#include "SexLab3.h"

namespace lab3
{
	struct Person
	{
		char Surname[40];
		char Name[20];
		Sex Gender;
		int Age;
		//TODO: Именование по RSDN \ DONE
		int Index = 0;
	};
}


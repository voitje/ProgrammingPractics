#pragma once

#include "SexLab4.h"

namespace lab4
{
	//TODO: ������ �������� (������������/���������) ������ ���� � ��������� ����� \ DONE
	struct Person
	{
		char Surname[40];
		char Name[20];
		Sex Gender;
		int Age;
		//TODO: ���������� �� RSDN \ DONE
		int Index = 0;
	};
}


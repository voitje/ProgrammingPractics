#pragma once
#include "SexLab3.h"

namespace lab3
{
	//TODO: � ��� ���������� ������� ����� ������, ������ �� �� ������������ ���� � �� �� ���������?
	struct Person
	{
		char Surname[40];
		char Name[20];
		Sex Gender;
		int Age;
		//TODO: ������ ������ - ��� �� ����� �������, ��� ����� ����������, ����������� �������
		int Index = 0;
	};
}


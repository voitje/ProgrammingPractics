#pragma once
#include "PersonLab5.h"
#include <iostream>

static std::ostream& operator << (std::ostream &os, lab5::Person* person)
{
	os << '(' << person->GetName() << ' ' << person->GetSurname() << ", " << person->GetAge() << ')';
	return os;
}

static ostream & operator <<(ostream & os, double* d)
{
	for (int i = 0; i < 5; i++)
	{
		os << d[i] << ' ';
	}
	return os;
}
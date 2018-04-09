#pragma once
#include "stdafx.h"

static bool CheckNameSurname(string name, string surname)
{
	if (!(name[0] >= 'A' && name[0] <= 'Z') || !(surname[0] >= 'A' && surname[0] <= 'Z'))
	{
		cout << "\nEnter the correct name and surname (with a capital letter)\n";
		return false;
	}

	int i = 1;
	while (name[i] != '\0')
	{
		if (!(name[i] >= 'a' && name[i] <= 'z'))
		{
			cout << "Enter the correct name (only Latin is accepted)";
			return false;
		}
		i++;
	}

	while (surname[i] != '\0')
	{
		if (!(surname[i] >= 'a' && surname[i] <= 'z'))
		{
			cout << "Enter the correct surname (only Latin is accepted)";
			return false;
		}
		i++;
	}
}
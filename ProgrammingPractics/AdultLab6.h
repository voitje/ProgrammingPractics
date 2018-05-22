#pragma once
#include "stdafx.h"
#include "PersonList.h"
#include "PersonLab6.h"


namespace lab6
{
	class Adult : public Person
	{
		private:
			Adult* _marriedOn = nullptr;
			string _workPlace;

		public:
			Adult(string name, string surname, unsigned int age, 
				enum lab4::Sex sex, Adult* marriedOn, string workPlace);
			virtual string GetDescription() override;
			virtual void SetAge(unsigned int age);
			void SetMarriedOn(Adult* marriedOn);
			void SetWorkPlace(string workPlace);
			Adult* GetMarriedOn();
			string GetWorkPlace();
			Adult::~Adult();
	};
}
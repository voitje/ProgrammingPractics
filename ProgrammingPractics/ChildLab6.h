#pragma once
#include "stdafx.h"
#include "PersonLab5.h"

namespace lab6
{
	class Child : public lab5::Person
	{
		private:
			Person* _mother;
			Person* _father;
			string _school;
		public://TODO: Где деструктор?
			Child(string name, string surname, int age, lab4::Sex sex, Person* mother, Person* father);
			string GetDescriptionChild();
			//TODO: Этого метода не должно тут быть!
			static Child* GetRandom();
			void SetAge(int age);
			void SetMother(Person* mother);
			void SetFather(Person* father);
			Person* GetMother();
			Person* GetFather();
	};
}
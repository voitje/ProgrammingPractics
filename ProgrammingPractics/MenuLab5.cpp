#include "stdafx.h"
#include "MenuLab5.h"

namespace lab5
{
	void MenuLabFive()
	{
		HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
		const char escapeSymbol = 27;
		char key;
		int temp = 1;
		int numberCase;
		int asciiValue = 0;
		//Person* person = new Person();
		PersonList p1;

		while (asciiValue != escapeSymbol)
		{
			system("cls");

			SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
			cout.width(12); cout << "Surname:";
			cout.width(12); cout << "Name:";
			cout.width(12); cout << "Age:\n";

			SetConsoleTextAttribute(hStdOut, 2);
			p1.Show();

			SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			cout << "\n------List of Person: Main Menu------"
				<< "\n1. Add Person"
				<< "\n2. Find a person at the specified index"
				<< "\n3. Return the index of the person, if it is in the list"
				<< "\n4. Remove a person from the list"
				<< "\n5. Remove a person from the list by index"
				<< "\n6. Clear List"
				<< "\n7. Get the number of items"
				<< "\n8. Add Random Person"
				<< "\n------List of Person : Main Menu------";

			SetConsoleTextAttribute(hStdOut, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			cout << "\n\n\nChoose action (1-7):\n>";

			key = _getch();
			asciiValue = key;
			/*switch (asciiValue)
			{
				case '1':
				{
					string name;
					string surname;
					cout << "\nPlease enter name and surname (ex. \"Jack Bauer\"):\n>";
					cin >> name; cin >> surname;
					person->SetName(name);
					person->SetSurname(surname);
					if (person->GetName() == "" || person->GetSurname() == "")
					{
						cout << "\nPress any key to continue working\n";
						key = _getch();
						break;
					}
					cout << "\nInsert Sex - Male(M)/Female(F):\n>";
					int n;
					char key = NULL;
					const char escapeSymbol = 27;
					int asciiValue = 0;
					key = _getch();
					asciiValue = key;
					char newKey = key;
					while ((key != 'f') && (key != 'm'))
					{
						cout << ("\nINCORRECT SYMBOL!!!\nPlease, enter (Button 'F' or Button 'M'):\n>");
						newKey = _getch();
						key = newKey;
					}
					asciiValue = newKey;
					switch (asciiValue)
					{
					case 'f':
					{
						cout << 'F';
						person->SetSex(lab4::Female);
						break;
					}
					case 'm':
					{
						cout << 'M';
						person->SetSex(lab4::Male);
						break;
					}
					default:
						break;
					}
					int age;
					cout << "\nInsert Age(0 - 100)\n>";
					cin >> age;
					if (age < 0 || age > 100)
					{
						cout << "\nPress any key to continue working\n";
						key = _getch();
						break;
					}
					person->SetAge(age);
					p1.Add(person);
					cout << "\nPerson added\n";
					break;
				}
				case '2':
				{
					int index;
					cout << "\nInsert index:\n>";
					cin >> index;
					PersonListItem tmp = p1.Find(index);
					cout << "\nName:\n>";
					cout << tmp.GetValue()->GetName();
					cout << "\nSurname:\n>";
					cout << tmp.GetValue()->GetSurname();
					cout << "\nPress any key to continue working\n";
					key = _getch();
					break;
				}
				case '3':
				{
					cout << p1.IndexOf();
					cout << "\nPress any key to continue working\n";
					key = _getch();
					break;
				}
				case '4':
				{
					int index;
					p1.Remove(person);
					cout << "\nPress any key to continue working\n";
					key = _getch();
					break;
				}*/
				/*case '5':
				{
					int index;
					cout << "\nInsert index:\n>";
					cin >> index;
					p1.RemoveAt(index);
					cout << "\nPress any key to continue working\n";
					key = _getch();
					break;
				}
				case '6':
				{
					p1.Clear();
					cout << "\nList is empty";
					cout << "\nPress any key to continue working\n";
					key = _getch();
					break;
				}
				case '7':
				{
					cout << p1.GetCount();
					cout << "\nPress any key to continue working\n";
					key = _getch();
					break;
				}
				case '8':
				{
					enum lab4::Sex tempSex = enum lab4::Sex(rand() % 2);
					p1.Add(MakeRandomPerson(tempSex));
				}*/
			}
		}
	}
//}
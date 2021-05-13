/* Final Project Milestone 1
Module:		Menu
File:		Menu.cpp
Author:		Filipe da Cunha de Freitas
ID:			155737190
Revision History
-----------------------------------------------------------
Date		Reason
12/nov		Developed all functions;
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
*/

#define _CRT_SECURE_NO_WARNINGS
#include "utils.h"
#include "Menu.h"
#include <cstring>
using namespace std;

namespace sdds {
	bool Menu::isValid(int menuChoice) const
	{
		bool isValid = false;
		if (menuChoice >= 0 && menuChoice <= m_noOfSel)
		{
			isValid = true;
		}
		return isValid;
	}
	Menu::Menu(const char* text, int NoOfSelections)
	{
		this->menuOptions(text);
		this->noOfSel(NoOfSelections);
	}

	void Menu::menuOptions(const char* text)
	{
		m_text = new char[strlen(text) + 1];
		strcpy(m_text, text);
	}

	void Menu::noOfSel(int numOfSel)
	{
		m_noOfSel = numOfSel;
	}

	Menu::~Menu()
	{
		delete[] m_text;
	}

	std::ostream& Menu::display(std::ostream& ostr) const
	{
		ostr << m_text << endl;
		ostr << "0- Exit" << endl;
		ostr << "> ";
		return ostr;
	}

	int Menu::userMenuChoice()
	{
		bool validEntry = true;
		int selection = 1000;

		do {
			cin >> selection;
			if (cin.fail())
			{
				cout << "Bad integer value, try again: ";
				validEntry = false;
			}
			else
			{
				if (!isValid(selection))
				{
					cout << "Invalid value enterd, retry[0 <= value <= 3]: ";
					validEntry = false;
				}
				else
				{
					validEntry = true;
				}
			}

			cin.clear();
			cin.ignore(5000, '\n');

		} while (!validEntry);

		return selection;
	}

	int& Menu::operator>>(int& Selection)
	{
		display();
		Selection = userMenuChoice();
		return Selection;
	}

}
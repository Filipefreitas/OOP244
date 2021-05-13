/*
Name: Filipe da Cunha de Freitas
ID: 155737190
email: fda-cunha-de-freitas@myseneca.ca
Date: 2020-10-16
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include "NameTag.h"
using namespace std;

namespace sdds {	
	//default constructor
	NameTag::NameTag()
	{
		setEmpty();
	}

	//constructor with one argument to set the name without extension number
	NameTag::NameTag(const char* name)
	{
		m_name = nullptr;
		setName(name);
		m_extension = 0;
	}

	//constructor with two arguments to set the name and the extension
	NameTag::NameTag(const char* name, long long extension)
	{
		m_name = nullptr;
		setName(name);
		m_extension = 0;
		setExtension(extension);
	}
	
	void NameTag::setEmpty()
	{
		m_name = nullptr;
		m_extension = 0;
	}

	bool NameTag::isEmpty() const
	{	
		bool empty = false;
		if (m_name == nullptr)
		{
			empty = true;
		}
		return empty;
	}

	//Check if extension is within the range >> not used for user input. 
	bool NameTag::isValid(long long extension) const
	{
		bool valid = false;
		long min = 10000;
		long max = 99999;

		if (extension >= min && extension <= max)
		{
			valid = true;
		}
	
		return valid;
	}

	long NameTag::isValid() const

	{
		long long extension;
		bool valid = false;
		char nextChar = char(0);

		do
		{
			valid = true;
			cin >> extension;

			if (cin.fail())
			{
				cout << "Invalid value [10000<=value<=99999]: ";
				cin.clear();
				cin.ignore(3000, '\n');
				valid = false;
			}
			else
			{
				nextChar = cin.get();
				if (nextChar != '\n')
				{
					cout << "Invalid value [10000<=value<=99999]: ";
					cin.ignore(3000, '\n');
					valid = false;
				}
			}

		} while (!valid);
	
		return extension;
	}
	
	void NameTag::setName(const char* Cstr)
	{
		//The name should be kept dynamically; however if the name is longer than 40 characters, only 40 characters should be used.
		//After dynamically allocating the name, you can easily do this by setting the 40th character in the name to null if the length of the name is longer than 40.
		//Also if the name is shorter than 20 characters, it should be printed in 20 spaces.
		if (Cstr != nullptr)
		{
			delete[] m_name;
			
			if (strlen(Cstr) > 40)
			{
				m_name = new char[40 + 1];
				strncpy(m_name, Cstr, 40);					
				m_name[40] = '\0';

			}
			else
			{
				m_name = new char[strlen(Cstr) + 1];
				strcpy(m_name, Cstr);
			}
		}
	}

	void NameTag::setExtension(const long long extension)
	{
		if (isValid(extension))
		{
			m_extension = extension;
		}
		else
		{
			setEmpty();
		}
	}

	void NameTag::addExtension()
	{
		long long extension;
		bool inRange = false;
		
		cout << "Please enter a 5 digit phone extension: ";
		extension = isValid();
		
		do
		{			
			if (isValid(extension))
			{
				break;
			}
			else
			{
				inRange = false;
				cout << "Invalid value [10000<=value<=99999]: ";
				cin >> extension;
			}

		} while (!inRange);

		inRange = true;
		setExtension(extension);

	}

	//Read function should read the name up to the maximum of 40 characters and ignore the rest and then set the name of the NameTag to the entered name.
	NameTag& NameTag::read()
	{
		//variable for user choice of inputing an extension
		char choice;
		bool run = true;
		std::string strName;

		//handling name
		std::cout << "Please enter the name: ";
		cin >> ws;
		std::getline(std::cin, strName);
		const char* name = strName.c_str();
		setName(name);

		//extension option
		while (run)
		{
			bool validChoice = false;
			do
			{
			cout << "Would you like to enter an extension? (Y)es/(N)o: ";
			cin >> choice;
			
				if (choice == 'N' || choice == 'n') {
					validChoice = true;
					m_extension = 0;
					run = false;
				}
				else if (choice == 'Y' || choice == 'y')
				{	
					validChoice = true;
					addExtension();
					run = false;
				}
				else
				{
					cin.clear();
					cin.ignore(3000, '\n');
					validChoice = false;
					cout << "Invalid entry >> ";
				}
			} while (!validChoice);
		};

		return *this;
		}
	
	std::ostream& NameTag::print() const
	{
		
		if (isEmpty())
		{
			//print empty
			cout << "EMPTY NAMETAG!" << endl;
		}
		else
		{
			//print names up to 20 characteres in leght
			if (strlen(m_name) <= 20)
			{
				cout << "************************" << endl;
				cout << "*                      *" << endl;
				cout << "* " << left << setw(20) << setfill(' ') << m_name << " *" << endl;
				cout << "*                      *" << endl;

				if (m_extension == 0)
				{
					cout << "* " << left << setw(20) << "Extension: N/A" << " *" << endl;
				}
				else
				{
					cout << "* Extension: " << left << setw(9) << m_extension << " *" << endl;
				}

				cout << "*                      *" << endl;
				cout << "************************" << endl;
			}

			//print names with more than 20 characteres in leght
			else
			{
				cout << "********************************************" << endl;
				cout << "*                                          *" << endl;
				cout << "* " << left << setw(40) << m_name << " *" << endl;
				cout << "*                                          *" << endl;

				if (m_extension == 0)
				{
					cout << "* " << left << setw(40) << "Extension: N/A" << " *" << endl;
				}
				else
				{
					cout << "* Extension: " << left << setw(29) << m_extension << " *" << endl;
				}
			cout << "*                                          *" << endl;
			cout << "********************************************" << endl;
			}

		}
		
		return cout;
	}

	NameTag::~NameTag()
	{
		delete[] m_name;
	}

}
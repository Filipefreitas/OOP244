/* Final Project Milestone 3
Modelue:	IOAble
File:       IOAble.h
Author:		Filipe da Cunha de Freitas
ID:			155737190
Revision History
-----------------------------------------------------------
Date		Reason
18/nov		Started all functions;
25/nov		Fixing bug, operators == missing;
26/nov		Finish all functions;
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Patient.h"
#include "utils.h"
using namespace std;
namespace sdds {
	Patient::Patient(int ticketNumber, bool fileIO) : m_ticket(ticketNumber)
	{
		this->flag(fileIO);
	}

	Patient::~Patient()
	{
		delete[] m_name;
	}

	void Patient::flag(const bool flag)
	{
		m_IOflag = flag;
	}

	void Patient::fileIO(const bool IOflag)
	{
		m_IOflag = IOflag;
	}

	void Patient::setArrivalTime()
	{		
		m_ticket.resetTime();
	}

	bool Patient::fileIO() const
	{
		return m_IOflag;
	}

	int Patient::number() const
	{
		return m_ticket.number();
	}

	bool Patient::operator==(char compareType) const
	{
		bool compare = false;
		if (type() == compareType)
		{
			compare = true;
		}
		return compare;
	}

	bool Patient::operator==(const Patient& P) const
	{
		bool compare = false;
		if (type() == P.type())
		{
			compare = true;
		}
		return compare;
	}

	Patient::operator Time() const
	{
		int arrivalTime = Time(m_ticket);
		return arrivalTime;
	}

	std::istream& Patient::csvRead(std::istream& istr)
	{
		char Cstr[51];
		istr.get(Cstr, 51, ',');
		delete[] m_name;
		m_name = new char[strlen(Cstr) + 1];
		strcpy(m_name, Cstr);
		istr.ignore(1000, ',');	
		istr >> m_ohip;
		istr.ignore(1000, ',');
		return m_ticket.csvRead(istr);
	}

	std::ostream& Patient::csvWrite(std::ostream& ostr) const
	{
		ostr << type() << "," << m_name << "," << m_ohip << ",";
		return m_ticket.csvWrite(ostr);
	}

	std::ostream& Patient::write(std::ostream& ostr) const
	{
		ostr << m_ticket << endl;
		ostr << m_name << ", OHIP: " << m_ohip;
		return ostr;
	}

	std::istream& Patient::read(std::istream& istr)
	{
		char Cstr[51];

		std::cout << "Name: ";
		istr.get(Cstr, 51, '\n');
		delete[] m_name;
		m_name = new char[strlen(Cstr) + 1];
		strcpy(m_name, Cstr);
		istr.ignore(1000, '\n');

		std::cout << "OHIP: ";

		bool badEntry;
		int value;
		int min_ohip = 100000000;
		int max_ohip = 999999999;

		do 
		{
			badEntry = false;
			istr >> value;
			if (cin.fail()) 
			{
				cout << "Bad integer value, try again: ";
				cin.clear();
				cin.ignore(3000, '\n');
				badEntry = true;
			}
			else
			{
				if (value <= min_ohip || value >= max_ohip)
				{
					cout << "Invalid value enterd, retry[100000000 <= value <= 999999999]: ";
					istr.clear();
					istr.ignore(3000, '\n');
					badEntry = true;
				}
				else
				{
					badEntry = false;
					m_ohip = value;
				}
			}
		} while (badEntry);
		return istr;
	}

	std::ostream& operator<<(std::ostream& ostr, const Patient& I)
	{
		return I.write(ostr);
	}

	std::istream& operator>>(std::istream& istr, Patient& I)
	{
		return I.read(istr);
	}
}
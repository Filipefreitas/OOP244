/* Final Project Milestone 1
Module:		Time
File:		Time.cpp
Author:		Filipe da Cunha de Freitas
ID:			155737190
Revision History
-----------------------------------------------------------
Date		Reason
12/nov		Developed all functions; read function needs to be adjusted
13/nov		Read function fixed
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
*/

#define _CRT_SECURE_NO_WARNINGS
#include "Time.h"
#include "utils.h"
#include <iomanip>
#include <iostream>

namespace sdds {

	Time& Time::reset()
	{
		m_min = sdds::getTime();
		return *this;
	}

	Time::Time(unsigned int min)
	{
		m_min = min;
	}

	int Time::toHours(int time) const
	{
		int hours = time / 60;
		return hours;
	}

	int Time::toMinutes(int time) const
	{
		int minutes = time % 60;
		return minutes;
	}

	int Time::hourToInteger(int time) const
	{
		int intHour = time * 60;
		return intHour;
	}

	std::ostream& Time::write(std::ostream& ostr) const
	{
		int hours, minutes;
		hours = toHours(m_min);
		minutes = toMinutes(m_min);

		ostr << std::setw(2) << std::setfill('0') << hours << ":";
		ostr << std::setw(2) << std::setfill('0') << minutes;

		return ostr;
	}

	std::istream& Time::read(std::istream& istr)
	{
		char delimiter = char(58);
		int hours, minutes;
		int hoursInt = 0, timeInteger = 0;
		istr >> hours;

		if (istr.get() == delimiter)
		{
			istr >> minutes;
			hoursInt = hourToInteger(hours);
			timeInteger = hoursInt + minutes;
			m_min = timeInteger;
		}
		else
		{
			istr.setstate(std::ios::failbit);
		}
		return istr;
	}

	Time::operator int() const
	{
		return m_min;
	}

	Time& Time::operator*=(int val)
	{
		this->m_min = m_min * val;
		return *this;
	}

	Time& Time::operator-=(const Time& D)
	{
		int timeDiff;
		int fixNegative = 1440;
		timeDiff = m_min - D.m_min;
		if (timeDiff >= 0)
		{
			m_min -= D.m_min;
		}
		else
		{
			m_min = m_min - D.m_min + fixNegative;
		}

		return *this;
	}

	Time Time::operator-(const Time& ROperand)
	{
		Time LOperand = *this;
		LOperand -= ROperand;
		return LOperand;
	}

	std::ostream& operator<<(std::ostream& ostr, const Time& T)
	{
		return T.write(ostr);
	}

	std::istream& operator>>(std::istream& istr, Time& T)
	{
		return T.read(istr);
	}
}
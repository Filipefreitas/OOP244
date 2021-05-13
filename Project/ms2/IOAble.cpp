/* Final Project Milestone 2
Modelue:	IOAble
File:       IOAble.cpp
Author:		Filipe da Cunha de Freitas
ID:			155737190
Revision History
-----------------------------------------------------------
Date		Reason
15/nov		Developed all functions;
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
*/

#include <iostream>
#include "IOAble.h"
using namespace std;
namespace sdds {
	std::ostream& IOAble::csvWrite(std::ostream& ostr) const
	{
		return ostr;
	}

	std::istream& IOAble::csvRead(std::istream& istr)
	{
		return istr;
	}

	std::ostream& IOAble::write(std::ostream& ostr) const
	{
		return ostr;
	}

	std::istream& IOAble::read(std::istream& istr)
	{
		return istr;
	}

	IOAble::~IOAble()
	{
	}

	std::ostream& operator<<(std::ostream& ostr, const IOAble& I)
	{
		return I.write(ostr);
	}

	std::istream& operator>>(std::istream& istr, IOAble& I)
	{
		return I.read(istr);
	}

}
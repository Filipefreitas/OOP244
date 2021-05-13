/* Final Project Milestone 4
Modelue:	TriagePatient
File:       TriagePatient.cpp
Author:		Filipe da Cunha de Freitas
ID:			155737190
Revision History
-----------------------------------------------------------
Date		Reason
27/nov		Started all functions;
28/nov		Fixed bug in read Fcuntion;
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
*/

#define _CRT_SECURE_NO_WARNINGS
#include "TriagePatient.h"
#include <cstring>

using namespace std;
namespace sdds {
	int nextTriageTicket = 1;

	TriagePatient::TriagePatient() : Patient(nextTriageTicket)
	{
		m_symptoms = nullptr;
		nextTriageTicket++;
	}

	TriagePatient::~TriagePatient()
	{
		delete[] m_symptoms;
	}

	char TriagePatient::type() const
	{
		return 'T';
	}

	std::istream& TriagePatient::csvRead(std::istream& istr)
	{

		delete[] m_symptoms;
		Patient::csvRead(istr);
		istr.ignore(1, ',');
		char Cstr[511];
		istr.get(Cstr, 511, '\n');
		m_symptoms = new char[strlen(Cstr) + 1];
		strcpy(m_symptoms, Cstr);
		nextTriageTicket = Patient::number() + 1;
		return istr;

	}

	std::ostream& TriagePatient::csvWrite(std::ostream& ostr) const
	{
		Patient::csvWrite(ostr);
		ostr << "," << m_symptoms;
		return ostr;
	}

	std::ostream& TriagePatient::write(std::ostream& ostr) const
	{
		if (fileIO())
		{
			csvWrite(ostr);
		}
		else
		{
			ostr << "TRIAGE" << endl;
			Patient::write(ostr) << endl;
			ostr << "Symptoms: " << m_symptoms << endl;
		}
		return ostr;
	}

	std::istream& TriagePatient::read(std::istream& istr)
	{
		if (fileIO())
		{
			csvRead(istr);
		}
		else
		{
			delete[] m_symptoms;
			Patient::read(istr);
			cout << "Symptoms: ";
			char Cstr[511];
			istr.getline(Cstr, 511, '\n');
			m_symptoms = new char[strlen(Cstr) + 1];
			strcpy(m_symptoms, Cstr);

		}
		return istr;
	}
}
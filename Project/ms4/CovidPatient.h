/* Final Project Milestone 4
Modelue:	Covid
File:       CovidPatient.h
Author:		Filipe da Cunha de Freitas
ID:			155737190
Revision History
-----------------------------------------------------------
Date		Reason
27/nov		Developed all functions;
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
*/

#ifndef SDDS_COVIDPATIENT_H_
#define SDDS_COVIDPATIENT_H_
#include "Patient.h"
namespace sdds {

	class CovidPatient : public Patient
	{
	public:
		CovidPatient();
		virtual char type() const;

		std::ostream& csvWrite(std::ostream& ostr) const;
		std::istream& csvRead(std::istream& istr);
		std::ostream& write(std::ostream& ostr) const;
		std::istream& read(std::istream& istr);
	};
}
#endif // !SDDS_COVIDPATIENT_H_


/* Final Project Milestone 4
Modelue:	TriagePatient
File:       TriagePatient.h
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

#ifndef SDDS_TRIAGE_H
#define SDDS_TIRAGE_H
#include <iostream>
#include "Patient.h"
namespace sdds {
   class TriagePatient : public Patient
   {
   private:
	   char* m_symptoms;

   public:
	   TriagePatient();
	   ~TriagePatient();
	   virtual char type() const;

	   std::ostream& csvWrite(std::ostream& ostr) const;
	   std::istream& csvRead(std::istream& istr);
	   std::ostream& write(std::ostream& ostr) const;
	   std::istream& read(std::istream& istr);
   };

}
#endif // !SDDS_



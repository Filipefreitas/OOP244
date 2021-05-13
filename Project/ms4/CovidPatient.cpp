/* Final Project Milestone 4
Modelue:	Covid
File:       CovidPatient.cpp
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

#include "CovidPatient.h"
#include <cstring>

using namespace std;
namespace sdds {
   int nextCovidTicket = 1;

   CovidPatient::CovidPatient() : Patient(nextCovidTicket)
   {
	   nextCovidTicket ++;
   }

   char CovidPatient::type() const
   {
		return 'C';
   }

   std::istream& CovidPatient::csvRead(std::istream& istr)
   {
	   Patient::csvRead(istr);
	   nextCovidTicket = Patient::number() +1;
	   return istr;
   }

   std::ostream& CovidPatient::csvWrite(std::ostream& ostr) const
   {
	   Patient::csvWrite(ostr);
	   return ostr;
   }

   std::ostream& CovidPatient::write(std::ostream& ostr) const
   {
	   if (fileIO() == true)
	   {
		   csvWrite(ostr);
	   }
	   else
		{
		   ostr << "COVID TEST" << endl;
		   Patient::write(ostr) << endl;
	   }
	   return ostr;
   }

   std::istream& CovidPatient::read(std::istream& istr)
   {
	   if (fileIO())
		{
		   csvRead(istr);
	   }
	   else
	   {
		   Patient::read(istr);
	   }
	   return istr;
   }
}
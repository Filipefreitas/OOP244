/* Final Project Milestone 3
Modelue:	Patient
File:       Patient.h
Author:		Filipe da Cunha de Freitas
ID:			155737190
Revision History
-----------------------------------------------------------
Date		Reason
18/nov		Started all functions;
25/nov		Fixing bug, operators == missing;
26/nov		Finish all functions;
28/nov		Remove unnecessary functions left by mistake;
28/nov		Fix mistake at type function;
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
*/

#include <iostream>
#include "IOAble.h"
#include "Ticket.h"
#ifndef SDDS_PATIENT_H_
#define SDDS_PATIENT_H_

namespace sdds {
	class Patient : public IOAble 
	{
		private: 
			char* m_name = nullptr;
			int m_ohip;
			Ticket m_ticket;
			bool m_IOflag;

		public:
			Patient(int ticketNumber = 0, bool fileIO = false);
			~Patient();
		
			bool fileIO() const;
			void fileIO(const bool IOflag);
			void flag(const bool flag);
			void setArrivalTime();
	
			bool operator==(char compareType) const;
			bool operator==(const Patient&) const;

			Patient& operator=(const Patient&) = delete;
			operator Time() const;
			int number() const;

			virtual char type() const = 0;

			std::ostream& csvWrite(std::ostream& ostr) const;
			std::istream& csvRead(std::istream& istr);
			std::ostream& write(std::ostream& ostr) const;
			std::istream& read(std::istream& istr);
	};

}
#endif // !SDDS_PATIENT_H_



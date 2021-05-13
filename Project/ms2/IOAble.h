/* Final Project Milestone 2
Modelue:	IOAble
File:       IOAble.h
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

#ifndef SDDS_IOABLE_H_
#define SDDS_IOABLE_H_
#include <iostream>
namespace sdds {
   class IOAble {
   public:
	   virtual std::ostream& csvWrite(std::ostream& ostr) const = 0;
	   virtual std::istream& csvRead(std::istream& istr);
	   virtual std::ostream& write(std::ostream& ostr) const = 0;
	   virtual std::istream& read(std::istream& istr);
	   virtual ~IOAble();

   };

	   std::istream& operator>>(std::istream& istr, IOAble& I);
	   std::ostream& operator<<(std::ostream& ostr, const IOAble& I);

}
#endif // !SDDS_IOABLE_H_

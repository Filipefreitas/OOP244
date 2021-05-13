/* Final Project Milestone 1
Modelue:	Time
File:       Time.h
Author:		Filipe da Cunha de Freitas
ID:			155737190
Revision History
-----------------------------------------------------------
Date		Reason
12/nov		Developed all functions;
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
*/

#ifndef SDDS_TIME_H
#define SDDS_TIME_H
#include <iostream>
namespace sdds {
    class Time {
        unsigned int m_min;
    public:
        Time& reset();
        Time(unsigned int min = 0);
        std::ostream& write(std::ostream& ostr) const;
        std::istream& read(std::istream& istr);
        operator int()const;
        Time& operator *= (int val);
        Time& operator-=(const Time& D);
        Time operator-(const Time& ROperand);

        int toHours(int time) const;
        int toMinutes(int time) const;
        int hourToInteger(int time) const;

    };
    // helper operator << and >> prototypes
    std::istream& operator>>(std::istream& istr, Time& T);
    std::ostream& operator<<(std::ostream& ostr, const Time& T);
}

#endif // !SDDS_TIME_H
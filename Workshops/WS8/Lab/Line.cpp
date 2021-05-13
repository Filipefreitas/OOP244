/*
Filipe da Cunha de Freitas
155737190
2020-11-19
I have done all the coding by myselfand only copied the code that my professor provided to complete my workshopsand assignments.
*/
#define _CRT_SECURE_NO_WARNINGS

#include "Line.h"

using namespace std;

namespace sdds {
    Line::Line()  
    {
        m_length = 0;
    }

    Line::Line(const char* Cstr, int length) : LblShape(Cstr)
    {
        m_length = length;
    }

    void Line::draw(std::ostream &ostr) const{
        //If the Rectangle is not in an empty state, this function will draw a rectangle with a label inside as follows, otherwise, it will do nothing:
        //If the m_length member variable is greater than zero and the label() is not null, this function will first print the label() and then go to new line. Afterwards it keeps printing the '=' (assignment character) to the value of the m_length member variable.
          //      Otherwise, it will take no action

        int size = m_length;
        if(size > 0 && label() != nullptr) 
        {
            ostr << label() << '\n';
            for (int i = 0; i < size; ++i) {
                ostr << '=';
            }
        }
    }

    void Line::getSpecs(std::istream &istr)
    {
        LblShape::getSpecs(istr);
        istr >> m_length;
        istr.ignore(1000,'\n');
    }
}

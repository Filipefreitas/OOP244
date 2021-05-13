/*
Filipe da Cunha de Freitas
155737190
2020-11-19
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#define _CRT_SECURE_NO_WARNINGS

#include "Rectangle.h"
#include <cstring>

using namespace std;
namespace sdds {
    Rectangle::Rectangle() 
    {
    }

    Rectangle::Rectangle(const char *Cstr, int width, int height) : LblShape(Cstr) 
    {
        m_height = height;
        m_width = width;
        
        int sizeOfLabel = strlen(label()) + 2;
        if (m_height < 3 && m_width < sizeOfLabel)
        {
            m_width = 0;
            m_height= 0;
        }
    }

    void Rectangle::draw(std::ostream &ostr)const{
        //If the Rectangle is not in an empty state, this function will draw a rectangle with a label inside as follows, otherwise, it will do nothing:
        if(m_width > 0 && label() != nullptr && m_height > 0) {
            int i, j;
            ostr << "+";
            for (i = 0; i < m_width - 2; ++i) 
            {
                ostr << '-';
            }
            ostr << "+" << "\n";

            int printLine = m_width - 2;
            ostr << "|";
            ostr << left;
            ostr.width(printLine);
            ostr << label();
            ostr << "|" << "\n";

            for (i = 0; i < m_height- 3; ++i)
            {
                ostr << "|";
                for (j = 0; j< m_width - 2; ++j) 
                {
                    ostr << " ";
                }
                ostr << "|" << "\n";
            }
            
            ostr << "+";
            for (i = 0; i < m_width - 2; ++i) 
            {
                ostr << '-';
            }
            ostr << "+";
        }

    }

    void Rectangle::getSpecs(std::istream &istr) 
    {
        LblShape::getSpecs(istr);
        istr >> m_width;
        istr.ignore(1000, ',');
        istr >> m_height;
        istr.ignore(1000,'\n');

        int sizeOfLabel = strlen(label()) + 2;
        if (m_height < 3 && m_width < sizeOfLabel)
        {
            m_width = 0;
            m_height = 0;

        }
    }
}
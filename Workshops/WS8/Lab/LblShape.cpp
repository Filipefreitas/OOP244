/*
Filipe da Cunha de Freitas
155737190
2020-11-19
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
This code was finished timely and sent by email to the professor, with the correct output, but with a memory leak that only now was fixed. Submitting 
*/
#define _CRT_SECURE_NO_WARNINGS

#include <cstring>
#include "LblShape.h"

using namespace std;
namespace sdds {
    LblShape::LblShape()
    {
    }

    LblShape::LblShape(const char* Cstr)
    {
        m_label = new char[strlen(Cstr) + 1];
        strcpy(m_label, Cstr);
    }
    
    void LblShape::getSpecs(std::istream &istr)
    {
        char Cstr[21];
        istr.get(Cstr, 21, ',');
        delete[] m_label;
        m_label = new char[strlen(Cstr) + 1];
        strcpy(m_label, Cstr);
        istr.ignore(1000,',');
    }

    const char* LblShape::label() const 
    {
        return m_label;
    }

    LblShape::~LblShape()
    {
        delete[] m_label;
    }

}
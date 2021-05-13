/*
Filipe da Cunha de Freitas
155737190
2020-11-19
I have done all the coding by myselfand only copied the code that my professor provided to complete my workshopsand assignments.
*/

#ifndef SDDS_LINE_H
#define SDDS_LINE_H

#include "LblShape.h"

namespace sdds {
    class Line : public LblShape {
        int m_length;

    public:
        Line();
        Line(const char *Cstr, int length);
        void draw(std::ostream &ostr) const;
        void getSpecs(std::istream &istr);
    };
}
#endif // !SDDS_LINE_H


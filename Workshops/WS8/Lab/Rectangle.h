/* dec
Filipe da Cunha de Freitas
155737190
2020-11-19
I have done all the coding by myselfand only copied the code that my professor provided to complete my workshopsand assignments.
*/

#ifndef SDDS_RECTANGLE_H
#define SDDS_RECTANGLE_H

#include "LblShape.h"

namespace sdds {
    class Rectangle : public LblShape {
        int m_height = 0;
        int m_width = 0;

    public:
        Rectangle();
        Rectangle( const char *Cstr, int width, int height);
        void draw(std::ostream &ostr)const;
        void getSpecs(std::istream &istr);
    };
}
#endif



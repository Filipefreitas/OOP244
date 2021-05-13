/*
Filipe da Cunha de Freitas
155737190
2020-11-19
I have done all the coding by myselfand only copied the code that my professor provided to complete my workshopsand assignments.
*/
#define _CRT_SECURE_NO_WARNINGS

#include "Shape.h"

namespace sdds {
    std::ostream &operator<<(std::ostream &ostr, const Shape &S){
        S.draw(ostr);
        return ostr;
    }

    std::istream &operator>>(std::istream &istr, Shape &S){
        S.getSpecs(istr);
        return istr;
    }
}
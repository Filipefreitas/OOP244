/*
Filipe da Cunha de Freitas
155737190
2020-11-19
I have done all the coding by myselfand only copied the code that my professor provided to complete my workshopsand assignments.
*/
#ifndef SDDS_SHAPE_H
#define SDDS_SHAPE_H

#include <iostream>

namespace sdds {
    class Shape {
    public:
        virtual ~Shape() {};
        virtual void draw(std::ostream &ostr) const = 0;
        virtual void getSpecs(std::istream &istr) = 0;
    };
    std::ostream& operator<<(std::ostream& ostr, const Shape& S);
    std::istream& operator>>(std::istream& istr, Shape& S);

}

#endif // !SDDS_SHAPE_H


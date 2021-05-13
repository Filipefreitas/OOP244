/*
Filipe da Cunha de Freitas
155737190
2020-11-19
I have done all the coding by myselfand only copied the code that my professor provided to complete my workshopsand assignments.
*/

#ifndef SDDS_LBLSHAPE_H
#define SDDS_LBLSHAPE_H

#include "Shape.h"

namespace sdds {
    class LblShape : public Shape {
    public:
        LblShape();
        LblShape(const char *Cstr);
        void getSpecs(std::istream &istr);
        ~LblShape();

        //Deleted Actions
        LblShape(const LblShape&) = delete;
        LblShape& operator=(const LblShape &) = delete;
    
    protected:
        const char *label() const;

    private:
        char *m_label = nullptr;

    };
}
#endif // !SDDS_LBLSHAPE_H



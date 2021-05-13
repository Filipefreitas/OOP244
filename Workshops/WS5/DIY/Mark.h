/*
Name: Filipe da Cunha de Freitas
ID: 155737190
Email: fda-cunha-de-freitas@myseneca.ca
Date: 2020-10-27
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#ifndef SDDS_MARK_H_
#define SDDS_MARK_H_
#include <iostream>

namespace sdds {
    class Mark {
        int m_mark;
        int m_valid;

        void setEmpty();
        void setValid();
        void setInvalid();
        bool isValid(int value);
        void correctContent();
    public:
        Mark();
        Mark(int mark);

        operator bool()const;
        operator int() const;
        operator double()const;
        operator char()const;
        bool operator~() const;

        Mark& operator=(int value);
        Mark& operator+=(int value);

        double getMark() const;
    };

    double operator+=(int& value, const Mark& RightOperand);

}
#endif // SDDS_MARK_H_
/*
Name: Filipe da Cunha de Freitas
ID: 155737190
Email: fda-cunha-de-freitas@myseneca.ca
Date: 2020-10-27
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Mark.h"

using namespace std;
namespace sdds {
    void Mark::setEmpty() {
        m_mark = 0;
        setValid();
    }

    void Mark::setValid()
    {
        m_valid = 1;
    }

    void Mark::setInvalid()
    {
        m_valid = 0;
    }
    
    Mark::Mark()
    {
        m_mark = 0;
        setValid();
    }

    Mark::Mark(int mark) {
        setEmpty();
        bool valid = isValid(mark);
        if (valid && bool(m_valid))
        {
            m_mark = mark;
        }
        else
        {
            setInvalid();
        }
    }

    bool Mark::isValid(int value) 
    {
        int minMark = 0;
        int maxMark = 100;
        bool valid = false;

        if (value >= minMark && value <= maxMark)
        {
            valid = true;
        }
        return valid;
    }

    void Mark::correctContent()
    {
        m_mark = 0;
        setInvalid();
    }

    Mark::operator bool()const
    {
        return m_valid != 0;
    }

    Mark::operator double()const
    {
        int GPA = -1;
        if (!bool(m_valid))
        {
            GPA = 0;
        }
        else if (m_mark >= 0 && m_mark < 50)
        {
            GPA = 0;
        }
        else if (m_mark >= 50 && m_mark < 60)
        {
            GPA = 1;
        }
        else if (m_mark >= 60 && m_mark < 70)
        {
            GPA = 2;
        }
        else if (m_mark >= 70 && m_mark < 80)
        {
            GPA = 3;
        }
        else if (m_mark >= 80 && m_mark <= 100)
        {
            GPA = 4;
        }
        else
        {
            GPA = 0;
        }
        return GPA;
    }

    Mark::operator int() const
    {
        return m_mark;
    }

    Mark::operator char()const
    {
        char GPA = -1;

        if (!bool(m_valid))
        {
            GPA = char(88);
        }
        else if (m_mark >= 0 && m_mark < 50)
        {
            GPA = char(70);
        }
        else if (m_mark >= 50 && m_mark < 60)
        {
            GPA = char(68);
        }
        else if (m_mark >= 60 && m_mark < 70)
        {
            GPA = char(67);
        }
        else if (m_mark >= 70 && m_mark < 80)
        {
            GPA = char(66);
        }
        else if (m_mark >= 80 && m_mark <= 100)
        {
            GPA = char(65);
        }
        else
        {
            GPA = char(88);
        }
        return GPA;
    }

    bool Mark::operator~() const
    {
        bool newMark = false;
        if (m_valid == 1)
        {
            newMark = true;
        }
        return newMark;
    }

    Mark& Mark::operator=(int value)
    {
        bool valid = isValid(value);

        if (!valid)
        {
            setEmpty();
            setInvalid();
        }
        else
        {
            setValid();
            m_mark = value;
        }
        return *this;
    }
    
    Mark& Mark::operator+=(int value)
    {
        int sumMark = m_mark += value;
        bool validValue = isValid(value);
        bool validsum = isValid(sumMark);

        if (m_valid == 0 || !validValue || !validsum)
        {
            correctContent();
        }      
    return *this;
    }

    double Mark::getMark() const
    {
        return m_mark;
    }

    double operator+=(int& value, const Mark& RightOperand)
    {
        value += RightOperand.getMark();
        return value;
    }

}
/*
Name: Filipe da Cunha de Freitas
ID: 155737190
email: fda-cunha-de-freitas@myseneca.ca
Date: 2020-10-16
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cstring>
#include "Box.h"
using namespace std;

namespace sdds {
    //Default constructor
    Box::Box()
    {
        m_width = 12;   
        m_height = 12;
        m_length = 12;
        m_contentName = nullptr;
        m_contentVolume = 0;
    }

    //cubical box constructor
    Box::Box(int sideLength, const char* contentName)
    {
        m_contentName = nullptr;
        if (sideLength < 5 || sideLength > 36)
        {
            setUnusable();
        }
        else
        {
            m_width = sideLength;
            m_height = sideLength;
            m_length = sideLength;
            m_contentVolume = 0;
            setName(contentName);
        }
    };

    //free style box constructor
    Box::Box(int width, int height, int length, const char* contentName)
    {
        m_contentName = nullptr;
        if (width < 5 || width > 36 || height < 5 || height > 36 || length < 5 || length > 36)
        {
            setUnusable();
        }
        else
        {
            m_width = width;
            m_height = height;
            m_length = length;
            m_contentVolume = 0;
            setName(contentName);
        }
    }

    void Box::setName(const char* Cstr)
    {
        if (Cstr != nullptr)
        {
            delete[] m_contentName;
            m_contentName = new char[strlen(Cstr) + 1];
            strcpy(m_contentName, Cstr);
        }
    }

    void Box::setUnusable()
    {
        delete[] m_contentName;
        m_contentName = nullptr;
        m_width = -1;
        m_height = -1;
        m_length = -1;
        m_contentVolume = -1;
    }

    bool Box::isUnusable()const
    {
        bool isUnusable = false;
        if (m_width == -1 || m_height == -1 || m_length == -1 || m_contentVolume == -1)
        {
            isUnusable = true;
        }
        return isUnusable;
    }

    bool Box::hasContent() const
    {
        bool hasCotent = false;
        if (m_contentVolume > 0 || Box::quantity() > 0)
        {
            hasCotent = true;
        }
        return hasCotent;
    }

    int Box::capacity() const
    {
        int volume;
        volume = m_width * m_height * m_length;
        return volume;        
    }

    int Box::quantity() const
    {
        return m_contentVolume;
    }

    Box& Box::setContent(const char* contentName)
    {
        setName(contentName);
        
        if (hasContent() && m_contentName == nullptr)
        {
            setUnusable();
        }
        return *this;
    }

    std::ostream& Box::display() const
    {
        if (!isUnusable())
        {
            if (m_contentName == nullptr)
            {
                cout << fixed << left << setw(30) << setfill('.') << "Empty box" << "  ";
            }
            else
            {
                cout << fixed << left << setw(30) << setfill('.') << m_contentName << "  ";
            }

            cout << fixed << right << setw(2) << setfill('0') << m_width << "x";
            cout << fixed << right << setw(2) << setfill('0') << m_height << "x";
            cout << fixed << right << setw(2) << setfill('0') << m_length << "  ";
            cout << fixed << right << setw(6) << setfill(' ') << quantity() << "/";
            cout << fixed << right << capacity() << " C.I.";

        }
        else
        {
            cout << "Unusable box, discard the content, and recycle.";
        }
        return cout;
    }

    Box& Box::add(int i)
    {
        if (i > 0 && i <= capacity())
        {
            m_contentVolume += i;
        }
        else
        {
            setUnusable();
        }
        return *this;
    }

    Box& Box::add(Box& B)
    {
        if (m_contentName == nullptr || quantity() == 0) {
            setContent(B.m_contentName);
        }
        
        if (strcmp(m_contentName, B.m_contentName) == 0) {
            if (quantity() + B.quantity() <= capacity()) {
                add(B.quantity());
                B.m_contentVolume = 0;
            }
            else {
                B.m_contentVolume -= (capacity() - quantity());
                m_contentVolume = capacity();
            }
        }
        else {
            if (quantity() + B.quantity() <= capacity()) {
                B.m_contentVolume = 0;
            }
            else {
                B.m_contentVolume -= (capacity() - quantity());
            }
            setUnusable();
        }
        return *this;
    }

    Box::~Box()
    {
        delete[] m_contentName;
    }

}

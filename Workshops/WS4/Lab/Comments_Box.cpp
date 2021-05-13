#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Box.h"
using namespace std;

namespace sdds {
    //Default constructor
    Box::Box()
    {
        m_width = 12; //< -- - Remove all the data types!!!
        m_height = 12;
        m_length = 12;
        m_contentName = nullptr; //< -- - NO!a data member!the type is char*;
        m_contentVolume = 0;
    }

    //cubical box constructor    
    Box::Box(int sideLength, const char* contentName)
    {
        m_contentName = nullptr; //< -- - NO!a data member!

        if (sideLength < 5 || sideLength > 36)
        {
            setUnusable();
        }
        else
        {
            m_width = sideLength; //< -- - Remove all the data types!!!
            m_height = sideLength;
            m_length = sideLength;
            m_contentVolume = 0;
            setName(contentName);
        }
    };


    //free style box constructor    
    Box::Box(int width, int height, int length, const char* contentName)
    {
        const char* m_contentName = nullptr;

        if (m_width < 5 || m_width > 36 || m_height < 5 || m_height > 36 || m_length < 5 || m_length > 36)
        {
            setUnusable();
        }
        else
        {
            m_width = width; //< -- - Remove all the data types!!!
            m_height = height;
            m_length = length;
            m_contentVolume = 0;
            setName(contentName);
        }
    }

    void Box::setName(const char* Cstr)
    {
        if (m_contentName != nullptr) //< -- - NO!logic: if m_contentName != nullptr;
        {
            delete[] m_contentName;
            m_contentName = new char[strlen(Cstr) + 1];
            strcpy(m_contentName, Cstr);
        }
    }

    void Box::setUnusable()
    {
        delete[] m_contentName;
        m_contentName = nullptr; //< -- - Remove all the data types!!!
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
        if (Box::quantity() > 0)
        {
            hasCotent = true;
        }
        return hasCotent;
    }

    int Box::capacity() const
    {
        int volume;
        volume = m_width * m_height * m_length; //< -- - Remove all the data types!!!
        return volume;
    }

    int Box::quantity() const
    {
        return m_contentVolume;
    }

    Box& Box::setContent(const char* contentName)
    {//sets the content name to the parameter using the set name function 

        setName(contentName); //< -- - NO!Are you trying to call setName() ?


        if (hasContent() && *contentName != '\0' && contentName != nullptr);
        {
            setUnusable();
        }
        return *this;
    }

    std::ostream& Box::display() const
    {
        if (!isUnusable())
        {
            cout << &Box::m_contentName;
            cout << &Box::m_width << "x" << &Box::m_height << "x" << &Box::m_length;
            cout << &Box::quantity << "/" << &Box::capacity << "C.I." << endl;
        }
        else
        {
            cout << "Unusable box, discard the content, and recycle.";
        }
        return cout;
    }

    Box& Box::add(int quantity)
    {
        if (quantity > 0 && quantity <= capacity())
        {
            m_contentVolume += quantity;
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
        //delete[] Box;
    }

}

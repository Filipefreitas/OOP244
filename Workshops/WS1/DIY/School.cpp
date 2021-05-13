/*
Name: Filipe da Cunha de Freitas
Email: fda-cunha-de-freitas@myseneca.ca
ID: 155737190
Date: 2020-10-28
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#include <iostream>
#include "School.h"
#include "File.h"
#include <cstring>
using namespace std;
using namespace sdds;

namespace sdds {

    Phonebook phonebook[24];

    bool loadContacts() {
        Phonebook pb;
        int mnum = 0;
        bool valid = true;
        if (openFile("school.dat")) {
            while (valid && mnum < 24) {
                valid = readCode(pb.schoolCode) && readExtension(&pb.schoolExt);
                if (valid)
                {
                    phonebook[mnum++] = pb;
                }
            }
            closeFile();
        } 
        else 
        {
            cout << "File failed to open" << endl;
        }
        return mnum == 24;
    }

    bool hasCode(const Phonebook* pb, const char code[])
    {
        int i = 0;
        bool found = false;
    
        if (strcmp(pb[i].schoolCode, code) == 0)
        {
            found = true;
        }
        return found;
    }

    void display(const char code[])
    {
        int i;
        int indexFound = -1;

        for (i = 0; i < 24; i++)
        {
            if (hasCode(&phonebook[i], code))
            {
                indexFound = i;
                break;
            }
        }

        if (indexFound != -1)
        {
            cout << "416 491 5050 x " << phonebook[i].schoolExt << endl;
        }
        else
        {
            cout << code << " School code not found!" << endl;
        }
    }
}
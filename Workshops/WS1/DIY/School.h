/*
Name: Filipe da Cunha de Freitas
Email: fda-cunha-de-freitas@myseneca.ca
ID: 155737190
Date: 2020-10-28
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#ifndef SDDS_SCHOOL_H__
#define SDDS_SCHOOL_H__

namespace sdds {

    struct Phonebook {
        char schoolCode[5];
        int schoolExt;
    };

    bool loadContacts();
    bool hasCode(const Phonebook* pb, const char code[]);
    void display(const char code[]);
}

#endif 
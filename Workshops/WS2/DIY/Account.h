/*
Name: Filipe da Cunha de Freitas
Student ID: 155737190
Email: fda-cunha-de-freitas@myseneca.ca
Date: 2020-10-30
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#ifndef SDDS_ACCOUNT_H_
#define SDDS_ACCOUNT_H_

#define DATAFILE "accounts_prof.csv"

namespace sdds {

    struct Account {
        int m_accNumber;
        double m_balance;
    };

    void sort();
    bool load(const char Cstr[]);
    bool load(Account& acc);
    void display(const Account& acc);
    void display();
    void deallocateMemory();

}
#endif // SDDS_ACCOUNT_H_
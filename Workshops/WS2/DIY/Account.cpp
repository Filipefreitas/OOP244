/*
Name: Filipe da Cunha de Freitas
Student ID: 155737190
Email: fda-cunha-de-freitas@myseneca.ca
Date: 2020-10-30
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Account.h"
#include "File.h"
#include <cstring>
using namespace std;

namespace sdds {

    int noOfAccounts;
    Account* accounts;
  
    void sort() {
        int i, j;
        Account temp;
        for (i = noOfAccounts - 1; i > 0; i--) {
            for (j = 0; j < i; j++) {
                if (accounts[j].m_balance > accounts[j + 1].m_balance) {
                    temp = accounts[j];
                    accounts[j] = accounts[j + 1];
                    accounts[j + 1] = temp;
                }
            }
        }
    }

    bool load(Account& acc)
    {
        bool ok = false;
        
        if (read(acc.m_accNumber) && read(acc.m_balance)) {
            if (ok)
            {
                ok = true;
            }
        }
        return ok;
    }

    bool load(const char Cstr[])
    {
        bool ok = false;
        int mnum = 0;
        if (openFile(DATAFILE))
        {
            noOfAccounts = noOfRecords();

            accounts = new Account[noOfAccounts];

            for (int i = 0; i < noOfAccounts; i++)
            {
                load(accounts[i]);
                mnum++;
            }

            if (mnum != noOfAccounts)
            {
                cout << "Error: incorrect number of records read; the data is possibly corrupted" << endl;
            }
            else
            {
                ok = true;
            }

            closeFile();
        }

        else
        {
            cout << "Could not open data file: thedatafilename.whatever" << endl;
        }
        return ok;
    }

    void display(const Account& acc)
    {
        cout << acc.m_accNumber << ":  " << acc.m_balance << endl;
    }

    void display()
    {
        sort();
        cout << "Account#: Balance" << endl;
        for (int i = 0; i < noOfAccounts; i++)
        {
            cout << i + 1 << ": ";
            display(accounts[i]);
        }
    }

    void deallocateMemory()
    {
        delete[] accounts;
    }
}
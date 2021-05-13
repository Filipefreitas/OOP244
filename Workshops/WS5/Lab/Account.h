/*
Name: Filipe da Cunha de Freitas
ID: 155737190
Email: fda-cunha-de-freitas@myseneca.ca
Date: 2020-10-23
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#ifndef SDDS_ACCOUNT_H_
#define SDDS_ACCOUNT_H_
#include <iostream>

namespace sdds {
    class Account {
        int m_number;
        double m_balance;
        void setEmpty();
        void correctContent();
    public:
        Account();
        Account(int number, double balance);
        std::ostream& display()const;
        operator bool()const;
        operator int()const;
        operator double()const;
        bool operator~() const;

        Account& operator=(Account& RightOperand);
        Account& operator=(int value);

        Account& operator+=(double value);
        Account& operator+=(const Account& RightOperand);
        Account& operator-=(double value);

        double getBalance() const;
    };
    
    double operator+(const Account& LeftOperand, const Account& RightOperand);
    double operator+=(double& LeftOperand, const Account& RightOperand);

}
#endif // SDDS_ACCOUNT_H_
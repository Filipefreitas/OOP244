/*
Name: Filipe da Cunha de Freitas
ID: 155737190
Email: fda-cunha-de-freitas@myseneca.ca
Date: 2020-10-23
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Account.h"

using namespace std;
namespace sdds {
    void Account::setEmpty() {
        m_number = -1;
        m_balance = 0.0;
    }
    // New account
    Account::Account() {
        m_number = 0;
        m_balance = 0.0;
    }
    Account::Account(int number, double balance) {
        setEmpty();
        if (number >= 10000 && number <= 99999
            && balance > 0) {
            m_number = number;
            m_balance = balance;
        }
    }
    std::ostream& Account::display() const {
        if (*this) {
            cout << "Acc#: ";
            if (~(*this))
                cout << "Not Set";
            else
                cout << " " << m_number << " ";
            cout << ", Balance: ";
            cout.width(12);
            cout.precision(2);
            cout.setf(ios::right);
            cout.setf(ios::fixed);
            cout << m_balance;
            cout.unsetf(ios::right);
            // I (Fardad) removed the "return cout", this was a mistake
            // (copied and pasted by mistake)
            // and had no effect to the execution of the program.
            // As mentioned before we should have only
            // one return statement in a function.
        }
        else {
            cout << "Invalid Account";
        }
        return cout;
    }

    void Account::correctContent() {
        long minAccountNumber = 10000;
        long maxAccountNumber = 99999;

        if (m_number < minAccountNumber || m_number > maxAccountNumber) setEmpty();
        if (m_number == -1);
    }

    //returns true if the account is valid and otherwise false. This operator can not modify the account object.
    Account::operator bool()const
    {
        return m_number != -1;
    }

    //returns the account number.This operator can not modify the account object.
    Account::operator int()const
    {
        return m_number;
    }

    //returns the account number.This operator can not modify the account object.
    Account::operator double()const
    {
        return m_balance;
    }

    bool Account::operator~() const
    {
        bool newAccount = false;
        if (m_number == 0)
        {
            newAccount = true;
        }
        return newAccount;
    }

    Account& Account::operator=(Account& RightOperand)
    {        
        long minAccountNumber = 10000;
        long maxAccountNumber = 99999;

        if (RightOperand.m_number > minAccountNumber && RightOperand.m_number < maxAccountNumber)
        {

            if (operator bool())
            {
                m_balance = RightOperand.m_balance;
                RightOperand.m_balance = 0;
            }
        }
        return *this;
    }

    
    Account& Account::operator=(int value)
    {
        long minAccountNumber = 10000;
        long maxAccountNumber = 99999;

        if (value < minAccountNumber || value > maxAccountNumber)
        {
            setEmpty();
        }
        else
        {
            m_number = value;
        }
        return *this;
    }
    
    Account& Account::operator+=(double value)
    {
        correctContent();
        if (value > 0)
        {
            m_balance += value;
        }
        return *this;
    }
    

    Account& Account::operator+=(const Account& RightOperand)
    {
        correctContent();
        if (RightOperand.m_balance > 0)
        {
            m_balance += RightOperand.m_balance;
        }
        return *this;
    }

    Account& Account::operator-=(double value)
    {
        correctContent();
        if (m_balance > value && value > 0)
        {
            m_balance -= value;
        }
        return *this;
    }
   
    double Account::getBalance() const
    {
        return m_balance;
    }
    
    double operator+(const Account &LeftOperand, const Account &RightOperand)
    {
        double sum;
        sum = LeftOperand.getBalance() + RightOperand.getBalance();
        return sum;
    }
    
    double operator+=(double &value, const Account& RightOperand)
    {
        value += RightOperand.getBalance();
        return value;        
    }
}
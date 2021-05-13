/*
Name: Filipe da Cunha de Freitas
Email: fda-cunha-de-freitas@myseneca.ca
ID: 155737190
Date: 2020-10-28
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#include <iostream>
#include "School.h"
using namespace std;
using namespace sdds;

void flushkeys() {
    while (cin.get() != '\n');
}

bool yes() {
    char ch = cin.get();
    flushkeys();
    return ch == 'y' || ch == 'Y';
}

int main() {
    bool done = false;
    char code[6];
    loadContacts();
    cout << "Seneca School Extension search." << endl << endl;
    while (!done) {
        cout << "Enter the School code: ";
        cin >> code;
        flushkeys();
        display(code);
        cout << "Do another search? (Y)es: ";
        done = !yes();
        cout << endl;
    }
    cout << "Goodbye!" << endl;
    return 0;
}

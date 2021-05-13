/*
Name: Filipe da Cunha de Freitas
Student ID: 155737190
Email: fda-cunha-de-freitas@myseneca.ca
Date: 2020-10-30
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include "File.h"
using namespace std;

namespace sdds {
    FILE* fptr;
    
    bool openFile(const char filename[]) {
        fptr = fopen(filename, "r");
        return fptr != NULL;
    }
    
    
    int noOfRecords() {
        int noOfRecs = 0;
        char ch;
        while (fscanf(fptr, "%c", &ch) == 1) {
            noOfRecs += (ch == '\n');
        }
        rewind(fptr);
        return noOfRecs;
    }

    void closeFile() {
        if (fptr) fclose(fptr);
    }

    bool read(int& accNumber)
    {
        return fscanf(fptr, "%d,", &accNumber) == 1;
    }
    
    bool read(double& accBalance)
    {
        return fscanf(fptr, "%lf\n", &accBalance) == 1;
    }

}
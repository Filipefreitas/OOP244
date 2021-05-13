/*
Name: Filipe da Cunha de Freitas
Email: fda-cunha-de-freitas@myseneca.ca
ID: 155737190
Date: 2020-10-28
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "File.h"
using namespace std;
using namespace sdds;

namespace sdds {
 
    FILE* fptr;

    // opens the data file and returns true is successful
    bool openFile(const char filename[]) {
        fptr = fopen(filename, "r");
        return fptr != NULL;
    }

    // closes the data file
    void closeFile() {
        if (fptr) fclose(fptr);
    }

    // returns true if successful
    bool readCode(char code[]) {
        return fscanf(fptr, "%s", code) == 1;
    }

    // returns true if successful
    bool readExtension(int* extension) {
        return fscanf(fptr, "%d", extension) == 1;
    }

}



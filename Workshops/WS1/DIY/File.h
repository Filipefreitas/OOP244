/*
Name: Filipe da Cunha de Freitas
Email: fda-cunha-de-freitas@myseneca.ca
ID: 155737190
Date: 2020-10-28
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#define _CRT_SECURE_NO_WARNINGS
#ifndef SDDS_FILE_H 
#define SDDS_FILE_H

namespace sdds {

	bool openFile(const char filename[]);
	void closeFile();
	bool readCode(char code[]);
	bool readExtension(int* extension);

};

#endif
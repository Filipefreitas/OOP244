/*
Name: Filipe da Cunha de Freitas
Student ID: 155737190
Email: fda-cunha-de-freitas@myseneca.ca
Date: 2020-10-30
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#ifndef SDDS_FILE_H_
#define SDDS_FILE_H_

namespace sdds {
	bool openFile(const char filename[]);
	void closeFile();
	int noOfRecords();

	bool read(int& accNumber);
	bool read(double& accBalance);
}
#endif // !SDDS_FILE_H_


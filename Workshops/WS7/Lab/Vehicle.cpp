/*
Filipe da Cunha de Freitas
155737190
2020-11-10
I have done all the coding by myselfand only copied the code that my professor provided to complete my workshopsand assignments.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iomanip>
#include "Vehicle.h"
using namespace std;

namespace sdds {	
	Vehicle::Vehicle(const char* plate, int year, const char* address)
	{
		this->licensePlate(plate);
		this->address(address);
		this->year(year);
	}

	void sdds::Vehicle::moveTo(const char* address)
	{
		if(m_address != address)
		{
			cout << "|" << right << setw(8) << m_licensePlate;
			cout << "| |" << right << setw(20) << m_address;
			cout << " ---> " << left << setw(20) << address << "|" << endl;
			strcpy(m_address, address);
		}
	}

	void Vehicle::licensePlate(const char* plate)
	{
		strncpy(m_licensePlate, plate, 8);
		m_licensePlate[8] = char(0);
	}

	void Vehicle::address(const char* address)
	{
		strncpy(m_address, address, 63);
		m_address[63] = char(0);
	}

	void Vehicle::year(int year)
	{
		m_year = year;
	}

	Vehicle::~Vehicle()
	{
	}

	std::ostream& sdds::Vehicle::write(std::ostream& os) const
	{
		os << "| " << m_year << " | " << m_licensePlate << " | " << m_address;
		return os;
	}

	std::istream& sdds::Vehicle::read(std::istream& in)
	{
		cout << "Built year: ";
		in >> m_year;
		in.ignore(5000, '\n');

		char tempPlate[8];
		cout << "License plate: ";
		in.get(tempPlate, 8);
		in.ignore(5000, '\n');
		strcpy(m_licensePlate, tempPlate);

		char tempLocation[63];
		cout << "Current location: ";
		in.get(tempLocation, 63);
		in.ignore(5000, '\n');
		strcpy(m_address, tempLocation);

		return in;
	}

	std::ostream& operator<<(std::ostream& ostr, const Vehicle& V)
	{
		return V.write(ostr);
	}

	std::istream& operator>>(std::istream& istr, Vehicle& V)
	{
		return V.read(istr);
	}

}


/*
Filipe da Cunha de Freitas
155737190
2020-11-10
I have done all the coding by myselfand only copied the code that my professor provided to complete my workshopsand assignments.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include "Truck.h"

using namespace std;

namespace sdds {
	Truck::Truck(const char* plateNumber, const int year, float capacity, const char* address) : Vehicle(plateNumber, year)
	{
		m_capacity = capacity;
		m_cargo = 0;
		moveTo(address);
	}
	bool Truck::addCargo(double cargo)
	{
		bool add = false;
		double newCargo = m_cargo + cargo;
		if (m_cargo != m_capacity)
		{
			if(newCargo > m_capacity)
			{			
				m_cargo = m_capacity;
				add = true;
			}
			else
			{
				m_cargo = newCargo;
				add = true;
			}
		}
		return add;
	}

	bool Truck::unloadCargo()
	{
		bool unload = !(m_cargo == 0);
		m_cargo = 0;
		return unload;
	}

	std::ostream& Truck::write(std::ostream& os)const
	{
		Vehicle::write(os);
		os << " | " << m_cargo << "/" << m_capacity;
		return os;
	}

	std::istream& Truck::read(std::istream& in) {
		Vehicle::read(in);
		std::cout << "Capacity: ";
		in >> m_capacity;
		std::cout << "Cargo: ";
		in >> m_cargo;

		return in;
	}

	std::ostream& operator<<(std::ostream& ostr, const Truck& T)
	{
		T.write(ostr);
		return ostr;
	}

	std::istream& operator>>(std::istream& istr, Truck& T)
	{
		T.read(istr);
		return istr;
	}
}


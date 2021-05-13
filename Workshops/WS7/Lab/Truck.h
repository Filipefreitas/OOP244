/*
Filipe da Cunha de Freitas
155737190
2020-11-10
I have done all the coding by myselfand only copied the code that my professor provided to complete my workshopsand assignments.
*/

#ifndef __TRUCK_H_
#define __TRUCK_H_

#include <iostream>
#include <cstring>
#include "Vehicle.h"

namespace sdds {

    class Truck : public Vehicle
    {
        float m_capacity;
        float m_cargo;

    public:
        Truck(const char* plate, const int year, float capacity, const char* address);

        bool addCargo(double cargo);
        bool unloadCargo();
        std::ostream& write(std::ostream& os) const;
        std::istream& read(std::istream& in);
    };

    std::istream& operator>>(std::istream& istr, Truck& T);
    std::ostream& operator<<(std::ostream& ostr, const Truck& T);

}

#endif
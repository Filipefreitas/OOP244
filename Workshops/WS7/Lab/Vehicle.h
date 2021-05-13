/*
Filipe da Cunha de Freitas
155737190
2020-11-10
I have done all the coding by myselfand only copied the code that my professor provided to complete my workshopsand assignments.
*/

#ifndef __VEHICLE_H_
#define __VEHICLE_H_
#include <iostream>

namespace sdds {

    class Vehicle
    {
        char m_licensePlate[9];
        char m_address[64];
        int m_year;

    public:
        Vehicle(const char* plate, int year, const char* address = "Factory");
        void moveTo(const char* address);
        std::ostream& write(std::ostream& os) const;
        std::istream& read(std::istream& in);

        void licensePlate(const char* plate);
        void address(const char* address);
        void year(int year);

        ~Vehicle();

    };
    
    std::istream& operator>>(std::istream& istr, Vehicle& V);
    std::ostream& operator<<(std::ostream& ostr, const Vehicle& V);
}

#endif
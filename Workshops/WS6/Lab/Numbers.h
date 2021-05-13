/*
Filipe da Cunha de Freitas
155737190
2020-11-08
I have done all the coding by myselfand only copied the code that my professor provided to complete my workshopsand assignments.
*/

#ifndef SDDS_NUMBERS_H_
#define SDDS_NUMBERS_H_
#include <iostream>
namespace sdds {
    class Numbers {
        double* m_numbers;
        char* m_filename;
        bool m_isOriginal;
        int m_numCount;
        bool isEmpty()const;
        void setEmpty();
        void setFilename(const char* filename);
        void sort();
        int numberCount();
        bool load();
        void save();
    public:
        Numbers();
        Numbers(const char* filename);
        Numbers(const Numbers&);
        Numbers& operator=(const Numbers& src);
        Numbers& operator+=(const double number);
        std::ostream& display(std::ostream& ostr) const;
        double average()const;
        double max()const;
        double min()const;
        ~Numbers();
    };
    std::ostream& operator<< (std::ostream& os, const Numbers& N);
    std::istream& operator>> (std::istream& istr, Numbers& N);
}
#endif // !SDDS_NUMBERS_H_
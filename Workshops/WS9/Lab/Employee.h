/*
Filipe da Cunha de Freitas
155737190
2020-11-25
I have done all the coding by myselfand only copied the code that my professor provided to complete my workshopsand assignments.
*/

#include <iostream>
#ifndef SDDS_EMPLOYEE_H_
#define SDDS_EMPLOYEE_H_
#include "ReadWrite.h"
namespace sdds {
   class Employee : public ReadWrite {
      int _empno;
      char _name[41];
      double _salary;
   public:
      Employee();
      Employee(int stno, const char* name, double salary);
      void set(int stno, const char* name, double salary);
      std::ostream& display(std::ostream& os)const;
      std::istream& read(std::istream& is);
      bool operator==(const char* nameSubstr)const;
   };


}
#endif // !SDDS_EMPLOYEE_H_
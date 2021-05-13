/*
Filipe da Cunha de Freitas
155737190
2020-11-25
I have done all the coding by myselfand only copied the code that my professor provided to complete my workshopsand assignments.
*/

#include <iostream>
#ifndef SDDS_STUDENT_H_
#define SDDS_STUDENT_H_
#include "ReadWrite.h"
namespace sdds {
   class Student : public ReadWrite {
      int _stno;
      char _name[41];
   public:
      Student();
      Student(int stno, const char* name);
      void set(int stno, const char* name);
      std::ostream& display(std::ostream& os)const;
      std::istream& read(std::istream& is);
      bool operator==(const char* nameSubstr)const;
   };
}
#endif // !SDDS_STUDENT_H_


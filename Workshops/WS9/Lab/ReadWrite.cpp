/*
Filipe da Cunha de Freitas
155737190
2020-11-25
I have done all the coding by myselfand only copied the code that my professor provided to complete my workshopsand assignments.
*/

#include <iostream>
#include "ReadWrite.h"
using namespace std;
namespace sdds {
   ostream& operator<<(ostream& os, const ReadWrite& c) {
      return c.display(os);
   }

   istream& operator >> (istream& is, ReadWrite& c) {
      return c.read(is);
   }
}
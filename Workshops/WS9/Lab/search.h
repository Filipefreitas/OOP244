/*
Filipe da Cunha de Freitas
155737190
2020-11-25
I have done all the coding by myselfand only copied the code that my professor provided to complete my workshopsand assignments.
*/

#include <iostream>
#include <string>

using namespace std;
using namespace sdds;

template<class Templ>
bool search(Templ arrayItens[], int nArrayItens, const char *Cstr, Collection<Templ> *result) {
    string name;
    bool returnBool = false;
    for (int i = 0; i < nArrayItens; ++i) {
        if (arrayItens[i] == Cstr){
            returnBool = true;
            result->add(arrayItens[i]);
        }
    }
    return returnBool;
}
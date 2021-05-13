/* Final Project Milestone 1
Modelue:	Menu
File:       Menu.h
Author:		Filipe da Cunha de Freitas
ID:			155737190
Revision History
-----------------------------------------------------------
Date		Reason
12/nov		Developed all functions
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
*/

#ifndef SDDS_MENU_H_
#define SDDS_MENU_H_
#include <iostream>
namespace sdds {
    class Menu {
        char* m_text;
        int m_noOfSel;
        bool isValid(int menuChoice) const;
    public:
        Menu(const char* text, int NoOfSelections);
        virtual ~Menu();
        Menu(const Menu&) = delete;
        Menu& operator=(const Menu&) = delete;
        std::ostream& display(std::ostream& ostr = std::cout)const;
        int& operator>>(int& Selection);

        void menuOptions(const char* text);
        int userMenuChoice();
        //int selectedOption(int numOfSel);
        void noOfSel(int numOfSel);
    };
}
#endif // !SDDS_MENU_H_
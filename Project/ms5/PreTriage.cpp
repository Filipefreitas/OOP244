/* Final Project Milestone 5
Modelue:	PreTriage
File:       PreTriage.cpp
Author:		Filipe da Cunha de Freitas
ID:			155737190
Revision History
-----------------------------------------------------------
Date		Reason
30/nov		Start coding
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "PreTriage.h"
#include "CovidPatient.h"
#include "TriagePatient.h"
#include "utils.h"
#include "time.h"
#include <fstream>
#include <typeinfo>
using namespace std;

namespace sdds 
{
    void PreTriage::reg() {
        if (m_lineupSize == maxNoOfPatients) 
        {
            cout << "Line up full!" << endl;
        }
        else 
        {
            m_pMenu.display(std::cout);
            int selection;
            selection = cin.get() - 48;
            cin.ignore(100, '\n');
            int i = m_lineupSize;
            m_lineupSize++;
            if (selection == 1) 
            {
                m_lineup[i] = new CovidPatient();
            }
            else if (selection == 2) 
            {
                m_lineup[i] = new TriagePatient();
            }
            else if (selection == 0) 
            {
                return;
            }
            m_lineup[i]->setArrivalTime();
            cout << "Please enter patient information:" << endl;
            m_lineup[i]->read(cin);
            cout << "\n" << "******************************************" << endl;
            m_lineup[i]->write(cout);
            cout << "Estimated Wait Time: ";
            cout << getWaitTime(*m_lineup[i]);
            cout << "\n" << "******************************************" << endl << endl;
        }
    }

    void PreTriage::admit() 
    {
        int selection;
        char type;
        m_pMenu.display();
        selection = cin.get()-48;
        cin.ignore(1000, '\n');
        if(selection == 1){
            type = 'C';
        }
        else if(selection == 2)
        {
            type = 'T';
        }
        if(selection != 0){
            int i = 0;
            i = indexOfFirstInLine(type);
            if (i != -1){
                cout <<  '\n' << "******************************************" << '\n';
                cout << "Calling for " << *m_lineup[i];
                cout << "******************************************" << '\n' << '\n';
                setAverageWaitTime(*m_lineup[i]);
                removePatientFromLineup(i);
            }
        }
    }

    const Time PreTriage::getWaitTime(const Patient &p) const {
        int itens = 0;
        for (int i = 0; i < maxNoOfPatients; ++i) 
        {
            if(&p == m_lineup[i]){
                itens++;
            }
        }

        if (p.type() == 'C')
        {
            Time tempTime = m_averCovidWait;
            tempTime *= (itens - 1);
            return tempTime;
        }
        else
        {
            Time tempTime = m_averTriageWait;
            tempTime *= (itens - 1);
            return tempTime;
        }

    }

    void PreTriage::setAverageWaitTime(const Patient &p) {
        Time CT = Time(getTime());
        CT -= p.operator Time();
        if(p == CovidPatient())
        {
            m_averCovidWait  = (CT + m_averCovidWait * (p.number()-1))/p.number();
        }
        else
        {
            m_averTriageWait = (CT + m_averTriageWait * (p.number()-1))/p.number();
        }
    }

    void PreTriage::removePatientFromLineup(int index) {
        removeDynamicElement(m_lineup, index, m_lineupSize);
    }

    void PreTriage::load() {
        cout << "Loading data..." << endl;
        ifstream file(m_dataFilename);

        if (file) 
        {
            file >> m_averCovidWait;
            file.ignore(1000, ',');
            file >> m_averTriageWait;
            file.ignore(1000, '\n');
            Patient* p;
            int i = 0;

            while (file && i < maxNoOfPatients) 
            {
                char typePatient;
                file >> typePatient;
                file.ignore(100, ',');
                if (typePatient == 'C')
                {
                    p = new CovidPatient();
                    p->fileIO(true);
                    p->csvRead(file);
                    m_lineup[i] = p;
                    m_lineupSize++;
                }
                else
                {
                    p = new TriagePatient();
                    p->fileIO(true);
                    p->csvRead(file);
                    m_lineup[i] = p;
                    m_lineupSize++;
                }
                i++;
            }
            if (!file.eof()) 
            {
                cout << "Warning: number of records exceeded" << maxNoOfPatients << endl << endl;
            }
            else
            {
                cout << m_lineupSize << " Records imported..." << endl << endl;
            }
        }
        else 
        {
            cout << "No data or bad data file!" << endl << endl;
        }
    }

    int PreTriage::indexOfFirstInLine(char type) const {
        if(m_lineupSize>0) 
        {
            for (int i = 0; i < maxNoOfPatients; ++i) 
            {
                if (type == m_lineup[i]->type()) 
                {
                    return i;
                }
            }
        }
        return -1;
    }

    PreTriage::PreTriage(const char *dataFilename):
            m_appMenu("General Hospital Pre-Triage Application\n1- Register\n2- Admit", 2),
            m_pMenu("Select Type of Admittance:\n1- Covid Test\n2- Triage", 2){
        m_dataFilename = new char[strlen(dataFilename)+1];
        strcpy(m_dataFilename, dataFilename);
        m_averCovidWait = 15;
        m_averTriageWait = 5;
        load();
    }

    PreTriage::~PreTriage() {
        ofstream file(m_dataFilename, ofstream::trunc);
        file << m_averCovidWait << ',' << m_averTriageWait;
        cout << "Saving Average Wait Times," << endl;
        cout << "   COVID Test: " << m_averCovidWait << endl;
        cout << "   Triage: " << m_averTriageWait << endl;
        cout << "Saving m_lineup..." << endl;
        int maxLines = m_lineupSize;
        for (int i = 0; i < maxLines; ++i) 
        {
            file << '\n';
            m_lineup[0]->csvWrite(file);
            cout << i+1 << "- ";
            m_lineup[0]->csvWrite(cout);
            cout << '\n';
            removePatientFromLineup(0);
        }
        delete []m_dataFilename;
        cout << "done!";
    }

    void PreTriage::run() {
        int selection;
        m_appMenu.display();
        selection = cin.get()-48;
        cin.ignore(1000, '\n');
        while(selection != 0){
            if(selection == 1){
                reg();
                m_appMenu.display();
                selection = cin.get()-48;
                cin.ignore(1000, '\n');
            }
            else if(selection == 2){
                admit();
                m_appMenu.display();
                selection = cin.get()-48;
                cin.ignore(1000, '\n');
            }else{
                cout  << "Invalid Option, choose again" << endl;
                selection = cin.get()-48;
                cin.ignore(1000, '\n');
            }
        }
    }
}

/*
    Student Name:	Wonchul Choi
    Student Nubmer:	118362201
    Student ID:	    wchoi28
    Student e-mail: wchoi28@myseneca.ca
    Course:         OOP244
    Final project:  MS5
*/
#include <iostream>
#include <fstream>
#include <limits>
#include "PreTriage.h"
#include "CovidPatient.h"
#include "TriagePatient.h"
#include <crtdbg.h>
using namespace std;
namespace sdds {
    typedef PreTriage pt;
  
    pt::PreTriage(const char* dataFilename)
        : m_averCovidWait(15), m_averTriageWait(5), m_dataFilename(nullptr)
        , m_appMenu("General Hospital Pre-Triage Application\n1- Register\n2- Admit", 2)
        , m_pMenu("Select Type of Admittance:\n1- Covid Test\n2- Triage", 2){
        copyString(dataFilename, m_dataFilename);
        load();
    }
    pt::~PreTriage() {
        ofstream ofs;
        ofs.open(m_dataFilename);
        m_averCovidWait.write(ofs);
        ofs << ",";
        m_averTriageWait.write(ofs);
        ofs << endl;

        cout << "Saving Average Wait Times," << endl;
        cout << "\tCOVID Test: ";
        m_averCovidWait.write(cout);
        cout << endl << "\tTriage: ";
        m_averTriageWait.write(cout);
        
        cout << endl << "Saving m_lineup..." << endl;
        for (int i = 0; i < m_lineupSize; i++) {
            m_lineup[i]->fileIO(true);
            m_lineup[i]->write(ofs);
            ofs << endl;
            cout << i + 1 << "- ";
            m_lineup[i]->write(cout);
            cout << endl;            
        }
      
        ofs.close();
      
        delete[] m_dataFilename;
        m_dataFilename = nullptr;
        for (int i = 0; i < m_lineupSize; i++)
            delete m_lineup[i];
       cout << "done!" << endl;
        //_CrtDumpMemoryLeaks();
    }
    
    void pt::run(void) {
        int selectNum;
        
        while (m_appMenu >> selectNum) {
            switch (selectNum) {
            case 0:
                exit(0);
            case 1:
                reg();
                break;
            case 2:
                admit();
                break;
            }
        }
    }
    void pt::admit() {
        char type = 'A';
        int selectNum;
        int index = -1;
       
        while (true) {
            m_pMenu >> selectNum;

            switch (selectNum) {
            case 0:
                break;
            case 1:
                type = 'C';
                break;
            case 2:
                type = 'T';
                break;
            }
            index = indexOfFirstInLine(type);
            if (index != -1)
                break;
        }
     
        if (type != 'A') {
            m_lineup[index]->fileIO(false);
            cout << endl << "******************************************" << endl;
            cout << "Calling for ";
            m_lineup[index]->write(cout);
            cout  << "******************************************" << endl << endl;
            setAverageWaitTime(*m_lineup[index]);
            removePatientFromLineup(index);
        }
    }

    void pt::reg() {
        bool isPass = true;
        int selection;
        if (m_lineupSize >= maxNoOfPatients)
            cout << "Line up full!" << endl;
        else {
            m_pMenu >> selection;
            switch (selection) {
                case 0:
                    isPass = false;
                    break;
                case 1:
                    m_lineup[m_lineupSize] = new CovidPatient;
                    break;
                case 2:
                    m_lineup[m_lineupSize] = new TriagePatient;
                    break;
            }

            if (isPass) {
                m_lineup[m_lineupSize]->resetTime();
                cout << "Please enter patient information: " << endl;
                m_lineup[m_lineupSize]->fileIO(false);
                m_lineup[m_lineupSize]->read(cin);
                cout << endl << "******************************************" << endl;
                m_lineup[m_lineupSize]->write(cout);
                cout << "Estimated Wait Time: " << getWaitTime(*m_lineup[m_lineupSize]) << endl;
                cout << "******************************************" << endl << endl;
                if (m_lineupSize < maxNoOfPatients) m_lineupSize++;
            }            
        }
    }

    void pt::load() {
        bool isOver = false;
        char finputCh;
        int finputNum;
        int index = 0;
               
        ifstream ifs;
        ifs.open(m_dataFilename);
        cout << "Loading data..." << endl;
        if (!ifs.is_open()) { cout << "No data or bad data file!" << endl << endl; }
        else {
            finputNum = getTime(ifs);
            ifs.ignore(numeric_limits<int>::max(), ',');
            m_averCovidWait = finputNum;
            finputNum = getTime(ifs);
            ifs.ignore(numeric_limits<int>::max(), '\n');
            m_averTriageWait = finputNum;

            while (ifs >> finputCh) {
                ifs.ignore(numeric_limits<char>::max(), ',');
                if (finputCh == 'C') ptPtr = new CovidPatient();
                else if (finputCh == 'T') ptPtr = new TriagePatient();
                else { cout << "Error - Fail to read data from file.\n please check the file." << endl; break; }
                ptPtr->fileIO(true);
                ptPtr->read(ifs);
                ptPtr->fileIO(false);
                m_lineup[index++] = ptPtr;
                if (index > maxNoOfPatients - 1) {
                    isOver = true;
                    ifs.clear();
                    break;
                }
            }
            
            if (isOver) {
                m_lineupSize = maxNoOfPatients;
                cout << "Warning: number of records exceeded 100" << endl;
            }
            else m_lineupSize = index;
            cout << m_lineupSize << " Records imported..." << endl << endl;
            ifs.close();
        }
    }

    int pt::indexOfFirstInLine(char type) const {
        bool isfound = false;
        int index = 0;
        
        for (int i = 0; i < m_lineupSize; i++) {
            if (m_lineup[i]->type() == type) {
                index = i;
                isfound = true;
                break;
            }
        }
        if (!isfound) index = -1;
        return index;                   
    }
    void pt::removePatientFromLineup(int index) { removeDynamicElement(m_lineup, index, m_lineupSize);  }
    const Time pt::getWaitTime(const Patient& p)const {
        int totalTime;
        int patNum = 0;
        for (int i = 0; i < m_lineupSize; i++) {
            if (p.type() == m_lineup[i]->type())
                patNum++;
        }
        if (p.type() == 'C')
            totalTime = patNum * m_averCovidWait;
        else
            totalTime = patNum * m_averTriageWait;
        return Time(totalTime);
    }
    void pt::setAverageWaitTime(const Patient& p) {
        Time cur(getTime());
        int waitTime;
        if (p.type() == 'C') {
            waitTime = ((cur - p) + (m_averCovidWait * (p.number() - 1))) / p.number();
            m_averCovidWait = waitTime;
        }
        else {
            waitTime = ((cur - p) + (m_averTriageWait * (p.number() - 1))) / p.number();
            m_averTriageWait = waitTime;
        }
    }

  
}
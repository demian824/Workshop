/*
    Student Name:	Wonchul Choi
    Student Nubmer:	118362201
    Student ID:	    wchoi28
    Student e-mail: wchoi28@myseneca.ca
    Course:         OOP244
    Final project:  MS5
*/
#ifndef SDDS_PRETRIAGE_H_
#define SDDS_PRETRIAGE_H_
#include "Patient.h"
#include "Menu.h"
#include "utils.h"
namespace sdds {
    const int maxNoOfPatients = 100;
    class PreTriage {
        Time
            m_averCovidWait,
            m_averTriageWait;
        Patient* m_lineup[maxNoOfPatients]{};
        char* m_dataFilename{};
        int m_lineupSize = 0;
        Menu m_appMenu, m_pMenu;
        void reg();
        void admit();
        const Time getWaitTime(const Patient& p)const;
        void setAverageWaitTime(const Patient& p);
        void removePatientFromLineup(int index);
        void load();
        int indexOfFirstInLine(char type) const;
    public:
        PreTriage(const char* dataFilename);
        ~PreTriage();
        void run(void);
    };
}
#endif // !SDDS__H_
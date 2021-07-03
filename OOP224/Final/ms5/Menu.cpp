/*
    Student Name:	Wonchul Choi
    Student Nubmer:	118362201
    Student ID:	    wchoi28
    Student e-mail: wchoi28@myseneca.ca
    Course:         OOP244
    Final project:  MS1
*/
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include "utils.h"
#include "Menu.h"

using namespace std;
namespace sdds {
    typedef Menu m;
    m::Menu(const char* text, const int NoOfSelections)
        : m_text(nullptr), m_noOfSel(0) {
        if(text)
            init(text, NoOfSelections); 
    }
    void m::init(const char* text, const int NoOfSelections) {
       if (m_text) delete[] m_text;
        m_text = new char[strlen(text) + 1];

        if (!m_text)
            cout << "failed to dynamic memory allocation" << endl;
        strcpy(m_text, text);
               
        if (NoOfSelections > 0) m_noOfSel = NoOfSelections;    }

    m::~Menu(){ delete[] m_text; }
    ostream& m::display(ostream& ostr)const{ return ostr << m_text << endl << "0- Exit" << endl << "> "; }
    int& m::operator>>(int& Selection){
        int temp;
        int min = 0;
        display();
        while (true) {
            temp = getInt();
            if (numRange(min, m_noOfSel, temp)){
                Selection = temp;
                break;
            }
        }
        return Selection;
    }
}
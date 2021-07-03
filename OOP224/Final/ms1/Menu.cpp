/*
    Student Name:	Wonchul Choi
    Student Nubmer:	118362201
    Student ID:	    	wchoi28
    Student e-mail: 	wchoi28@myseneca.ca
    Course:         	OOP244
    Final project:  	MS1
*/
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include "utils.h"
#include "Menu.h"

using namespace std;
namespace sdds {
    typedef Menu m;

    m::Menu(const char* text, const int NoOfSelections){
        m_text = nullptr;
        m_noOfSel = 0;

        init(text, NoOfSelections);
    }

    void m::init(const char* text, const int NoOfSelections) {
        if (text) {
            delete[] m_text;
            m_text = new char[strlen(text) + 1];

            if (!text)
                cout << "failed to dynamic memory allocation" << endl;
            strcpy(m_text, text);
        }
       
        if (NoOfSelections > 0)
            m_noOfSel = NoOfSelections;
    }
    m::~Menu(){
        delete[] m_text;
    }
    ostream& m::display(ostream& ostr)const{
        return ostr;
    }
    int& m::operator>>(int& Selection){
        int temp;
        cout << m_text << endl;
        cout << "0- Exit" << endl << "> ";

        while (true) {
            temp = getInt();
            if (numRange(temp, m_noOfSel)) {
                Selection = temp;
                break;
            }
        }
        return Selection;
    }



}
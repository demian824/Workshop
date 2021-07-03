/*
    Student Name:	Wonchul Choi
    Student Nubmer:	118362201
    Student ID:	    	wchoi28
    Student e-mail: 	wchoi28@myseneca.ca
    Course:         	OOP244
    Final project:  	MS1
*/
#include <cstring>
#include <cstdlib>
#include "Time.h"
#include "utils.h"
using namespace std;
namespace sdds {
    typedef Time t;

    Time& t::reset(){
        m_min = getTime();

        return *this;
    }
    t::Time(unsigned int min)
        : m_min(min)
    {}
    ostream& t::write(ostream& ostr) const{
        ostr.width(2);
        ostr.fill('0');
        ostr << (m_min / 60) << ":" ;
        ostr.width(2);
        ostr.fill('0');
        ostr << (m_min % 60);
        return ostr;
    }
    istream& t::read(istream& istr){
        bool flag = false;
        char tempTime[9];
        int length = 0;
        int  tempHour = 0;
        int  tempMin = 0;

        while (!flag) {
            istr >> tempTime;
            length = strlen(tempTime);
            if (tempTime[2] == ':' && length == 5)
                flag = strTotime(tempTime, tempHour, tempMin);
            
            if (!flag)
                cout << "Bad time entry, retry (HH:MM): ";
        }
        m_min = (tempHour * 60) + tempMin;

        return istr;
    }
    t::operator int()const { return (int)m_min; }
    Time& t::operator *= (int val){
        m_min *= val;
        return *this;
    }
    Time& t::operator-=(const Time& D){
        if (this->m_min >= D.m_min) {
            m_min -= D.m_min;
        }
        else {
            m_min = (m_min + (24 * 60)) - D.m_min;
        }
        return *this;
    }
    istream& operator >> (istream& in, Time& t){
        t.read(in);

        return in;
    }
    ostream& operator << (ostream& out, Time& t){
        t.write(out);
        return out;
    }


}
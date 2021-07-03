/*
    Student Name:	Wonchul Choi
    Student Nubmer:	118362201
    Student ID:	    wchoi28
    Student e-mail: wchoi28@myseneca.ca
    Course:         OOP244
    Final project:  MS1
*/
#ifndef SDDS_TIME_H
#define SDDS_TIME_H
#include <iostream>
namespace sdds {
    class Time {
        unsigned int m_min;
    public:
        Time& reset();
        Time(unsigned int min = 0);
        std::ostream& write(std::ostream& ostr) const;
        std::istream& read(std::istream& istr);
        operator int()const; 
        operator Time() const;
        Time& operator *= (int val);
        Time& operator-=(const Time& D);
        Time operator-(const Time& ROperand);
        std::ostream& operator << (std::ostream&);
    };
    // helper operator << and >> prototypes
    std::istream& operator >> (std::istream& out, Time& t);
    std::ostream& operator << (std::ostream& out, const Time& t);   
}

#endif // !SDDS_TIME_H

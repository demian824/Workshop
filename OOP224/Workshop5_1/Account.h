/*
    Student Name:	Wonchul Choi
    Student Nubmer:	118362201
    Student ID:	    wchoi28
    Student e-mail: wchoi28@myseneca.ca
    Course:         OOP244
    Workshop:	    Week05_PT1
*/
#pragma once
#include <iostream>
namespace sdds {
    class Account {
        int m_number;
        double m_balance;
        void setEmpty();
    public:
        Account();
        Account(int number, double balance);
        std::ostream& display()const;
        bool operator ~() const;
        operator bool() const;
        operator int() const;
        operator double() const;
        Account operator = (int num);
        Account operator =(Account &acc);
        Account operator +=(const double& add);
        Account operator -=(const double& minus);
        double operator +( const Account &acc);
        friend double operator +=(double &num, const Account& acc);

    };

}

/*
    Student Name:	Wonchul Choi
    Student Nubmer:	118362201
    Student ID:	    wchoi28
    Student e-mail: wchoi28@myseneca.ca
    Course:         OOP244
    Workshop:	    Week05_PT1
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Account.h"

using namespace std;
namespace sdds {
    typedef Account a;
    void a::setEmpty() {
        m_number = -1;
        m_balance = 0.0;
    }
    // New account
    a::Account() {
        m_number = 0;
        m_balance = 0.0;
    }
    a::Account(int number, double balance) {
        setEmpty();
        if (number >= 10000 && number <= 99999
            && balance > 0) {
            m_number = number;
            m_balance = balance;
        }
    }
    a::operator bool() const { return (m_number != -1 && (m_number >= 10000 && m_number <= 99999)) ? true : false || (m_number == 0 && m_balance == 0.0);   }
    a::operator int() const {  return this->m_number;  }
    a::operator double() const { return this->m_balance; }
    bool a::operator ~() const { return ((m_number == 0) && (m_balance == 0.0)); }
    Account a::operator = (int num) {
        if (num >= 10000 && num <= 99999)
            this->m_number = num;
        else
            this->m_number = -1;
            
        return *this;
    }
    Account a::operator =(Account& acc) {
       if(acc.m_number != -1 && this->m_number != -1)
           if (acc.m_number >= 10000 && acc.m_number <= 99999 && acc.m_balance >= 0.0) {
               this->m_balance = acc.m_balance;
               acc.m_balance = 0.0;
           }
               
        return *this;
    }
     double operator +=(double &num,const Account& acc) {
        
         return num += acc.m_balance;
        

    }
    Account a::operator +=(const double& add) {
        
        if(add > 0.0)
            if (m_number >= 10000 && m_number <= 99999
                && m_balance >= 0) {
                m_balance += add;
            }
        return *this;
    }
    Account a::operator -=(const double& minus) {
        if (minus > 0.0)
            if (m_number >= 10000 && m_number <= 99999
                && m_balance - minus >= 0) {
                m_balance -= minus;
            }
        return *this;
    }
    double a::operator +(const Account& acc){
        Account temp;
        if (this->m_balance >= 0 && acc.m_balance >= 0) {
            temp.m_balance = m_balance + acc.m_balance;
            return temp.m_balance;
        }
        else
            return 0.0;
    }
    

    std::ostream& a::display() const {
        if (*this) {
            cout << "Acc#: ";
            if (~(*this))
                cout << "Not Set";
            else
                cout << " " << m_number << " ";
            cout << ", Balance: ";
            cout.width(12);
            cout.precision(2);
            cout.setf(ios::right);
            cout.setf(ios::fixed);
            cout << m_balance;
            cout.unsetf(ios::right);
            // I (Fardad) removed the "return cout", this was a mistake
            // (copied and pasted by mistake)
            // and had no effect to the execution of the program.
            // As mentioned before we should have only
            // one return statement in a function.
        }
        else {
            cout << "Invalid Account";
        }
        return cout;
    }

  

}
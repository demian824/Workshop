/*
    Student Name:	Wonchul Choi
    Student Nubmer:	118362201
    Student ID:	    wchoi28
    Student e-mail: wchoi28@myseneca.ca
    Course:         OOP345
    Workshop:	    Week4
*/
#include <iostream>
#include "Restaurant.h"

namespace sdds
{
    //Aggregation
    Restaurant::Restaurant(const Reservation* res[], size_t cnt) {
        m_size = cnt;
        m_resptr = new Reservation[cnt];
        for (auto i = 0ull; i < cnt; i++)
            m_resptr[i] = *res[i];
    }
    Restaurant::Restaurant(const Restaurant& res){ *this = res; }
    Restaurant& Restaurant::operator=(const Restaurant& res) {
        if (this != &res) {
            m_size = res.m_size;
            if (res.m_resptr != nullptr) {
                delete[] m_resptr;
                m_resptr = new Reservation[res.m_size];
                for (auto i = 0u; i < res.m_size; i++) 
                    m_resptr[i] = res.m_resptr[i];
            }
        }
        return *this;
    }

    Restaurant::Restaurant(Restaurant&& res)  {  *this = std::move(res);  }
    Restaurant& Restaurant::operator=(Restaurant&& res)  {
        if (this != &res) {
            delete[] m_resptr;
            m_resptr = res.m_resptr;
            res.m_resptr = nullptr;
            m_size = res.m_size;
            res.m_size = 0ull;
        }
        return *this;
    }


    size_t Restaurant::size() const { return m_size; }

    Restaurant::~Restaurant() { delete[] m_resptr; }

    std::ostream& operator<<(std::ostream& os, const Restaurant& src) {
        static int num = 1;
        os << "--------------------------" << std::endl
           << "Fancy Restaurant (" << num++ << ")\n"
           << "--------------------------" << std::endl;
        if (src.m_size == 0ull) { os << "This restaurant is empty!" << std::endl; }
        else {          
            for (auto i = 0u; i < src.m_size; i++) 
                os << src.m_resptr[i];
        }
        os << "--------------------------" << std::endl;
        return os;
    }


}
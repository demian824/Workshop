/*
    Student Name:	Wonchul Choi
    Student Nubmer:	118362201
    Student ID:	    wchoi28
    Student e-mail: wchoi28@myseneca.ca
    Course:         OOP345
    Workshop:	    Week4
*/
#include <iostream>
#include "ConfirmationSender.h"

namespace sdds
{
    //Association 
    ConfirmationSender::ConfirmationSender(const ConfirmationSender& cf) { *this = cf; }
    ConfirmationSender& ConfirmationSender::operator=(const ConfirmationSender& cf) {
        if (this != &cf) {
            delete[] m_conptr;
            if (cf.m_conptr != nullptr) {
                m_capacity = cf.m_capacity;
                m_conptr = new const Reservation * [cf.m_capacity];
                for (auto i = 0u; i < m_capacity; i++) {
                    m_conptr[i] = cf.m_conptr[i];
                }

            }
        }
        return *this;
    }
    ConfirmationSender::ConfirmationSender(ConfirmationSender&& S)noexcept { *this = std::move(S); }
    ConfirmationSender& ConfirmationSender::operator=(ConfirmationSender&& S)noexcept {
        if (this != &S) {
            delete[] m_conptr;
            m_conptr = S.m_conptr;
            S.m_conptr = nullptr;
            m_capacity = S.m_capacity;
            S.m_capacity = 0ull;
        }
        return *this;
    }
    ConfirmationSender& ConfirmationSender::operator+=(const Reservation& res) {
        size_t size = 0ull;
        if (m_conptr == nullptr) size = m_capacity;
        else {
            for (auto i = 0u; i < m_capacity; i++) {
                if (m_conptr[i] != &res)
                    size++;
            }
        }
        if (size == m_capacity) {
            ConfirmationSender temp;
            temp = *this;
            delete[] m_conptr;
            m_conptr = new const Reservation * [m_capacity + 1];
            for (auto i = 0u; i < m_capacity; i++)
                m_conptr[i] = temp.m_conptr[i];
            m_conptr[m_capacity] = &res;
            m_capacity++;
        }

        return *this;
    }
    ConfirmationSender& ConfirmationSender::operator-=(const Reservation& res) {
        ConfirmationSender temp;
        temp.m_conptr = new  const Reservation * [m_capacity - 1];
        size_t index = 0ull;
        for (size_t i = 0ull; i < m_capacity; i++) {
            if (m_conptr[i] == &res) {
                m_conptr[i] = nullptr;
                index = i;
                break;
            }
        }
        if (index) {
            for (size_t i = 0ull, j = 0ull; i < m_capacity && j < m_capacity - 1; i++) {
                if(i != index)
                temp.m_conptr[j++] = m_conptr[i];
            }
            delete[] m_conptr;
            m_conptr = new const Reservation * [--m_capacity];
            for (size_t i = 0u; i < m_capacity; i++)
                m_conptr[i] = temp.m_conptr[i];
        }
        return *this;
    }
    ConfirmationSender::~ConfirmationSender() { delete[] m_conptr; }
    std::ostream& operator<<(std::ostream& os, const ConfirmationSender& cf) {
        os << "--------------------------" << std::endl
           << "Confirmations to Send" << std::endl
           << "--------------------------" << std::endl;
        if (cf.m_conptr == nullptr) 
            os << "There are no confirmations to send!" << std::endl;
        else 
            for (auto i = 0ull; i < cf.m_capacity; i++) 
                os << *cf.m_conptr[i];
        os << "--------------------------" << std::endl;
        return os;
    }
}
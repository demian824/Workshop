/*
    Student Name:	Wonchul Choi
    Student Nubmer:	118362201
    Student ID:	    wchoi28
    Student e-mail: wchoi28@myseneca.ca
    Course:         OOP345
    Workshop:	    Week4
*/
#pragma once
#include "Reservation.h"

namespace sdds
{
    //Association 
    class ConfirmationSender
    {
        const Reservation** m_conptr = nullptr;
        size_t m_capacity = 0ull;
    public:
        ConfirmationSender() {};
        ConfirmationSender(const ConfirmationSender& cf);
        ConfirmationSender& operator=(const ConfirmationSender&cf);
        ConfirmationSender(ConfirmationSender&& cf)noexcept;
        ConfirmationSender& operator=(ConfirmationSender&& cf)noexcept;
        ConfirmationSender& operator+=(const Reservation& res);
        ConfirmationSender& operator-=(const Reservation& res);
        ~ConfirmationSender();
        friend std::ostream& operator<<(std::ostream&, const ConfirmationSender&);
    };
}


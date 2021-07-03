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
    //Aggregation
    class Restaurant
    {
        Reservation* m_resptr = nullptr;
        size_t m_size = 0ull;
    public:
        Restaurant(const Reservation* res[], size_t cnt);
        Restaurant(const Restaurant& res);
        Restaurant& operator=(const Restaurant& res);
        Restaurant(Restaurant&& res);
        Restaurant& operator=(Restaurant&& res);
        size_t size() const;
        ~Restaurant();
        friend std::ostream& operator<<(std::ostream&, const Restaurant&);
    };
}

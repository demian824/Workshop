/*
	Student Name:	Wonchul Choi
	Student Nubmer:	118362201
	Student ID:	    wchoi28
	Student e-mail: wchoi28@myseneca.ca
	Course:         OOP244
	Workshop:	    Week07
*/
#pragma once
#include "Vehicle.h"

namespace sdds {
	class Truck : public Vehicle {
		double	m_capWeight;
		double	m_curWeight;
	public:
		Truck(const char* string = nullptr, int year = 0, int capacity = 0, const char* address = nullptr);
		~Truck();
		bool addCargo(double cargo);
		bool unloadCargo();
		
		std::ostream& write(std::ostream& os);
		std::istream& read(std::istream& in);
	};
	std::istream& operator >> (std::istream& in, Truck& t);
	std::ostream& operator << (std::ostream& os, Truck& t);
	
}
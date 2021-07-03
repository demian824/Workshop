/*
	Student Name:	Wonchul Choi
	Student Nubmer:	118362201
	Student ID:	    wchoi28
	Student e-mail: wchoi28@myseneca.ca
	Course:         OOP244
	Workshop:	    Week07
*/
#pragma once

namespace sdds {
	class Vehicle {
		char	m_plateNum[9];
		char	m_addressVeh[64];
		int		m_year;
	public:
		Vehicle(const char* string = "Empty", const int& year = 0, const char* address = "Factory");
		~Vehicle();
		void init(const char*string, const int year, const char*address);
		void moveTo(const char* address);
		std::ostream& write(std::ostream& os);
		std::istream& read(std::istream& in);
	};
	std::ostream& operator << (std::ostream& out, Vehicle vh);
	std::istream& operator >> (std::istream& in, Vehicle& vh);
}
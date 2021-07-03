/*
	Student Name:	Wonchul Choi
	Student Nubmer:	118362201
	Student ID:	    wchoi28
	Student e-mail: wchoi28@myseneca.ca
	Course:         OOP345
	Workshop:	    Week4
*/
//composition
#pragma once
#include <string>

namespace sdds {
	class Reservation {
		int m_resPpl;
		int m_resDay;
		int m_resHour;
		std::string m_resId;
		std::string m_resName;
		std::string m_resEmail;
		std::string m_serviceTime;
		std::string m_people;
		void removeSpace(std::string& str);
		void setOption(std::string& service, const int& hour);
		
	public:
		Reservation();
		Reservation(const std::string& res);
		bool isEmpty() const;
		friend std::ostream& operator << (std::ostream& os, const Reservation& res);

	};
}
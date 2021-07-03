/*
	Student Name:	Wonchul Choi
	Student Nubmer:	118362201
	Student ID:	    wchoi28
	Student e-mail: wchoi28@myseneca.ca
	Course:         OOP345
	Workshop:	    Week6
*/
/************************************
	* File Name:				Racecar.cpp
	* Included Header/Library	Racecar.h
	* namespace:				sdds
	************************************/
#include "Racecar.h"

namespace sdds {

	using namespace std;
	/************************************
	* Constructor Name:		Racecar
	* Discription:			default constructor
	************************************/
	Racecar::~Racecar() {}
	/************************************
	* Constructor Name:		Racecar
	* Discription:			constructor
	************************************/
	Racecar::Racecar(std::istream& in):Car(in) {
		size_t startIn = 0;
		string temp;
		getline(in, temp);

		for (size_t i = 0; i < temp.m_length(); i++) {
			if (temp[i] >= 48 && temp[i] <= 57) {
				startIn = i;
				break;
			}
		}
		temp = temp.substr(startIn);
		m_booster = stod(temp);
	}
	/************************************
	* Function prototype:		void display(std::ostream& out) const
	* Function Name:			display
	* Function type:			void
	* Function Parameter:		out
	* Parameter type:			std::ostream&
	* Discription:				print the value
	************************************/
	void Racecar::display(std::ostream& out) const {
		Racecar::Car::display(out);
		out << "*";
	}
	/************************************
	* Function prototype:		double topSpeed() const
	* Function Name:			topSpeed
	* Function type:			double
	* Function Parameter:		NONE
	* Discription:				return m_topSpeed with m_booster
	************************************/
	double Racecar::topSpeed() const {	return (m_booster + 1) * Racecar::Car::topSpeed();	}

}
/*
	Student Name:	Wonchul Choi
	Student Nubmer:	118362201
	Student ID:	    wchoi28
	Student e-mail: wchoi28@myseneca.ca
	Course:         OOP345
	Workshop:	    Week6
*/
/************************************
	* File Name:			Racecar.h
	* Included Header/Library
	*	Car.h
	* namespace:			sdds
	* preprocessor:			#pragma once
	************************************/
#include "Car.h"

namespace sdds {
	/************************************
		* Class Name:			Racecar
		* Mother Class:			Car
		* Member Variable:		m_booster
		* Member Variable type: double;
		* Constructor:			Racecar(std::istream& in)
		* Destructor:			~Racecar()
		* Member Function:
		*	 virtual void display(std::ostream& out) const
		*	 virtual double topSpeed() const
		************************************/
	class Racecar : public Car{
		double m_booster;
	public:
		~Racecar();
		Racecar(std::istream& in);
		virtual void display(std::ostream& out) const;
		virtual double topSpeed() const;
	};
}
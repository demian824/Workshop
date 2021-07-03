/*
	Student Name:	Wonchul Choi
	Student Nubmer:	118362201
	Student ID:	    wchoi28
	Student e-mail: wchoi28@myseneca.ca
	Course:         OOP345
	Workshop:	    Week6
*/
/************************************
	* File Name:			Car.h
	* Included Header/Library
	*	iostream
	*	string
	*	Vehicle.h
	* namespace:			sdds
	* preprocessor:			#pragma once
	************************************/
#pragma once

#include <iostream>
#include <string>
#include "Vehicle.h"

namespace sdds {
	/************************************
		* Class Name:			Car
		* Mother Class:			Vehicle
		* Member Variable:		m_maker, m_condition, m_topSpeed
		* Member Variable type: double;
		* Constructor:			Car(std::istream& in)
		* Destructor:			~Car()
		* Member Function:
		*	 virtual std::string condition() const
		*	 virtual double topSpeed() const
		*	 virtual void display(std::ostream& out) const
		*    void removeSpace(std::string& str, bool flag = false)
		************************************/
	class Car : public Vehicle{
		std::string m_maker{};
		std::string m_condition{};
		double m_topSpeed=0.0;
		void removeSpace(std::string& str, bool flag = false);
	public:
		~Car();
		Car(std::istream& in);
		virtual std::string condition() const;
		virtual double topSpeed() const;
		virtual void display(std::ostream& out) const;
	};
}
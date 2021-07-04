/*
	Student Name:	Wonchul Choi
	Student Nubmer:	118362201
	Student ID:	    wchoi28
	Student e-mail: wchoi28@myseneca.ca
	Course:         OOP345
	Workshop:	    Week6
*/
/************************************
	* File Name:			Utilities.h
	* Included Header/Library
	*	Vehicle.h
	*	Car.h
	*	Racecar.h
	*	Autoshop.h
	* namespace:			sdds
	* preprocessor:			#pragma once
	************************************/
#pragma once

#include"Vehicle.h"
#include"Car.h"
#include "Racecar.h"
#include"Autoshop.h"

namespace sdds {
	/************************************
	* Function prototype:		Vehicle* createInstance(std::istream& in)
	* Function Name:			createInstance
	* Function type:			Vehicle*
	* Function Parameter:		in
	* Parameter type:			std::istream&
	************************************/
	Vehicle* createInstance(std::istream& in);
}
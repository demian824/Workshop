/*
	Student Name:	Wonchul Choi
	Student Nubmer:	118362201
	Student ID:	    wchoi28
	Student e-mail: wchoi28@myseneca.ca
	Course:         OOP345
	Workshop:	    Week3
*/
/************************************
	* File Name:			StringSet.h
	* Included Header/Library
	*	Set.h
	* namespace:			sdds
	* preprocessor:			#pragma once
	************************************/
#pragma once
#include "Set.h"

namespace sdds {
	/************************************
		* Class Name:			SetSummable
		* Constructor:			defualt
		* Destructor:			defualt
		* Member Function:		T accumulate(const std::string& filter) const
		************************************/
	template<unsigned int N, typename T>
	class SetSummable : public Set<N, T> {
	public:
		T accumulate(const std::string& filter) const {
			T sumValue(filter);
			for (size_t i = 0; i < this->size(); i++) 
				if (sumValue.isCompatibleWith(this->get(i)))
					sumValue += this->get(i);			
			return sumValue;
		}
	};
}
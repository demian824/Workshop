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
	*	iostream
	* namespace:			sdds
	* preprocessor:			#pragma once
	************************************/
#pragma once
#include <iostream>

namespace sdds {
	/************************************
		* Class Name:			Set
		* Member Variable:		m_arr[N], m_curIndex
		* Member Variable type: T , size_t
		* Constructor:			defualt, copy, move
		* Destructor:			defualt
		* Member Function:
		*	size()
		*	get(size_t idx)
		* Overloading:			operator+=
		************************************/
	template<int N, typename T >
	class Set {
		T m_arr[N];
		size_t m_curIndex;
	public:
		Set() : m_arr{}, m_curIndex(0ull) {}
		size_t size() const { return m_curIndex; }
		const T& get(size_t idx) const { return m_arr[idx]; }
		void operator+=(const T& item) {	
			if (m_curIndex < N) m_arr[m_curIndex++] = item;	}
	};
}
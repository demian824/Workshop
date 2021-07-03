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
	*	string
	*	iomanip
	* namespace:			sdds
	* preprocessor:			#pragma once
	************************************/
#pragma once
#include <iostream>
#include <string>
#include <iomanip>
namespace sdds {
	/************************************
		* Class Name:			Pair
		* Member Variable:		m_type, m_value
		* Member Variable type: V, K
		* Constructor:			defualt, Pair(const K& key, const V& value)
		* Destructor:			defualt
		* Member Function:
		*	value()
		*	key()
		*	display(std::ostream& os) -Virtual
		* Overloading:			operator <<
		************************************/
	template<typename V, typename K>
	class Pair {
		K m_type;
		V m_value;
	public:
		Pair() : m_type{}, m_value{} {}
		Pair(const K& key, const V& value) : m_type(key), m_value(value){}
		const V& value() const { return m_value; }
		const K& key() const { return m_type; }
		virtual void display(std::ostream& os) const { 
			os << m_type << " : " << m_value << std::endl; }	
	};
	template<typename V, typename K>
	std::ostream& operator << (std::ostream& os, const Pair<V, K>& pair) {
		pair.display(os);
		return os;
	}

}
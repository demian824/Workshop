/*
	Student Name:	Wonchul Choi
	Student Nubmer:	118362201
	Student ID:	    wchoi28
	Student e-mail: wchoi28@myseneca.ca
	Course:         OOP345
	Workshop:	    Week5
*/
/************************************
	* File Name:			Book.h
	* Included Header/Library
	*	iostream
	*	string
	*	iomanip
	* namespace:			sdds
	* preprocessor:			#pragma once
	************************************/
#pragma once
#include <iostream>
#include <iomanip>
#include <string>
namespace sdds {
	/************************************
		* Class Name:			Book
		* Member Variable:		m_year, m_price, m_author, m_title, m_country, m_desc
		* Member Variable type: size_t, double, std::string, std::string, std::string, std::string
		* Constructor:			Book(const std::string& strBook)
		* Destructor:			defualt
		* Member Function:
		*	Book();
		*	Book(const std::string& strBook)
		*	isCompatibleWith(const PairSummable<V, K>& b)
		*	init(std::string& str, std::string& member, bool desc = false)
		*	isMovie()
		*	title()
		*	country()
		*	year()
		*	price()
		*	fixSpelling(T& spellChecker)
		* Overloading:			operator <<
		************************************/
	class Book {
		size_t m_year;
		double m_price;
		std::string m_author;
		std::string m_title;
		std::string m_country;
		std::string m_desc;
	public:
		Book();
		Book(const std::string& strBook);
		void init(std::string& str, std::string& member, bool desc = false);
		const std::string& title() const;
		const std::string& country() const;
		const size_t& year() const;
		const bool isMovie() const;
		double& price();
		friend std::ostream& operator << (std::ostream& os, const Book& data);
		template <typename T>
		void fixSpelling(T& spellChecker) { spellChecker(m_desc); }
	};
}
/*
	Student Name:	Wonchul Choi
	Student Nubmer:	118362201
	Student ID:	    wchoi28
	Student e-mail: wchoi28@myseneca.ca
	Course:         OOP345
	Workshop:	    Week5
*/
/************************************
	* File Name:			Movie.h
	* Included Header/Library
	*	string
	* namespace:			sdds
	* preprocessor:			#pragma once
	************************************/
#pragma once
#include <string>

namespace sdds {
	/************************************
		* Class Name:			Movie
		* Member Variable:		m_year, m_title, m_desc
		* Member Variable type: size_t, std::string, std::string;
		* Constructor:			Movie(const std::string& strMovie)
		* Destructor:			defualt
		* Member Function:
		*	isCompatibleWith(const PairSummable<V, K>& b)
		*	 init(std::string& str, std::string& member, bool desc = false)
		*	 isMovie()
		*	 title()
		*	 fixSpelling(T& spellChecker)
		* Overloading:			operator <<
		************************************/
	class Movie {
		size_t m_year;
		std::string m_title;
		std::string m_desc;
	public:
		Movie();		
		Movie(const std::string& strMovie);
		void init(std::string& str, std::string& member, bool desc = false);
		const bool isMovie() const;
		const std::string& title() const;
		friend std::ostream& operator << (std::ostream& os, const Movie& data);
		template <typename T>
		void fixSpelling(T& spellChecker) {	
			spellChecker(m_title);
			spellChecker(m_desc); 
		}
	};
}
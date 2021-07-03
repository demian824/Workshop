/*
	Student Name:	Wonchul Choi
	Student Nubmer:	118362201
	Student ID:	    wchoi28
	Student e-mail: wchoi28@myseneca.ca
	Course:         OOP345
	Workshop:	    Week5
*/
/************************************
	* File Name:				Movie.cpp
	* Included Header/Library	Movie.h
	*							iomanip
	* namespace:				sdds
	************************************/
#include <iomanip>
#include "Movie.h"

namespace sdds {
	typedef Movie M;
	using namespace std;
	/************************************
	* Constructor Name:		Movie
	* Discription:			default constructor
	************************************/
	M::Movie()
		: m_year(0), m_title{}, m_desc{}{}
	/************************************
	* Constructor Name:		Movie
	* Discription:			constructor
	************************************/
	M::Movie(const string& strMovie){
		string temp = strMovie;
		string tempNum;
		init(temp, m_title);
		init(temp, tempNum);
		m_year = stoi(tempNum);
		init(temp, m_desc, true);
		temp.erase();
	}
	/************************************
	* Function prototype:		void M::init(std::string& str, std::string& member, bool desc)
	* Function Name:			init
	* Function type:			void
	* Function Parameter:		str, member,desc
	* Parameter type:			std::string&, std::string&, bool
	* Default Parameter:		desc = false
	* Discription:				initialized Movie member variable
	************************************/
	void M::init(std::string& str, std::string& member, bool desc) {
		size_t startNum = 0;
		for (size_t i = 0; i < str.length(); i++)
			if (str[i] != 32) {
				startNum = i;
				break;
			}
		size_t indexNum = str.find(',');
		if (indexNum != std::string::npos && !desc) {
			member = str.substr(startNum, (indexNum - startNum));
			str = str.substr(indexNum + 1);
		}
		else member = str.substr(startNum);
		bool noSpace = false;
		size_t index = member.length() - 1;
		while (!noSpace) {
			if (member[index--] == 32) member.pop_back();
			else noSpace = true;
		}
	}
	/************************************
	* Function prototype:		const std::string& M::title() const
	* Function Name:			title
	* Function type:			const std::string&
	* Function Parameter:		NONE
	* Parameter type:			NONE
	* Discription:				return m_title from Movie class
	************************************/
	const std::string& M::title() const { return m_title; }
	/************************************
	* Function prototype:		const bool M::isMovie() const
	* Function Name:			isMovie
	* Function type:			const bool
	* Function Parameter:		NONE
	* Parameter type:			NONE
	* Discription:				A flag to check class 'Movie'
	************************************/
	const bool M::isMovie() const { return true; }
	/************************************
	* Function prototype:		std::ostream& operator << (std::ostream& os, const Movie& data)
	* Function Name:			operator <<
	* Function type:			std::ostream&
	* Function Parameter:		os, data
	* Parameter type:			std::ostream&, const Movie&
	* Default Parameter:		NONE
	* Return value/variable:	os
	* Discription:				print the value of Movie class
	************************************/
	std::ostream& operator << (std::ostream& os, const Movie& data) {
		os.setf(std::ios::right);
		os << std::setw(40) << data.m_title << " | ";
		os.unsetf(std::ios::right);
		os << std::setw(4) << data.m_year << " | ";
		os << data.m_desc << std::endl;
		return os;
	}
}
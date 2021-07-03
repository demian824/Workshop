/*
	Student Name:	Wonchul Choi
	Student Nubmer:	118362201
	Student ID:	    wchoi28
	Student e-mail: wchoi28@myseneca.ca
	Course:         OOP345
	Workshop:	    Week5
*/
/************************************
	* File Name:				StringSet.cpp
	* Included Header/Library	StringSet.h
	* namespace:				sdds
	************************************/
#include "Book.h"

namespace sdds {
	using namespace std;
	typedef Book B;
	/************************************
	* Constructor Name:		Book
	* Discription:			default constructor
	************************************/
	B::Book()
		: m_year(0), m_price(0.0), m_author{}, m_title{}, m_country{}, m_desc{} {}
	/************************************
	* Constructor Name:		Book
	* Discription:			constructor
	************************************/
	B::Book(const std::string& strBook) {
		string tempStr = strBook;
		string tempNum;
		init(tempStr, m_author);
		init(tempStr, m_title);
		init(tempStr, m_country);
		init(tempStr, tempNum);
		m_price = stod(tempNum);
		init(tempStr, tempNum);
		m_year = stoi(tempNum);
		init(tempStr, m_desc, true);		
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
	void B::init(string& str, string& member, bool desc ) {
		size_t startNum = 0;
		for(size_t i = 0; i <str.length(); i++)
			if (str[i] != 32) {
				startNum = i;
				break;
			}
		size_t indexNum = str.find(',');
		if (indexNum != string::npos && !desc) {
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
	* Discription:				return m_title from Book class
	************************************/
	const std::string& B::title() const { return m_title; }
	/************************************
	* Function prototype:		const std::string& B::country() const
	* Function Name:			country
	* Function type:			const std::string&
	* Function Parameter:		NONE
	* Parameter type:			NONE
	* Discription:				return m_country from Book class
	************************************/
	const std::string& B::country() const { return m_country; }
	/************************************
	* Function prototype:		const size_t& B::year() const
	* Function Name:			year
	* Function type:			const size_t&
	* Function Parameter:		NONE
	* Parameter type:			NONE
	* Discription:				return m_year from Book class
	************************************/
	const size_t& B::year() const { return m_year; }
	/************************************
	* Function prototype:		const bool B::isMovie() const
	* Function Name:			isMovie
	* Function type:			const bool
	* Function Parameter:		NONE
	* Parameter type:			NONE
	* Discription:				A flag to check class 'Movie'
	************************************/
	const bool B::isMovie() const { return false; }
	/************************************
	* Function prototype:		double& B::price()
	* Function Name:			price
	* Function type:			double&
	* Function Parameter:		NONE
	* Parameter type:			NONE
	* Discription:				return m_price from Book class
	************************************/
	double& B::price() { return m_price; }
	/************************************
	* Function prototype:		std::ostream& operator << (std::ostream& os, const Book& data)
	* Function Name:			operator <<
	* Function type:			std::ostream&
	* Function Parameter:		os, data
	* Parameter type:			std::ostream&, const Book&
	* Default Parameter:		NONE
	* Return value/variable:	os
	* Discription:				print the value of Book class
	************************************/
	std::ostream& operator << (std::ostream& os, const Book& data) {
		os << std::setw(20) << data.m_author << " | ";
		os << std::setw(22) << data.m_title << " | ";	
		os << std::setw(5) << data.m_country << " | ";
		os << std::setw(4) << data.m_year << " | ";
		os.setf(ios::fixed);
		os.precision(2);
		os << std::setw(6) << data.m_price << " | ";
		os.unsetf(ios::fixed);
		os << data.m_desc << endl;
		return os;
	}
}

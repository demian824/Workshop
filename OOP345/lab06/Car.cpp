/*
	Student Name:	Wonchul Choi
	Student Nubmer:	118362201
	Student ID:	    wchoi28
	Student e-mail: wchoi28@myseneca.ca
	Course:         OOP345
	Workshop:	    Week6
*/
/************************************
	* File Name:				Car.cpp
	* Included Header/Library	
	* cctype
	* iomanip
	* Car.h
	* namespace:				sdds
	************************************/
#include <iomanip>
#include <cctype>
#include "Car.h"

namespace sdds {
	using namespace std;
	typedef Car C;
	/************************************
	* Constructor Name:		Car
	* Discription:			default constructor
	************************************/
	C::~Car(){}
	/************************************
	* Constructor Name:		Car
	* Discription:			constructor
	************************************/
	C::Car(std::istream& in) {		
		getline(in, m_maker, ',');
		removeSpace(m_maker);
		getline(in, m_condition, ',');
		removeSpace(m_condition, true);
		if(condition() == "none"){
			in.ignore(256, '\n');
			throw "Invalid record!";
		}
		std::string temp;
		in >> temp;
		removeSpace(temp);
		if (temp[0] >= 48 && temp[0] <= 57) { m_topSpeed = stod(temp); }
		else {
			in.ignore(256,'\n');
			throw "Invalid record!";
		}
	}
	/************************************
	* Function prototype:		void removeSpace(string& str, bool flag)
	* Function Name:			removeSpace
	* Function type:			void
	* Function Parameter:		str, flag
	* Parameter type:			std::string&, bool
	* Default Parameter:		desc = false
	* Discription:				remove the space in string
	************************************/
	void C::removeSpace(string& str, bool flag) {
		if (flag && str.empty()) str = "new";
		else {
			size_t startNum = 0;
			for (size_t i = 0; i < str.length(); i++) {
				if (str[i] != 32) {
					startNum = i;
					break;
				}
			}
			bool noSpace = false;
			size_t index = str.length() - 1;
			while (!noSpace) {
				if (str[index] != 32) noSpace = true;
				else {
					str.pop_back();
					if (index == 0) break;
					index--;
				}
			}
			if (flag && str.empty()) str = "new";
			else str = str.substr(startNum);
		}
	}
	/************************************
	* Function prototype:		std::string condition() const 
	* Function Name:			condition
	* Function type:			std::string
	* Function Parameter:		NONE
	* Discription:				check the condition of car
	************************************/
	std::string C::condition() const {
		std::string str;
		switch (m_condition[0])
		{
		case 'n':
			str = "new";
			break;
		case 'u':
			str = "used";
			break;
		case 'b':
			str = "broken";
			break;
		default:
			str = "none";
			break;
		}
		return str;
	}
	/************************************
	* Function prototype:		double topSpeed() const
	* Function Name:			topSpeed
	* Function type:			double
	* Function Parameter:		NONE
	* Discription:				return m_topSpeed
	************************************/
	double C::topSpeed() const { return m_topSpeed; }
	/************************************
	* Function prototype:		void display(std::ostream& out) const 
	* Function Name:			display
	* Function type:			void
	* Function Parameter:		out
	* Parameter type:			std::ostream&
	* Discription:				display the data
	************************************/
	void C::display(std::ostream& out) const {
		out.setf(std::ios::right);
		out << "| "<< std::setw(10) << m_maker << " | ";
		out.unsetf(std::ios::right);
		out.setf(std::ios::left);
		out << std::setw(6) << condition() << " | ";
		out.unsetf(std::ios::left);
		out.setf(ios::fixed);
		out.precision(2);
		out << std::setw(6) << topSpeed() << " |" ;
		out.unsetf(ios::fixed);
	}
}
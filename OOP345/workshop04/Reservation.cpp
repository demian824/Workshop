/*
	Student Name:	Wonchul Choi
	Student Nubmer:	118362201
	Student ID:	    wchoi28
	Student e-mail: wchoi28@myseneca.ca
	Course:         OOP345
	Workshop:	    Week4
*/
//composition
#include "Reservation.h"
#include <iostream>
#include <iomanip>
namespace sdds {
	typedef Reservation R;
	using namespace std;

	R::Reservation()
		: m_resPpl(0), m_resDay(0), m_resHour(0), m_resId{}, m_resName{}, m_resEmail{}, m_serviceTime{}, m_people{} {}
	R::Reservation(const string& res) {
		size_t indexNum = res.find(':');
		string temp;
		m_resId = res.substr(0, indexNum);
		removeSpace(m_resId);

		temp = res.substr(indexNum + 1);
		indexNum = temp.find(',');
		m_resName = temp.substr(0, indexNum);
		removeSpace(m_resName);

		temp = temp.substr(indexNum + 1);
		indexNum = temp.find(',');
		m_resEmail = temp.substr(0, indexNum);
		removeSpace(m_resEmail);
		
		temp = temp.substr(indexNum + 1);
		indexNum = temp.find(',');
		m_resPpl = stoi(temp.substr(0, indexNum));
		(m_resPpl > 1) ? m_people = "people" : m_people = "person";
		
		temp = temp.substr(indexNum + 1);
		indexNum = temp.find(',');
		m_resDay = stoi(temp.substr(0, indexNum));
		
		temp = temp.substr(indexNum + 1);
		m_resHour = stoi(temp.substr(0));
		setOption(m_serviceTime, m_resHour);
 	}
	
	void R::removeSpace(string& str) {
		bool found = false;
		size_t startIndex = 0;
		size_t strLen = str.m_length() - 1;
		for (size_t i = 0; i < strLen; i++) {
			if (str[i] != 32) {
				startIndex = i;
				break;
			}			
		}		
		while (!found) {
			if (str[strLen--] == 32)
				str.pop_back();
			else found = true;
		}
		str = str.substr(startIndex);
	}
	void R::setOption(string& service, const int& hour) {
		string str;
		if (hour > 5 && hour < 10)	service = "Breakfast";
		else if (hour > 10 && hour < 16)	service = "Lunch";
		else if (hour > 16 && hour <= 21)	service = "Dinner";
		else service = "Drinks";
	}
	bool R::isEmpty() const {
		return m_resId.size() <= 0 ? true : false;
	}
	
	
	ostream& operator << (std::ostream& os, const Reservation& res)
	{
		os << "Reservation ";
		os.setf(std::ios::right);
		os << std::setw(10) << res.m_resId << ":           ";
		os << std::setw(10) << res.m_resName << "  ";
		os.unsetf(std::ios::right);
		string tempEmail = "<" + res.m_resEmail + ">";
		os.setf(std::ios::left);
		os << std::setw(20)  << tempEmail;
		os.unsetf(std::ios::left);
		os << "    " << res.m_serviceTime << "on day " << res.m_resDay << " @ " << res.m_resHour << ":00 for " << res.m_resPpl << " " << res.m_people << "." << endl;
		
		return os;
	}
	
	
}
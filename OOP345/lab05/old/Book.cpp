#include <iomanip>
#include "Book.h"

namespace sdds {
	using namespace std;
	typedef Book B;
	B::Book()
		: m_year(0), m_price(0.0), m_author{}, m_title{}, m_country{}, m_desc{} {}
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
	const std::string& B::title() const { return m_title; }
	const std::string& B::country() const { return m_country; }
	const size_t& B::year() const { return m_year; }
	double& B::price() { return m_price; }
	std::ostream& operator << (std::ostream& os, Book data) {
		os << std::setw(20) << data.m_author << " | ";
		os << std::setw(22) << data.m_title << " | ";	
		os << std::setw(5) << data.m_country << " | ";
		os << std::setw(4) << data.m_year << " | ";
		os.setf(ios::fixed);
		os.precision(2);
		os << std::setw(6) << data.m_price << " | ";
		os.unsetf(ios::fixed);
		os << data.m_desc;		
		return os;
	}
}

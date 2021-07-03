#include "Reservation.h"
#include <iostream>
#include <iomanip>
#include <algorithm>
namespace sdds {
	typedef Reservation R;
	using namespace std;

	R::Reservation()
		: m_resPpl(0), m_resDay(0), m_resHour(0), m_resId{}, m_resName{}, m_resEmail{}, m_serviceTime{}, m_people{} {}
	R::Reservation(const string& res) {
		string::size_type arr[4]{};
		string noSpace;
		
		copyStr(res, noSpace);		
		commaIndex(noSpace, arr);
		init(res, noSpace, arr);
		setOption();
 	}
	void R::copyStr(const string& origin, string& copy) {
		string tempOrigin = origin;
		string::size_type sCount = std::count(tempOrigin.begin(), tempOrigin.end(), ' ');
		std::remove(tempOrigin.begin(), tempOrigin.end(), ' ');
		copy = tempOrigin.substr(0, tempOrigin.length() - sCount);
	}
	void R::commaIndex(const string& str, string::size_type* arr) {
		string::size_type i = 0, j = 0;
		while (i < str.size())
			if (str[i++] == ',') arr[j++] = i - 1;
	}
	void R::init(const string& origin, const string& str, string::size_type* arr) {
		string::size_type indexNum;
		if (str.find("RES") == std::string::npos) {
			indexNum = origin.find(":");
			m_resId = origin.substr(0, indexNum);
		}
		else {
			indexNum = str.find(":");
			m_resId = str.substr(0, indexNum);
			if (m_resId.find("-") == std::string::npos) m_resId.insert(3, " ");
		}
		

		indexNum = str.find(":");

		//bool isFind = false;
		//string temp = origin.substr(indexNum+1, 13);
		//cout << temp;
		//int firstChar;
		//int lastChar;
		m_resName = str.substr(indexNum + 1, arr[0] - indexNum - 1);

		//for (int i = 0; i < temp.length(); i++) {
		//	if (temp[i] >= 'A' && temp[i] <= 'Z') { 
		//		firstChar = static_cast<int>(i);
		//		lastChar = temp.find(',');
		//		break; 
		//	}
		//}
		//
		
		//m_resName = setName(origin);/*temp.substr(firstChar, lastChar);
		
		m_resEmail = str.substr(arr[0] + 1, (arr[1] - arr[0]) - 1);
		m_resPpl = stoi(str.substr(arr[1] + 1, (arr[2] - arr[1]) - 1));
		m_resDay = stoi(str.substr(arr[2] + 1, (arr[3] - arr[2]) - 1));
		m_resHour = stoi(str.substr(arr[3] + 1));
	}
	/*void R::setName(const string& str, const string& copy) {
		bool isFind = false;
		int firstChar = 0,
			lastChar = 0;
		string::size_type indexNum = str.find(":");
		
		for (string::size_type i = indexNum; i < str.length(); i++) {
			if (str[i] >= 65 && str[i] <= 90) {
				firstChar = static_cast<int>(i);
				lastChar = str.find(',');
				lastChar -= firstChar;
				break;
			}
		}
		string temp = str.substr(firstChar, lastChar);
		for (int i = lastChar - 1; 0 <= i && !isFind; i--) {
			if (temp[i] >= 97 && temp[i] <= 122)
				isFind = true;
			else
				temp.pop_back();
		}
		temp.copy(copy, temp.size());
	}*/
	bool R::isEmpty() const {
		if (m_resId.size()) return true;
		else return false;
	}
	void R::setOption() {
		(m_resPpl > 1)  ? m_people = "people" : m_people = "person";
		
		if (m_resHour > 5 && m_resHour < 10)	m_serviceTime = "Breakfast";
		else if (m_resHour > 10 && m_resHour < 16)	m_serviceTime = "Lunch";
		else if (m_resHour > 16 && m_resHour <= 10)	m_serviceTime = "Dinner ";
		else m_serviceTime = "Drinks";		
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
		os << "    " << res.m_serviceTime << " on day " << res.m_resDay << " @ " << res.m_resHour << ":00 for " << res.m_resPpl << " " << res.m_people << "." << endl;
		
		return os;
	}
	
	
}
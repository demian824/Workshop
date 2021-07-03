#pragma once
#include <string>

namespace sdds {
	class Reservation {
		unsigned int m_resPpl;
		unsigned int m_resDay;
		unsigned int m_resHour;
		std::string m_resId;
		std::string m_resName;
		std::string m_resEmail;
		std::string m_serviceTime;
		std::string m_people;		
		void copyStr(const std::string& origin, std::string& copy);
		void init(const std::string& origin, const std::string& str, std::string::size_type* arr);
		void commaIndex(const std::string& str, std::string::size_type* arr);
		void setOption();
		//void setName(const std::string& str, const string& copy);
	public:
		Reservation();
		Reservation(const std::string& res);
		bool isEmpty() const;
		//Reservation& operator = (const Reservation& res);
		friend std::ostream& operator << (std::ostream& os, const Reservation& res);

	};
}
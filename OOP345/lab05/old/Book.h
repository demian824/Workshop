#pragma once
#include <iostream>
#include <string>
namespace sdds {
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
		void init(std::string& str, std::string& memeber, bool desc = false);
		const std::string& title() const;
		const std::string& country() const;
		const size_t& year() const;
		double& price();
		friend std::ostream& operator << (std::ostream& os, Book data);
	};

}
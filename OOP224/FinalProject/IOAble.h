/*
	Student Name:	Wonchul Choi
	Student Nubmer:	118362201
	Student ID:	    wchoi28
	Student e-mail: wchoi28@myseneca.ca
	Course:         OOP244
	Final project:  MS2
*/
#ifndef SDDS_IOABLE_H_
#define SDDS_IOABLE_H_
#include <iostream>
namespace sdds {
	class IOAble {
	public:
		virtual std::istream& read(std::istream& istr) = 0;
		virtual std::ostream& write(std::ostream& ostr)const = 0;
		virtual std::istream& csvRead(std::istream& istr) = 0;
		virtual std::ostream& csvWrite(std::ostream& ostr)const = 0;
		virtual ~IOAble();
	};
	std::ostream& operator << (std::ostream& os, const IOAble& io);
	std::istream& operator >> (std::istream& in, IOAble& io);
}
#endif // !SDDS_IOABLE_H_
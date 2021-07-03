/*
	Student Name:	Wonchul Choi
	Student Nubmer:	118362201
	Student ID:	    wchoi28
	Student e-mail: wchoi28@myseneca.ca
	Course:         OOP244
	Workshop:	    Week05_PT2
*/
#include <iostream>
#include "Mark.h"

namespace sdds {

	typedef Mark m;

	m::Mark(int score )
	: m_grade('F'), m_scale(0.0), m_score(score){
		if (score < 0 || score > 100) {
			m_score = 0;
			m_grade = 'X';
		}
		else {
			m_score = score;
			init(m_score);
		}
	}
	m::~Mark(){}
	void m::init(int score) {
		if (m_grade != 'X') {
			if (100 >= score && score >= 80)
				m_grade = 'A';
			else if (80 >= score && score >= 70)
				m_grade = 'B';
			else if (70 >= score && score >= 60)
				m_grade = 'C';
			else if (60 >= score && score >= 50)
				m_grade = 'D';
			else if (50 >= score && score > -1)
				m_grade = 'F';
		}

		switch (m_grade) {
		case'A':
			m_scale = 4.0;
			break;
		case'B':
			m_scale = 3.0;
			break;
		case'C':
			m_scale = 2.0;
			break;
		case'D':
			m_scale = 1.0;
			break;
		default:
			m_scale = 0.0;
			break;
		}
	}

	//Overload cast operators
	m::operator int() const { return m_score; }
	m::operator double() const { return m_scale; }
	m::operator char() const { return m_grade; }
	//Overload compound assign operators
	int operator += (int& num, const Mark& mk) { return num += mk.m_score; }
	Mark& m::operator +=(const int& num) {
		int temp = 0;
		if (this->m_grade != 'X') {
			temp = this->m_score += num;
			init(temp);
			if (temp > 100) {
				this->m_score = 0;
				this->m_grade = 'X';
				this->m_scale = 0.0;
			}
		}
		return *this;
	}
}
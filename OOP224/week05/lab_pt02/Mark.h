/*
	Student Name:	Wonchul Choi
	Student Nubmer:	118362201
	Student ID:	    wchoi28
	Student e-mail: wchoi28@myseneca.ca
	Course:         OOP244
	Workshop:	    Week05_PT2
*/
#pragma once
namespace sdds {
	class Mark {
	private:
		char	m_grade;
		double	m_scale;
		int		m_score;
	public:
		//constructor
		Mark(int score = 0);
		//destructor
		~Mark();
		//initialization function
		void init(int score);
		//cast operator
		operator char() const;
		operator int() const;
		operator double() const;
		//Compound assignment operator
		Mark& operator += (const int& num);
		friend int operator += (int& num, const Mark& mk);
	};
}
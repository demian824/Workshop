/*
	Student Name:	Wonchul Choi
	Student Nubmer:	118362201
	Student ID:	wchoi28
	Student e-mail: wchoi28@myseneca.ca
	Course:         OOP244
	Workshop:	Week04_PT1
*/
#include "Subject.h"

using namespace std;

namespace sdds {
	typedef Subject S;

	S::Subject(){
		setEmpty();
	}
	S::~Subject(){
	}
	void S::setEmpty() {
		for (int i = 0; i < 7; i++)
			m_code[i] = '\0';
		m_mark = 0;

		if (m_code[0] != '\0')
		{
			cout << "Failed to make an empty" << endl;
			exit(1);
		}
	}
	//Grade and Score
	char S::grade()const{
		char grade;

		if (m_mark > 50)
		{
			if (m_mark <= 100 && m_mark >= 80)
				grade = 'A';
			else if (m_mark < 80 && m_mark >= 70)
				grade = 'B';
			else if (m_mark < 70 && m_mark >= 60)
				grade = 'C';
			else
				grade = 'D';
		}
		else
			grade = 'F';
		printf("%s%12d", m_code, m_mark);

		return grade;
	}
	float S::scale4()const {
		float scale = 0.0;
		char stdGrade = grade();
		switch (stdGrade)
		{
		case 'A':
			scale = 4.0f;
			break;
		case 'B':
			scale = 3.0f;
			break;
		case 'C':
			scale = 2.0f;
			break;
		case 'D':
			scale = 1.0f;
			break;
		}
		printf("%10c\n", stdGrade );
			
		return scale;
	}
	void S::set(const char* code, int mark){
		if(m_code[0] == '\0')
		{
			if (code != nullptr)
				strcpy(m_code, code);
			m_mark = mark;
		}
	}	
	bool S::isValid()const{
		bool ok = false;
		
		if (m_code != nullptr)
			if (m_mark <= 100 && m_mark >= 0)
			{
				cout << m_code;
				ok = true;
			}
		
		return ok;
	}
}
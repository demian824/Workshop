/*
	Student Name:	Wonchul Choi
	Student Nubmer:	118362201
	Student ID:	    wchoi28
	Student e-mail: wchoi28@myseneca.ca
	Course:         OOP244
	Workshop:	    Week04_PT1
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Transcript.h"
#include "Subject.h"

using namespace std;

namespace sdds {
	typedef Transcript Trans;
	
	Trans::Transcript()	{
		setEmpty();
	}
	Trans::~Transcript() {

	}
	bool Trans::add(const char* subject_code, int mark)
	{
		bool ok = true;

		if (subject_code == nullptr)
			ok = false;
		else {
			m_subjects[m_subjectsAdded].set(subject_code, mark);

			if (ok)	m_subjectsAdded++;
		}
		return 	ok;
	}
	bool Trans::isValid()const
	{
		bool ok = false;

		if (m_subjects != nullptr && m_studentName != nullptr)
			ok = true;

		return ok;
	}
	//Output functions
	void Trans::title()const
	{
		cout << m_studentName << endl;
		cout << "-----------------------------" << endl;
	}
	void Trans::display()const
	{
		float	temp_score = 0.0;

		if (m_subjectsAdded == m_noOfSubjects)
		{
			title();
			temp_score = gpa();
			footer();
			printf("%.1f\n", temp_score);
		}
		else
			cout << "Invalid Transcirpt!" << endl;
	}
	float Trans::gpa()const
	{
		float sum = 0.0;
		float avrg = 0.0;

		for (int i = 0; i < m_noOfSubjects; i++)
			sum += m_subjects[i].scale4();
		
		avrg = sum / m_noOfSubjects;

		return avrg;
	}
	void Trans::footer()const
	{
		cout << "-----------------------------" << endl;
		cout << "                     GPA: ";
	}
	void Trans::warningMessage()
	{
		cout << "fail to dynamic memory allocation" << endl;
		exit(1);
	}
	//Initialize variable
	void Trans::setEmpty()
	{
		m_studentName	= nullptr;
		m_subjects		= nullptr;
		m_noOfSubjects	= 0;
		m_subjectsAdded = 0;
	}
	//Memory functions
	void Trans::init(const char* studentName, int noOfSubjects) {
		
		//Dynamic memory allocation
		int nameLength = strlen(studentName);
		m_studentName = new char[nameLength + 1];
		if (m_studentName == nullptr)
			warningMessage();
		
		//Assign the data
		m_subjectsAdded = 0;
		strcpy(m_studentName, studentName);
		if (noOfSubjects >= 1)
		{
			m_noOfSubjects = noOfSubjects;
			m_subjects = new Subject[m_noOfSubjects];
			if (m_subjects == nullptr)
				warningMessage();
		}
		else
		{
			setEmpty();
			m_noOfSubjects = 0;
		}
	}
	void Trans::deallocate()
	{
		delete[] m_studentName;
		delete[] m_subjects;
	}
}
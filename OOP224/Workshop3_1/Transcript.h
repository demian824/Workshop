/*
	Student Name:	Wonchul Choi
	Student Nubmer:	118362201
	Student ID:	    wchoi28
	Student e-mail: wchoi28@myseneca.ca
	Course:         OOP244
	Workshop:	    Week04_PT1
*/#pragma once

#include "Subject.h"

namespace sdds{
	class Transcript{
	private:
		//private member variables
		char* m_studentName; // pointer to hold the student name dynamically 
		Subject* m_subjects; // pointer to hold the subjects in the Transcript dynamically
		int m_noOfSubjects;  // Number of subjects or number of elements in the array of m_subjects.
		int m_subjectsAdded; // Number of subjects in the m_subjects array that are set to thier values properly (they are not empty)
		//private member function
		void setEmpty();
		bool isValid()const;
		void title()const;
		float gpa()const;
		void footer()const;
		void warningMessage();
	public:
		//public member variable
		//constructor and distructor
		Transcript();
		~Transcript();
		//public member function
		void init(const char* studentName, int noOfSubjects);
		bool add(const char* subject_code, int mark); 
		void display()const;
		void deallocate();
	};

}
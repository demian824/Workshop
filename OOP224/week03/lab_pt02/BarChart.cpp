/*
	Student Name:		Wonchul Choi
	Student Nubmer:		118362201
	Student ID:	    	wchoi28
	Student e-mail: 	wchoi28@myseneca.ca
	Course:         	OOP244
	Workshop:	    	Week03_PT2
*/
#define _CRT_SECURE_NO_WARNINGS
#include "BarChart.h"

using namespace std;

namespace sdds
{
	typedef BarChart BC;
		
	void BC::init(const char* title, const int noOfSampels, const char fill)
	{
		m_title		= new char[strlen(title) + 1];
		m_bar		= new Bar[noOfSampels];
		m_ch		= fill;
		m_size		= noOfSampels;
		m_indexNum	= 0;

		if (m_title == nullptr) {
			cout << "fail to memory allocation of title array";
			exit(1);
		}
		else
			strcpy(m_title, title);

		if (m_bar == nullptr) {
			cout << "fail to memory allocation of class array";
			exit(1);
		}
	}

	void BC::add(const char* bar_title, const int value){
		m_bar[m_indexNum].set(bar_title, m_ch, value);
		m_indexNum++;
	}
	void BC::printBar()const {
		for (int i = 0; i < 71; i++)
			cout << "-";
		cout << endl;
	}
	void BC::draw()const{
		if (m_indexNum != m_size)
			cout << "Invalid Chart!"<< endl;
		else
		{
			cout << m_title << endl;
			printBar();
			for (int i = 0; i < m_size; i++)
				m_bar[i].draw();
			printBar();
		}
	}
	void BC::deallocate(){
		delete[] m_bar;
		delete[] m_title;
		m_bar = nullptr;
		m_title = nullptr;
	}};
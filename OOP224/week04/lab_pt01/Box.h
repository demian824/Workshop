/*
    Student Name:	Wonchul Choi
    Student Nubmer:	118362201
    Student ID:	    wchoi28
    Student e-mail: wchoi28@myseneca.ca
    Course:         OOP244
    Workshop:	    Week04_PT1
*/
#pragma once
#include <iostream>
#include <iomanip>
#include <cstdarg>
#include <cstring>

namespace sdds {
	class Box {
        char* m_contentName;   
        int m_width;           
        int m_height;
        int m_length;
        int m_contentVolume;
        void setName(const char* Cstr);
        void setUnusable();
        bool isUnusable()const;
        bool hasContent()const;
    public:
        //Constructor with function overloading
        Box(int sideLength = 12, const char* contentName = nullptr);
        Box(int width, int height, int length, const char* contentName = nullptr);
        //destructor 
        ~Box();
        int capacity() const;
        int quantity()const;
        //Use reference of class to return type
        Box& setContent(const char* contentName);
        Box& add(int quantity);
        Box& add(Box& B);
        //Output stream
        std::ostream& display()const;
	};
};
/*
    Student Name:	Wonchul Choi
    Student Nubmer:	118362201
    Student ID:	    wchoi28
    Student e-mail: wchoi28@myseneca.ca
    Course:         OOP244
    Workshop:	    Week06
*/
#ifndef SDDS_NUMBERS_H_
#define SDDS_NUMBERS_H_
#include <iostream>
namespace sdds {
    class Numbers {
        double* m_numbers;
        char* m_filename;
        bool m_isOriginal;
        int m_numCount;
        bool isEmpty()const;
        void setEmpty();
        void setFilename(const char* filename);
        void sort();
    public:
        Numbers();
        Numbers(const char* filename);
        double average()const;
        double max()const;
        double min()const;
        ~Numbers();

        //Copy constructor
        Numbers(Numbers& nb);
        Numbers& operator=(const Numbers& nb);
        //Countline with eof
        int numberCount();
        //File in/output
        bool load();
        void save();
        //overload operators 
        Numbers& operator += (const double num);
        std::ostream& display(std::ostream& ostr) const;
        friend std::ostream& operator << (std::ostream& os, const Numbers& N);
        friend std::istream& operator >> (std::istream& istr, Numbers& N);

    };
}
#endif // !SDDS_NUMBERS_H_

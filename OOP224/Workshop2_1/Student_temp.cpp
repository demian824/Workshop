#define _CRT_SECURE_NO_WARNINGS
/*
    Student Name:	Wonchul Choi
    Student Nubmer:	118362201
    Student ID:	    wchoi28
    Student e-mail: wchoi28@myseneca.ca
    Course:         OOP244
    Workshop:	    Week02
*/
#include <iostream>
#include <cstring>
#include "Student.h"
#include "File.h"

using namespace std;

namespace sdds
{
    int noOfStudents;
    Student* students;

    void sort()
    {
        int i, j;
        Student temp;
        for (i = noOfStudents - 1; i > 0; i--)
            for (j = 0; j < i; j++)
                if (students[j].m_gpa > students[j + 1].m_gpa)
                {
                    temp = students[j];
                    students[j] = students[j + 1];
                    students[j + 1] = temp;
                }
    }


    bool loadName(Student *str)
    {
        bool ok= false;
        char name[128];
        bool flag = false;

        if (sdds::readSname(name))
        {
            str->m_name = new char[sizeof(name)];
            //strcpy(string, name);
            
             
            if (sizeof(string) == 0)
                cout << "failed to memory allocation" << endl;
            else
            {
                ok = true;
                strncpy(str->m_name, name, sizeof(name));
            }
            //delete[] string;
        }
        return ok;
    }

    bool load()
    {
        bool ok = false;
        int i = 0;
        if (openFile(DATAFILE))
        {
            noOfStudents = noOfRecords();
            students = new Student[noOfStudents];
                  
            if (!openFile(DATAFILE))
                cout << "Error: incorrect number of records read; the data is possibly corrupted" << endl;
            else
                ok = true;
            if (ok)
            {
                for (i = 0; i < noOfStudents; i++)
                {
                    loadName(&students[i]);
                    loadNumb(&students[i].m_studentNumber);
                    loadGpa(&students[i].m_gpa);
                }
            }

            closeFile();
        }
        else
            cout << "Could not open data file: " << DATAFILE << endl;

        return ok;
    }


    void display()
    {
        sort();
        
        for (int i = 0; i < noOfStudents; i++)
        {
            cout.width(22);
            cout << students[i].m_name << "\t" << students[i].m_studentNumber << "\t" << students[i].m_gpa << endl;
        }
    }


    bool loadNumb(int* sNum)
    {
        bool ok = false;
        unsigned int temp = 0;

        if (!readSnumb(&temp))
            cout << "failed the load Number" << endl;
        else
        {
            ok = true;
            *sNum = static_cast<int>(temp);
        }
        return ok;
    }
    
    bool loadGpa(double* sGpa)
    {
        bool ok = false;
        double temp = 0.0;

        if(!readSgpa(&temp))
            cout << "failed the load Number" << endl;
        else
        {
            ok = true;
            *sGpa = temp;
        }

        return ok;
    }

    void deallocateMemory()
    {
        for (int i = 0; i < noOfStudents; i++)
            delete[] students[i].m_name;
        delete[] students;
    }

}
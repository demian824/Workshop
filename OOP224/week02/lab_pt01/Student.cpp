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
    void display()
    {
        sort();
        for (int i = 0; i < noOfStudents; i++)
            cout << i + 1 << ": " << students[i].m_name << ", " << students[i].m_studentNumber << ": " << students[i].m_gpa << endl;
    }
    void deallocateMemory()
    {
        for (int i = 0; i < noOfStudents; i++)
            delete[] students[i].m_name;
        delete[] students;
    }
    bool load()
    {
        bool ok = false;
        int i = 0;
        if (openFile(DATAFILE))
        {
            noOfStudents = noOfRecords();
            students = new Student[noOfStudents];
            ok = true;
            if (ok)
                for (i = 0; i < noOfStudents; i++)
                {
                    if (loadName(&students[i]))
                    {
                        if (loadNumb(&students[i].m_studentNumber))
                        {
                            if (!loadGpa(&students[i].m_gpa))
                            {
                                cout << "Failed to load data from file. Finish the program" << endl;
                                exit(1);
                            }
                        }
                        else
                        {
                            cout << "Failed to load data from file. Finish the program" << endl;
                            exit(1);
                        }
                    }
                    else
                    {
                        cout << "Failed to load data from file. Finish the program" << endl;
                        exit(1);
                    }
                }
            closeFile();
        }
        else
            cout << "Could not open data file: " << DATAFILE << endl;

        return ok;
    }
    bool loadName(Student* str)
    {
        bool ok = false;
        char name[128];

        if (sdds::readSname(name))
        {
            str->m_name = new char[sizeof(name)];

            if (sizeof(str->m_name) == 0)
                cout << "failed to memory allocation" << endl;
            else
            {
                ok = true;
                strncpy(str->m_name, name, sizeof(name));
            }
        }

        return ok;
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

   

}
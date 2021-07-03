#ifndef SDDS_STUDENT_H_
#define SDDS_STUDENT_H_

#define DATAFILE "students.csv"
/*
    Student Name:	Wonchul Choi
    Student Nubmer:	118362201
    Student ID:	    wchoi28
    Student e-mail: wchoi28@myseneca.ca
    Course:         OOP244
    Workshop:	    Week02
*/
namespace sdds {
    struct Student {
        char* m_name;
        int m_studentNumber;
        double m_gpa;
    };

    void sort();
    void display();
    //Deallocation function 
    void deallocateMemory();
    //Functions for copy the data from file to program.
    bool load();
    bool loadName(Student* str);
    bool loadNumb(int* sNum);
    bool loadGpa(double* sGpa);
}
#endif // SDDS_STUDENT_H_
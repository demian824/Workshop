/*
    Student Name:	Wonchul Choi
    Student Nubmer:	118362201
    Student ID:	    wchoi28
    Student e-mail: wchoi28@myseneca.ca
    Course:         OOP244
    Workshop:	    Week06
*/
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <fstream>
#include "Numbers.h"
using namespace std;
namespace sdds {
    Numbers::Numbers() {
        setEmpty();
        m_isOriginal = false;
    }
    Numbers::Numbers(const char* filename) {
        setEmpty();
        m_isOriginal = true;
        setFilename(filename);
        m_numCount = numberCount();
       if (m_numCount == 0 || !load()) {
            delete[] m_numbers;
            delete[] m_filename;
            setEmpty();
            m_isOriginal = false;
        }
        else {
            sort();
        }
    }
    Numbers::~Numbers() {
        cout << "destoryer" << endl;
        save();
        delete[] m_numbers;
        delete[] m_filename;
    }
    bool Numbers::isEmpty() const {
        return m_numbers == nullptr;
    }
    void Numbers::setEmpty() {
        m_numbers = nullptr;
        m_filename = nullptr;
        m_numCount = 0;
    }
    void Numbers::setFilename(const char* filename) {
        delete[] m_filename;
        m_filename = new char[strlen(filename) + 1];
        strcpy(m_filename, filename);
    }
    void Numbers::sort() {
        int i, j;
        double temp;
        for (i = m_numCount - 1; i > 0; i--) {
            for (j = 0; j < i; j++) {
                if (m_numbers[j] > m_numbers[j + 1]) {
                    temp = m_numbers[j];
                    m_numbers[j] = m_numbers[j + 1];
                    m_numbers[j + 1] = temp;
                }
            }
        }
    }
    double Numbers::average() const {
        double aver = 0.0;
        if (!isEmpty()) {
            for (int i = 0; i < m_numCount; i++)
                aver += m_numbers[i];
            aver = aver / m_numCount;
        }
        return aver;
    }
    double Numbers::min() const {
        double minVal = 0.0;
        if (!isEmpty()) {
            minVal = m_numbers[0];
            for (int i = 1; i < m_numCount; i++)
                if (minVal > m_numbers[i]) minVal = m_numbers[i];
        }
        return minVal;
    }
    double Numbers::max() const {
        double maxVal = 0.0;
        if (!isEmpty()) {
            maxVal = m_numbers[0];
            for (int i = 1; i < m_numCount; i++)
                if (maxVal < m_numbers[i]) maxVal = m_numbers[i];
        }
        return maxVal;
    }

    Numbers::Numbers(Numbers& nb) {
        setEmpty();
        m_isOriginal = false;
        *this = nb;
    }
    Numbers& Numbers::operator=(const Numbers& nb) {
        double temp;        
        if(this != &nb){
            if(nb.m_numCount > 0)
                m_numCount = nb.m_numCount;

            if (!isEmpty())
                delete[] m_numbers;
                
            m_numbers = new double[m_numCount];

            for (int i = 0; i < m_numCount; i++) {
                temp = nb.m_numbers[i];
                m_numbers[i] = temp;
            }
        }
        return *this;
    }
    int Numbers::numberCount() {
        ifstream readFile;
        int lineCount = 0; 
        char temp;
        readFile.open(m_filename);
        if (readFile.is_open()) {
            while (!readFile.eof()) {
                readFile.get(temp);
                if (temp == '\n')
                    lineCount += 1;
            }
            if(lineCount > 0)
                lineCount -= 1;
        }
        else
            cout << "Failed to open the file in numberCount" << endl;
        readFile.close();

        return lineCount;
    }
    bool Numbers::load() {
        bool ok = false;
        int index = 0;
        double temp;
        ifstream readFile;
        
        if (m_numCount > 0) {
            if (m_numbers != nullptr)
                delete[] m_numbers;
            m_numbers = new double[m_numCount];
        }

        if (m_numbers) {
            readFile.open(m_filename);
            if (readFile.is_open()) 
                while (readFile) {
                    readFile >> temp;
                    if (readFile && index < m_numCount) {
                        m_numbers[index] = temp;
                        index++;
                    }
                }
            readFile.close();
            ok = true;
        }

        else
            cout << "fail to memory allocation in load()" << endl;
        return ok;
    }
    void Numbers::save() {
        ofstream writeFile;
        if (m_isOriginal == true && m_filename != nullptr) {
            writeFile.open(m_filename);
            if (!writeFile.is_open()) 
                cout << "fail to open the file in save()" << endl;
            for (int i = 0; i < m_numCount; i++) 
                writeFile << m_numbers[i] << endl;
        }            
        writeFile.close();
    }
    Numbers& Numbers::operator += (const double num) {
        int index = 0;
        double* tempArr;
        if (m_numbers != nullptr) {
            m_numCount += 1;
            tempArr = new double[m_numCount];

            if (!tempArr)
                cout << "Fail to memory allocation in operator+=" << endl;

            for (index = 0; index < m_numCount - 1; index++)
                tempArr[index] = m_numbers[index];
            
            tempArr[index] = num;
            delete[] m_numbers;
            m_numbers = tempArr;
        }
        return *this;
    }
    std::ostream& Numbers::display(std::ostream& ostr) const {
        if (!m_numbers)
            ostr << "Empty list" << endl;
        else {
            ostr << "=========================" << endl;
            if (!m_isOriginal)
                ostr << "*** COPY ***" << endl;
            else
                ostr << m_filename << endl;
            for (int i = 0; i < m_numCount; i++) {
                ostr << m_numbers[i];
                if (i != m_numCount - 1)
                    ostr << ", ";
            }
            ostr << endl<< "-------------------------" << endl;
            ostr << "Total of " << m_numCount << " number(s)" << endl;
            ostr << "Largest number:  " << max() << endl;
            ostr << "Smallest number: " << min() << endl;
            ostr << "Average :        " << average() << endl;
            ostr << "=========================";
        }    
        return ostr;
    }
    std::ostream& operator << (std::ostream& os, const Numbers& N) {
        N.display(os);
        return os;
    }
    std::istream& operator >> (std::istream& istr, Numbers& N) {
        double temp;

        istr >> temp;
        N += temp;
        N.sort();

        return istr;
    }
}
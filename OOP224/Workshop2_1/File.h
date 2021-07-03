#ifndef SDDS_FILE_H_
#define SDDS_FILE_H_
/*
	Student Name:	Wonchul Choi
	Student Nubmer:	118362201
	Student ID:	    wchoi28
	Student e-mail: wchoi28@myseneca.ca
	Course:         OOP244
	Workshop:	    Week02
*/
namespace sdds {
	bool openFile(const char filename[]);
	void closeFile();
	int noOfRecords();
	//Functions for read data from the csv file
	bool readSname(char* name);
	bool readSnumb(unsigned int* snumber);
	bool readSgpa(double* score);
}
#endif // !SDDS_FILE_H_

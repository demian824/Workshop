/*
    Student Name:		Wonchul Choi
    Student Nubmer:	    118362201
    Student ID:	   	    wchoi28
    Student e-mail: 	wchoi28@myseneca.ca
    Course:         	OOP244
    Workshop:	    	Week02_DIY
*/

#ifndef SDDS_FILE_H_
#define SDDS_FILE_H_
namespace sdds {
	bool openFile(const char filename[]);
	void closeFile();
	int noOfRecords();

	bool readAccount(unsigned int* account);
	bool readBalance(double* balance);
}
#endif // !SDDS_FILE_H_

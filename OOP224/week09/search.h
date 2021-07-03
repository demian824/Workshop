/*
    Student Name:	Wonchul Choi
    Student Nubmer:	118362201
    Student ID:	    wchoi28
    Student e-mail: wchoi28@myseneca.ca
    Course:         OOP244
    Workshop:	    Week09
*/
#ifndef SDDS_SEARCH_H_
#define SDDS_SEARCH_H_


namespace sdds {
    template <class C, typename T >
    bool search(C& arr, int num, const char* key, T& colRef) {
        bool isWork = true;
        int i, j = 0;
        int* indexArr = new int[num];
                
        for (i = 0; i < num; i++) {
            if (arr[i] == key) 
                indexArr[j++] = i;
        }

        if (j > 0) {
            colRef.resize(j);
            for (i = 0; i < j; i++) {
                int temp = indexArr[i];
                colRef[i] = arr[temp];
            }
        }
        else
            isWork = false;
        delete[] indexArr;
        
        return isWork;
    }
   
}

#endif // !SDDS_SEARCH_H_
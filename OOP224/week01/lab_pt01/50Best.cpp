/*
    Student Name:	Wonchul Choi
    Student Nubmer:	118362201
    Student ID:	    wchoi28
    Course:         OOP244
    Workshop:	    Week01
*/

#include <iostream>
#include "Movie.h"

using namespace std;
using namespace sdds;

void flushkeys();
bool yes();

int main() {
    if (openFile("Hello")) cout << "fail" << endl;
    bool done = false;
    char genre[128];
    loadMovies();
    cout << "Welcome to 50 top movies of all times \"genre\" search." << endl << endl;
    while (!done) {
        cout << "Enter the movie genre to start the search: ";
        cin >> genre;
        flushkeys();
        displayMoviesWithGenre(genre);
        cout << "Do another search? (Y)es: ";
        done = !yes();
        cout << endl;
    }
    cout << "Goodbye!" << endl;
    return 0;
}

void flushkeys() {
    while (std::cin.get() != '\n');
}
// returns true if user enter y or Y
bool yes() {
    char ch = std::cin.get();
    flushkeys();
    return ch == 'y' || ch == 'Y';
}
/*
	Student Name:	Wonchul Choi
	Student Nubmer:	118362201
	Student ID:	    wchoi28
	Student e-mail: wchoi28@myseneca.ca
	Course:         OOP345
	Workshop:	    Week7
*/
/************************************
	* File Name:			SongCollection.h
	* Included Header/Library
	*	iostream
	*	string
	*	list
	* namespace:			sdds
	* preprocessor:			#pragma once
	************************************/
#pragma once

#include<iostream>
#include<string>
#include<vector>
#include<list>

namespace sdds {
	/************************************
		* Structure Name:			Song
		* Member Variable:		m_artist, m_title, m_album, m_price, m_year, m_length
		* Member Variable type: std::string, std::string, std::string, double, std::string, size_t
		************************************/
	struct Song {
		std::string m_artist = {};
		std::string m_title = {};
		std::string m_album = {};
		double		m_price = 0.0;
		std::string	m_year = {};
		size_t		m_length = 0.0;
	};
	/************************************
		* Class Name:			SongCollection
		* Member Variable:		m_songData
		* Member Variable type: std::vector<Song>
		* Constructor:			SongCollection(const char* filename) 
		* Member Function:
		*	 void removeSpace(std::string& str)
		*	 void display(std::ostream& out) const
		*	 void sort(const char* str)
		*	 void cleanAlbum()
		*	 bool inCollection(const char* str) const
		*	 std::list<Song> getSongsForArtist(const char* str) const
		************************************/
	class SongCollection {
		std::vector<Song> m_songData;
		void removeSpace(std::string& str);
	public:
		SongCollection(const char* filename);
		void display(std::ostream& out) const;
		void sort(const char* str);
		void cleanAlbum();
		bool inCollection(const char* str) const;		
		std::list<Song> getSongsForArtist(const char* str) const;		
	};
	/*
	 * Function:
	 *	 bool compAlbum(const Song& song1, const Song& song2)
	 *	 bool compLength(const Song& song1, const Song& song2)
	 *	 bool compTitle(const Song& song1, const Song& song2)
	 *	 std::ostream& operator<<(std::ostream& out, const Song& theSong)
	 */
	bool compAlbum(const Song& song1, const Song& song2);
	bool compLength(const Song& song1, const Song& song2);
	bool compTitle(const Song& song1, const Song& song2);
	std::ostream& operator<<(std::ostream& out, const Song& theSong);
}
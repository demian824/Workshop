/*
	Student Name:	Wonchul Choi
	Student Nubmer:	118362201
	Student ID:	    wchoi28
	Student e-mail: wchoi28@myseneca.ca
	Course:         OOP345
	Workshop:	    Week7
*/
/************************************
	* File Name:				SongCollection.cpp
	* Included Header/Library
	* algorithm
	* fstream
	* iostream
	* iomanip
	* SongCollection.h
	* namespace:				sdds
	************************************/
#include <algorithm>
#include <fstream>
#include <iostream>
#include <cstring>
#include <iomanip>

#include"SongCollection.h"

namespace sdds {
	using namespace std;
	/************************************
	* Constructor Name:		SongCollection(const char* filename)
	* Discription:			default constructor
	************************************/
	SongCollection::SongCollection(const char* filename) {
		size_t count = 0;
		std::string inputString;
		std::ifstream file(filename);
		if (!file)
		{
			std::cerr << "ERROR: Cannot open file [" << filename << "].\n";
			exit(1);
		}
		while (file) { 
			if(std::getline(file, inputString))
				count++; 
		}
		file.clear();
		file.seekg(0, std::ios_base::beg);
		m_songData.resize(count);
		size_t index = 0;
		while (index != count)
		{			
			std::getline(file,inputString);

			m_songData[index].m_title = inputString.substr(0, 25);
			removeSpace(m_songData[index].m_title);
			m_songData[index].m_artist = inputString.substr(25, 25);
			removeSpace(m_songData[index].m_artist);
			m_songData[index].m_album = inputString.substr(50, 25);
			removeSpace(m_songData[index].m_album);
			m_songData[index].m_year = inputString.substr(75, 5);
			removeSpace(m_songData[index].m_year);
						
			m_songData[index].m_length = stoi(inputString.substr(80, 5));
			m_songData[index].m_price = stod(inputString.substr(85));
			index++;
		}
		file.close();
	}
	/************************************
	* Function prototype:		void removeSpace(string& str)
	* Function Name:			removeSpace
	* Function type:			void
	* Function Parameter:		out
	* Parameter type:			std::string&
	* Discription:				remove space in the string
	************************************/
	void SongCollection::removeSpace(string& str) {
		size_t startNum = 0;
		for (size_t i = 0; i < str.length(); i++) {
			if (str[i] != 32) {
				startNum = i;
				break;
			}
		}
		bool noSpace = false;
		size_t index = str.length() - 1;
		while (!noSpace) {
			if (str[index] != 32) noSpace = true;
			else {
				str.pop_back();
				if (index == 0) noSpace = true;
				index--;
			}
		}
		str = str.substr(startNum);
	}
	/************************************
	* Function prototype:		void sort(const char* str)
	* Function Name:			sort
	* Function type:			void
	* Function Parameter:		str
	* Parameter type:			const char*
	* Discription:				sort data follow by str
	************************************/
	void SongCollection::sort(const char* str) {
		char searchFlag = 'z';
		if (strcmp(str , "title") == 0)
			searchFlag = 't';
		else if (strcmp(str, "length") == 0)
			searchFlag = 'l';
		else if (strcmp(str, "album") == 0)
			searchFlag = 'a';
		
		switch (searchFlag)
		{
		case 'a':
			std::sort(m_songData.begin(), m_songData.end(), compAlbum);
			break;
		case 'l':
			std::sort(m_songData.begin(), m_songData.end(), compLength);
			break;
		case 't':
			std::sort(m_songData.begin(), m_songData.end(), compTitle);
			break;
		default:
			break;
		}
	}
	/************************************
	* Function prototype:		void cleanAlbum()
	* Function Name:			cleanAlbum
	* Function type:			void
	* Discription:				delete string '[NONE]' in the data
	************************************/
	void SongCollection::cleanAlbum() {
		size_t index = 0;
		for_each(m_songData.begin(), m_songData.end(), [&](const Song& s)->auto {
			if (s.m_album == "[None]")
				m_songData[index].m_album.erase();
			index++;
		});
	}
	/************************************
	* Function prototype:		bool inCollection(const char* str)
	* Function Name:			inCollection
	* Function type:			bool
	* Function Parameter:		str
	* Parameter type:			const char*
	* Discription:				search str in the data 'm_songData'
	************************************/
	bool SongCollection::inCollection(const char* str) const {
		bool isfound = false;
		for_each(m_songData.begin(), m_songData.end(), [&](const Song& s)->auto {
			if (str == s.m_artist)
				isfound = true;
		});
		return isfound;
	}
	/************************************
	* Function prototype:		std::list<Song> getSongsForArtist(const char* str) const
	* Function Name:			getSongsForArtist
	* Function type:			std::list<Song>
	* Function Parameter:		str
	* Parameter type:			const char*
	* Discription:				get data of singer name 'str' from m_songData
	************************************/
	std::list<Song> SongCollection::getSongsForArtist(const char* str) const {
		list<Song> copy;
		size_t songCount = 0;
		for_each(m_songData.begin(), m_songData.end(), [&](const Song& s)->auto {
			if (str == s.m_artist)
				songCount++;
		});
		for_each(m_songData.begin(), m_songData.end(), [&](const Song& s)->auto {
			if (str == s.m_artist)
				copy.push_back(s);
		});
		copy.resize(songCount);
		return copy;
	}
	/************************************
	* Function prototype:		void display(std::ostream& out) const
	* Function Name:			display
	* Function type:			void
	* Function Parameter:		out
	* Parameter type:			std::ostream&
	* Discription:				print the m_songData
	************************************/
	void SongCollection::display(std::ostream& out) const {		
		size_t totalLength = 0;
		for_each(m_songData.begin(), m_songData.end(), [&](const Song& s)->auto {
			out << s << std::endl; 
			totalLength += s.m_length;
		});
		out.setf(std::ios::right);
		out << std::setw(89) << std::setfill('-') << '\n' << std::setfill(' ');
		out << "|" << setw(78) << "Total Listening Time: " << (totalLength / 60) / 60 <<":"<< (totalLength / 60) % 60 <<":" << totalLength % 60 << " |" << std::endl;
		out.unsetf(std::ios::right);
	}	
	/************************************
	* Function prototype:		std::ostream& operator << (std::ostream& out, const Song& theSong)
	* Function Name:			operator <<
	* Function type:			std::ostream&
	* Function Parameter:		out, theSong
	* Parameter type:			std::ostream&, const Song&
	* Discription:				print data follow by format
	************************************/
	std::ostream& operator << (std::ostream& out, const Song& theSong) {
		if (!theSong.m_artist.empty()) {
			out.unsetf(std::ios::right);
			out.setf(std::ios::left);
			out << "| " << std::setw(20) << theSong.m_title << " | ";
			out << std::setw(15) << theSong.m_artist << " | ";
			out << std::setw(20) << theSong.m_album << " | ";
			out.unsetf(std::ios::left);
			out.setf(std::ios::right);
			out << std::setw(6) << theSong.m_year << " | ";
			out << (theSong.m_length / 60) << ":";
			out.fill('0');
			out << setw(2) << (theSong.m_length % 60) << " | ";
			out.fill(' ');
			out << std::setw(4) << theSong.m_price << " |" ;
			out.unsetf(std::ios::right);
		}
		return out;
	}
	/************************************
	* Function prototype:		bool compAlbum(const Song& song1, const Song& song2)
	* Function Name:			compAlbum
	* Function type:			bool
	* Function Parameter:		song1, song2
	* Parameter type:			const Song&, const Song&
	* Discription:				compare two different ablums from different song data for sorting
	************************************/
	bool compAlbum(const Song& song1, const Song& song2) {
		return song1.m_album < song2.m_album;
	}
	/************************************
	* Function prototype:		bool compLength(const Song& song1, const Song& song2)
	* Function Name:			compLength
	* Function type:			bool
	* Function Parameter:		song1, song2
	* Parameter type:			const Song&, const Song&
	* Discription:				compare two different lengths from different song data for sorting
	************************************/
	bool compLength(const Song& song1, const Song& song2) {
		return song1.m_length < song2.m_length;
	}
	/************************************
	* Function prototype:		bool compTitle(const Song& song1, const Song& song2)
	* Function Name:			compTitle
	* Function type:			bool
	* Function Parameter:		song1, song2
	* Parameter type:			const Song&, const Song&
	* Discription:				compare two different titles from different song data for sorting
	************************************/
	bool compTitle(const Song& song1, const Song& song2) {
		return song1.m_title < song2.m_title;
	}
}
#pragma once

#include <string>



class Painting {


private:

	std::string title;

	std::string artist;

	int year;


public:

	Painting(const std::string& input_title, const std::string& input_artist, const int& input_year);

	std::string getTitle() const { return this->title; }

	std::string getArtist() const { return this->artist; }

	int getYear() const { return this->year; }
	

};


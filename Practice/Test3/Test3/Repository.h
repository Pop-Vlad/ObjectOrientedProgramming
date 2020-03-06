#pragma once

#include <vector>
#include <fstream>
#include <sstream>

#include "Model.h"


class Repository {

private:

	std::string file_name;
	std::vector<TimeInterval> elements;

	void load();

public:

	Repository(std::string file_name);

	std::vector<TimeInterval> getElements() const { return this->elements; }

	std::vector<TimeInterval> filterElements(int max_precipitation) const;

	//Function that comptes the total time for a weather description
	//Arguments: (string) description
	//Returns: (int) the time in hours for wich the weather condition holds
	int getTimeForWeather(std::string description) const;


};
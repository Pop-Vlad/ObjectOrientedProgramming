#pragma once

#include "Model.h"

#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>



class Repository {

private:

	std::vector<Car> elements;

	std::string file;

	void load();


public:

	Repository(std::string file_name);

	std::vector<Car> getElements() const;

	int getCarCount(std::string manufacturer);


};
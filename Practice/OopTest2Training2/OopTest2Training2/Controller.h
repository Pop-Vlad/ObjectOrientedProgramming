#pragma once

#include "Pod.h"

#include <vector>



class Controller {


private:

	std::vector<Pod> pods;

	Engine* createEngine(const std::string& engineType, const std::string& fuelType, const int& autonomy = 0);


public:

	Controller() { this->pods = std::vector<Pod>{}; }

	void addCar(const std::string& engineType, const std::string& fuelType, const int& autonomy = 0);

	std::vector<Pod> getAllCars() { return this->pods; }

	std::vector<Pod> getCarsWithMaxPrice(const double& max_price);

	void writeToFile(const std::string& filename, const int& max_cost);
	

};


#pragma once

#include <string>

class Engine {


protected:

	std::string fuelType;

	double basePrice;


public:

	Engine() {};

	virtual double getPrice() = 0;

	virtual std::string toString() = 0;

	
};


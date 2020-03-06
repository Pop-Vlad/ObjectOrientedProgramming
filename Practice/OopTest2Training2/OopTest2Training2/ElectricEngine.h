#pragma once

#include "Engine.h"

class ElectricEngine : public Engine {

private:

	int autonomy;

public:

	ElectricEngine(const std::string& input_fuel_type, const int& input_autonomy) {
		this->fuelType = input_fuel_type;
		this->basePrice = 3000;
		this->autonomy = input_autonomy;
	}
	
	double getPrice() override {
		return this->basePrice + 0.01 * this->autonomy;
	}

	std::string toString() override {
		std::string string_to_return = "Electric engine - Fuel: " + this->fuelType + " ,Price: " + std::to_string(this->basePrice) + " ,Autonomy: "
			+ std::to_string(this->autonomy);
		return string_to_return;
	}
	
};


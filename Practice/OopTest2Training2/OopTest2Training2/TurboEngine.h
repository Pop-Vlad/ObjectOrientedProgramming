#pragma once

#include "Engine.h"

class TurboEngine : public Engine {


public:

	TurboEngine(const std::string& input_fuel_type) {
		this->fuelType = input_fuel_type;
		this->basePrice = 3000;
	}
	
	double getPrice() override {
		double cost = this->basePrice;
		if (this->fuelType == "turroline") {
			cost += 0.01 * 100;
			return cost;
		}
		if (this->fuelType == "stynium") {
			cost += 0.01 * 150;
			return cost;
		}
	}

	std::string toString() override {
		std::string string_to_return = "Turbo engine - Fuel: " + this->fuelType + " ,Price: " + std::to_string(this->basePrice);
		return string_to_return;
	}
};


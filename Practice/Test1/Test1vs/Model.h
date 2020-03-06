#pragma once

#include <string>


class Car {

public:

	std::string manufacturer;
	std::string model;
	int year;
	std::string colour;

	Car(std::string input_manufacturer, std::string input_model, int input_year, std::string input_colour) :
		manufacturer(input_manufacturer), model(input_model), year(input_year), colour(input_colour) {};

	std::string toString() { return this->manufacturer + " " + this->model + " " + std::to_string(this->year) + " " + this->colour; }


};
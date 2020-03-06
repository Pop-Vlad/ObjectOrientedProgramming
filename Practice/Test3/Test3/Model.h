#pragma once

#include <string>


class TimeInterval {

public:

	int start;
	int end;
	int temperature;
	int precipitation;
	std::string description;


public:

	TimeInterval(int init_start, int init_end, int init_temperature, int init_precipitation, std::string init_description) :
		start(init_start), end(init_end), temperature(init_temperature), precipitation(init_precipitation), description(init_description) {}

	std::string toString() const {
		return std::to_string(this->start) + "->" + std::to_string(this->end) + "  " + std::to_string(this->temperature) + "*  " +
			std::to_string(this->precipitation) + "%  " + description;
	}


};
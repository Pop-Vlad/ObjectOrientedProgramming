#pragma once

#include <string>



class Task {

public:

	std::string description;

	int duration;

	int priority;

	Task(std::string init_description, int init_duration, int init_priotity) :
		description(init_description), duration(init_duration), priority(init_priotity) {}

	std::string toString() const { return this->description + " " + std::to_string(this->duration) + " " + std::to_string(this->priority); }


};
#pragma once

#include <string>
#include <vector>



class Disorder {

public:

	std::string category;
	std::string name;
	std::vector<std::string> symptoms;

	Disorder(std::string init_category, std::string init_name, std::vector<std::string> init_symptoms) : category(init_category),
		name(init_name), symptoms(init_symptoms) {}

	std::string toString() const {
		std::string str{};
		str += this->category + " " + this->name;
		for (int i = 0; i < this->symptoms.size(); i++) {
			str += " " + this->symptoms[i];
		}
		return str;
	}


};
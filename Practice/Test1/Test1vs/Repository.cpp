#include "Repository.h"



Repository::Repository(std::string file_name) {
	this->file = file_name;
	this->elements = std::vector<Car>{};
	this->load();
}


void Repository::load() {
	std::ifstream f;
	f.open(this->file);
	std::string current_line;
	while (std::getline(f, current_line)) {
		std::stringstream current_stream{ current_line };
		std::vector<std::string> attributes;
		std::string attribute;
		for (int i = 0; i < 4; i++) {
			std::getline(current_stream, attribute, '|');
			attributes.push_back(attribute);
		}
		Car new_car{ attributes[0], attributes[1], std::stoi(attributes[2]), attributes[3] };
		this->elements.push_back(new_car);
	}

}


std::vector<Car> Repository::getElements() const {
	return this->elements;
}


int Repository::getCarCount(std::string manufacturer) {
	int count = 0;
	for (Car current_car : this->elements) {
		if (current_car.manufacturer == manufacturer)
			count++;
	}
	return count;
}
#pragma once

#include "Repository.h"


Repository::Repository(std::string file_name) {
	this->file_name = file_name;
	this->load();
}


void Repository::load() {
	std::ifstream f;
	f.open(this->file_name);
	std::string line;
	while (std::getline(f, line)) {
		std::stringstream line_stream{ line };
		std::vector<std::string> attributes;
		std::string current;
		for (int i = 0; i < 5; i++) {
			std::getline(line_stream, current, ';');
			attributes.push_back(current);
		}
		TimeInterval new_time_intrval{ std::stoi(attributes[0]), std::stoi(attributes[1]), std::stoi(attributes[2]), std::stoi(attributes[3]),
			attributes[4] };
		this->elements.push_back(new_time_intrval);
	}
}


std::vector<TimeInterval> Repository::filterElements(int max_precipitation) const {
	std::vector<TimeInterval> results;
	for (TimeInterval current : this->elements)
		if (current.precipitation <= max_precipitation)
			results.push_back(current);
	return results;
}


int Repository::getTimeForWeather(std::string description) const {
	int count = 0;
	for (TimeInterval current : this->elements)
		if (current.description == description)
			count += current.end - current.start;
	return count;
}
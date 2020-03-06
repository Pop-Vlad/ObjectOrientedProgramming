#include "Repository.h"


Repository::Repository(std::string file_name) {
	this->file = file_name;
	this->load();
}


void Repository::load() {
	std::ifstream f;
	f.open(this->file);
	std::string line;
	while (std::getline(f, line)) {
		std::stringstream sstream{ line };
		std::vector<std::string> attributes{};
		std::string current;
		for (int i = 0; i < 3; i++) {
			std::getline(sstream, current, '|');
			attributes.push_back(current);
		}
		Task new_task{ attributes[0], std::stoi(attributes[1]), std::stoi(attributes[2]) };
		this->elements.push_back(new_task);
	}
}


std::vector<Task> Repository::getElementsWithPriority(int priority) const {
	if (priority == 0)
		return this->elements;
	std::vector<Task> results;
	for (Task current : this->elements)
		if (current.priority == priority)
			results.push_back(current);
	return results;
}
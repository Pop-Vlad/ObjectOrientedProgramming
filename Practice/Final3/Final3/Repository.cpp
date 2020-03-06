#include "Repository.h"


Repository::Repository(std::string programmers, std::string sources) : programmers_file(programmers), sources_file(sources) {
	this->load();
};


void Repository::load() {
	std::ifstream f{ this->programmers_file };
	std::string line;
	while (std::getline(f, line)) {
		std::stringstream sstream{ line };
		std::vector<std::string> components;
		std::string current;
		while (std::getline(sstream, current, ' '))
			components.push_back(current);
		Programmer new_programmer{ components[0], std::stoi(components[1]), std::stoi(components[2]) };
		this->programmers.push_back(new_programmer);
	}

	std::ifstream g{ this->sources_file };
	while (std::getline(g, line)) {
		std::stringstream sstream{ line };
		std::vector<std::string> components;
		std::string current;
		while (std::getline(sstream, current, ' '))
			components.push_back(current);
		if (components.size() == 3) {
			SourceFile new_source_file{ components[0], components[1], components[2], "" };
			this->files.push_back(new_source_file);
		}
		else {
			SourceFile new_source_file{ components[0], components[1], components[2], components[3] };
			this->files.push_back(new_source_file);
		}
	}
}


void Repository::save() {

}

int Repository::getRevised(const std::string& name) {
	for(auto current: this->programmers)
		if (current.getName() == name) {
			return current.getRevisedFiles();
		}
	return 0;
}

int Repository::getTotal(const std::string& name) {
	for (auto current : this->programmers)
		if (current.getName() == name) {
			return current.getTotalFiles();
		}
	return 0;
}

void Repository::reviseFile(std::string file, std::string programmer) {
	for (SourceFile& current : this->files) {
		if (current.getName() == file) {
			current.setReviewer(programmer);
			break;
		}
	}
	for (Programmer& current : this->programmers) {
		if (current.getName() == programmer) {
			current.setRevisedFiles(current.getRevisedFiles() + 1);
			break;
		}
	}
}
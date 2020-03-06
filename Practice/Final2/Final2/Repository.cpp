#include "Repository.h"


void Repository::load() {
	std::ifstream f{ this->p_file };
	std::string line;
	while (std::getline(f, line)) {
		std::stringstream line_stream{ line };
		std::vector<std::string> components;
		std::string current;
		while (std::getline(line_stream, current, ' '))
			components.push_back(current);
		Participant new_participant{ components[0], std::stoi(components[1]) };
		this->participants.push_back(new_participant);
	}
	f.close();

	std::ifstream g{ this->q_file };
	while (std::getline(g, line)) {
		std::stringstream line_stream{ line };
		std::vector<std::string> components;
		std::string current;
		while (std::getline(line_stream, current, ' '))
			components.push_back(current);
		Question new_question{ std::stoi(components[0]), components[1], components[2], std::stoi(components[3]) };
		this->questions.push_back(new_question);
	}
	g.close();
}


void Repository::save() {
	std::ofstream f{ this->q_file };
	for (auto q : this->questions) {
		f << q.toString() << "\n";
	}
}


void Repository::add(Question new_q) {
	for (auto q : this->questions) {
		if (q.getId() == new_q.getId())
			throw std::exception{ "Id already taken" };
	}
	this->questions.push_back(new_q);
}
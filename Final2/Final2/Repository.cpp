#include "Repository.h"


void Repository::load() {
	std::ifstream f{ this->writersFile };
	std::string line;
	while (std::getline(f, line)) {
		std::stringstream sstream{ line };
		std::string current;
		std::vector<std::string> components;
		while (std::getline(sstream, current, ' '))
			components.push_back(current);
		Writer new_writer{ components[0], components[1] };
		this->writers.push_back(new_writer);
	}
	f.close();

	std::ifstream g{ this->ideasFile };
	while (std::getline(g, line)) {
		std::stringstream sstream{ line };
		std::string current;
		std::vector<std::string> components;
		while (std::getline(sstream, current, ' '))
			components.push_back(current);
		Idea new_idea{ components[0], components[1], components[2], std::stoi(components[3]) };
		this->ideas.push_back(new_idea);
	}
	g.close();
}

void Repository::addIdea(Idea new_idea) {
	for (auto idea : this->ideas) {
		if (idea.getDescription() == new_idea.getDescription() && idea.getAct() == new_idea.getAct())
			throw std::exception{ "Idea already exists" };
	}
	this->ideas.push_back(new_idea);
}

void Repository::updateStatus(Idea idea_to_update, std::string status) {
	for (Idea& idea : this->ideas) {
		if (idea.getDescription() == idea_to_update.getDescription() && idea.getAct() == idea_to_update.getAct()) {
			idea.setStatus(status);
			break;
		}
	}
}
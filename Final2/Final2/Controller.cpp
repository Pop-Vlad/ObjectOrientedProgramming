#include "Controller.h"

void Controller::addIdea(std::string writer, std::string description, int act) {
	Idea new_idea = Idea{ description, "proposed", writer, act };
	this->repository->addIdea(new_idea);
	this->notify();
}

void Controller::savePlot(std::string fileName) {
	std::vector<Idea> allIdeas = this->repository->getIdeas();
	std::vector<Idea> filtered;
	auto it = std::copy_if(allIdeas.begin(), allIdeas.end(), std::back_inserter(filtered), 
		[](Idea current) {return current.getStatus() == "accepted"; });
	std::vector<Idea> act1;
	it = std::copy_if(filtered.begin(), filtered.end(), std::back_inserter(act1),
		[](Idea current) {return current.getAct() == 1; });
	std::vector<Idea> act2;
	it = std::copy_if(filtered.begin(), filtered.end(), std::back_inserter(act2),
		[](Idea current) {return current.getAct() == 2; });
	std::vector<Idea> act3;
	it = std::copy_if(filtered.begin(), filtered.end(), std::back_inserter(act3),
		[](Idea current) {return current.getAct() == 3; });

	std::ofstream f{ fileName };
	f << "Act1: \n";
	for (auto idea : act1) {
		f << idea.getDescription() << " (" << idea.getCreator() << ")\n";
	}
	f << "Act2: \n";
	for (auto idea : act2) {
		f << idea.getDescription() << " (" << idea.getCreator() << ")\n";
	}
	f << "Act3: \n";
	for (auto idea : act3) {
		f << idea.getDescription() << " (" << idea.getCreator() << ")\n";
	}

	f.close();
}

void Controller::revise(Idea idea_to_revise) {
	this->repository->updateStatus(idea_to_revise, "accepted");
	this->notify();
}

bool Controller::isSenior(std::string name) {
	std::vector<Writer> writers = this->repository->getWriters();
	for (auto writer : writers) {
		if (writer.getName() == name) {
			return writer.getExpertise() == "Senior";
		}
	}
	return false;
}
#pragma once

#include "Repository.h"
#include "Subject.h"

#include <algorithm>


class Controller : public Subject {

private:

	Repository* repository;

public:

	Controller(Repository* repository) { this->repository = repository; }

	std::vector<Writer> getWriters() { return this->repository->getWriters(); }
	std::vector<Idea> getIdeas() { return this->repository->getIdeas(); }

	void addIdea(std::string writer, std::string description, int act);

	void savePlot(std::string fileName);

	void revise(Idea idea_to_revise);

	bool isSenior(std::string name);
	
};


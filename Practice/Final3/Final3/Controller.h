#pragma once

#include "Repository.h"
#include "Subject.h"


class Controller : public Subject {

private:

	Repository* repository;

public:

	Controller(Repository* init_repo) : repository(init_repo) {}

	std::vector<Programmer> getProgrammers() { return this->repository->getAllProgrammers(); }
	std::vector<SourceFile> getFiles() { return this->repository->getAllFiles(); }

	int getRevised(const std::string& name) { return this->repository->getRevised(name); }
	int getRemainig(const std::string& name) { return this->repository->getTotal(name) - this->repository->getRevised(name); }

	void revise(std::string file, std::string programmer) { this->repository->reviseFile(file, programmer); this->notify(); };

};

